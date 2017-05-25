<?php

namespace Acquia\Hmac\Digest;

use Acquia\Hmac\Request\RequestInterface;
use Acquia\Hmac\RequestSignerInterface;

interface DigestInterface
{
    /**
     * Returns the signature.
     *
     * @param \Acquia\Hmac\RequestSignerInterface $requestSigner
     * @param \Acquia\Hmac\Request\RequestInterface $request
     * @param string $secretKey
     *
     * @return string
     */
    public function get(RequestSignerInterface $requestSigner, RequestInterface $request, $secretKey);
}
