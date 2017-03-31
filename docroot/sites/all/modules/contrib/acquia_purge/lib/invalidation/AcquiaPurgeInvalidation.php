<?php

/**
 * Provides an invalidation object.
 *
 * Invalidations are small value objects that describe an individual path from
 * the Acquia Purge queue, to be invalidated for the given scheme and domain
 * name. Executors are responsible for calling ::setStatus(), so that at the end
 * of processing, ::getStatus() evaluates whether the invalidation succeeded
 * across all executor engines. This means that a failed CloudEdge purge, would
 * render the entire path as failed so that it goes back into the queue.
 */
class AcquiaPurgeInvalidation implements AcquiaPurgeInvalidationInterface {
  use AcquiaPurgeQueueStatusTrait {
    setStatusContext as setStatusContextPrivate;
  }

  /**
   * Drupal's base path (or the one Acquia Purge is told to clear).
   *
   * @var string
   */
  protected $base_path;

  /**
   * String suffix to the ::setStatusContext() context to enable setting
   * multiple statuses within a single executor's ::invalidate() call for a
   * single invalidation object.
   *
   * @var string
   */
  protected $contextSuffix = '';

  /**
   * The domain name to clear the path on, e.g. "foo.com" or "bar.baz".
   *
   * @var string
   */
  protected $domain;

  /**
   * The requested scheme to be invalidated: 'http' or 'https'.
   *
   * @var string
   */
  protected $scheme;

  /**
   * The queue item to which this invalidation is associated.
   *
   * @var AcquiaPurgeQueueItemInterface
   */
  protected $queue_item;

  /**
   * {@inheritdoc}
   */
  public function __construct($scheme, $domain, $base_path, AcquiaPurgeQueueItemInterface $queue_item) {
    $this->queue_item = $queue_item;
    $this->domain = $domain;
    $this->scheme = $scheme;
    $this->base_path = $base_path;
  }

  /**
   * {@inheritdoc}
   */
  public function getScheme($fqn = FALSE) {
    if ($fqn) {
      return $this->scheme . '://';
    }
    return $this->scheme;
  }

  /**
   * {@inheritdoc}
   */
  public function getDomain() {
    return $this->domain;
  }

  /**
   * Retrieve the context value set on the queue item, adds the suffix.
   *
   * @return string|null
   */
  protected function getParentContext() {
    if (is_string($this->context) && strlen($this->contextSuffix)) {
      return $this->context . '_' . $this->contextSuffix;
    }
    return $this->context;
  }

  /**
   * {@inheritdoc}
   */
  public function getPath() {
    return $this->base_path . $this->queue_item->getPath();
  }

  /**
   * {@inheritdoc}
   *
   * Route any calls to the queue item's function so that a single queue item
   * holds the overal statuses for all domain and scheme-varied copies of a
   * single HTTP path.
   */
  public function getStatus() {
    $this->queue_item->setStatusContext($this->getParentContext());
    return $this->queue_item->getStatus();
  }

  /**
   * {@inheritdoc}
   */
  public function getUri() {
    return $this->getScheme(TRUE) . $this->getDomain() . $this->getPath();
  }

  /**
   * {@inheritdoc}
   */
  public function hasWildcard() {
    return strpos($this->getPath(), '*') !== FALSE;
  }

  /**
   * {@inheritdoc}
   *
   * Set status on the queue item, in the invalidation-specific context.
   */
  public function setStatus($status) {
    $this->queue_item->setStatusContext($this->getParentContext());
    $this->queue_item->setStatus($status);
  }

  /**
   * {@inheritdoc}
   *
   * Since queue items hold multiple invalidations, the context is kept local.
   */
  public function setStatusContext($id) {
    if (is_null($id)) {
      $this->setStatusContextPrivate(NULL);
      $this->queue_item->setStatusContext(NULL);
      return;
    }
    $id = $this->scheme . '_' . $this->domain . '_' . $id;
    $this->setStatusContextPrivate($id);
  }

  /**
   * {@inheritdoc}
   */
  public function setStatusContextSuffix($suffix) {
    $this->contextSuffix = $suffix;
  }

}
