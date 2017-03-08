Applicant: [appointment:name] [appointment:surname]
Email: [appointment:email]
Phone: [appointment:phone]
Note: [appointment:note]

Request details: [appointment:url]
<?php if ($show_acceptance_url) { ?>

To accept the request: [site:url]/appointment/[appointment:aid]/confirm

To deny the request: [site:url]/appointment/[appointment:aid]/reject (the request will be canceled and will be sent an email to the applicant)
<?php } ?>

To delete the request: [site:url]/appointment/[appointment:aid]/delete (warning, will be asked to confirm cancellation and will not sent anything to the applicant)
