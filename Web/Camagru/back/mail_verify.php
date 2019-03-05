<?php
require '../config/database.php';

$id = $_GET['id'];

$DB_DSN .= ";dbname=" . $DB_NAME;
// Connecting to 'instacam' database
try {
    $pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Searching for email
try {
    $sql = "SELECT users.email, users.name, verify.phrase FROM verify JOIN users ON verify.user_id=users.id
            WHERE users.id=? AND verify.verified=0";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$id]);
    $user = $stmt->fetch();
} catch (PDOEXCEPTION $e) {
    exit($e);
}

if ($user === false) {
    header("Location: ../email.php?error=failure");
    exit();
}

// Link to send
$link = "http://" . $_SERVER['HTTP_HOST'] . "/back/verify.php?id=" . $id . "&phrase=" . $user['phrase'];

// Compatibility
if (!preg_match("/^[a-z0-9._-]+@(hotmail|live|msn).[a-z]{2,4}$/", $user['email'])) {
    $nl = "\r\n";
} else {
    $nl = "\n";
}

// Text and HTML content
$msg_txt = "Votre lien : " . $link;
$msg_html = '<head>
<meta http-equiv="Content-Type" content="text/html">
<meta charset="utf-8">
<meta name="viewport" content="width=device-width">
</head>

<body style="-moz-box-sizing: border-box; -ms-text-size-adjust: 100%; -webkit-box-sizing: border-box; -webkit-text-size-adjust: 100%; box-sizing: border-box; color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 22px; margin: 0; min-width: 100%; padding: 0; text-align: left; width: 100% !important">
<style type="text/css">
  body {
    width: 100% !important;
    min-width: 100%;
    -webkit-text-size-adjust: 100%;
    -ms-text-size-adjust: 100%;
    margin: 0;
    padding: 0;
    -moz-box-sizing: border-box;
    -webkit-box-sizing: border-box;
    box-sizing: border-box;
  }

  .ExternalClass {
    width: 100%;
  }

  .ExternalClass {
    line-height: 100%;
  }

  #backgroundTable {
    margin: 0;
    padding: 0;
    width: 100% !important;
    line-height: 100% !important;
  }

  img {
    outline: none;
    text-decoration: none;
    -ms-interpolation-mode: bicubic;
    width: auto;
    max-width: 100%;
    clear: both;
    display: block;
  }

  body {
    color: #1C232B;
    font-family: Helvetica, Arial, sans-serif;
    font-weight: normal;
    padding: 0;
    margin: 0;
    text-align: left;
    line-height: 1.3;
  }

  body {
    font-size: 16px;
    line-height: 1.3;
  }

  a:hover {
    color: #1f54ed;
  }

  a:active {
    color: #1f54ed;
  }

  a:visited {
    color: #4E78F1;
  }

  h1 a:visited {
    color: #4E78F1;
  }

  h2 a:visited {
    color: #4E78F1;
  }

  h3 a:visited {
    color: #4E78F1;
  }

  h4 a:visited {
    color: #4E78F1;
  }

  h5 a:visited {
    color: #4E78F1;
  }

  h6 a:visited {
    color: #4E78F1;
  }

  table.button:hover table tr td a {
    color: #FFFFFF;
  }

  table.button:active table tr td a {
    color: #FFFFFF;
  }

  table.button table tr td a:visited {
    color: #FFFFFF;
  }

  table.button.tiny:hover table tr td a {
    color: #FFFFFF;
  }

  table.button.tiny:active table tr td a {
    color: #FFFFFF;
  }

  table.button.tiny table tr td a:visited {
    color: #FFFFFF;
  }

  table.button.small:hover table tr td a {
    color: #FFFFFF;
  }

  table.button.small:active table tr td a {
    color: #FFFFFF;
  }

  table.button.small table tr td a:visited {
    color: #FFFFFF;
  }

  table.button.large:hover table tr td a {
    color: #FFFFFF;
  }

  table.button.large:active table tr td a {
    color: #FFFFFF;
  }

  table.button.large table tr td a:visited {
    color: #FFFFFF;
  }

  table.button:hover table td {
    background: #1f54ed;
    color: #FFFFFF;
  }

  table.button:visited table td {
    background: #1f54ed;
    color: #FFFFFF;
  }

  table.button:active table td {
    background: #1f54ed;
    color: #FFFFFF;
  }

  table.button:hover table a {
    border: 0 solid #1f54ed;
  }

  table.button:visited table a {
    border: 0 solid #1f54ed;
  }

  table.button:active table a {
    border: 0 solid #1f54ed;
  }

  table.button.secondary:hover table td {
    background: #fefefe;
    color: #FFFFFF;
  }

  table.button.secondary:hover table a {
    border: 0 solid #fefefe;
  }

  table.button.secondary:hover table td a {
    color: #FFFFFF;
  }

  table.button.secondary:active table td a {
    color: #FFFFFF;
  }

  table.button.secondary table td a:visited {
    color: #FFFFFF;
  }

  table.button.success:hover table td {
    background: #009482;
  }

  table.button.success:hover table a {
    border: 0 solid #009482;
  }

  table.button.alert:hover table td {
    background: #ff6131;
  }

  table.button.alert:hover table a {
    border: 0 solid #ff6131;
  }

  table.button.warning:hover table td {
    background: #fcae1a;
  }

  table.button.warning:hover table a {
    border: 0px solid #fcae1a;
  }

  .thumbnail:hover {
    box-shadow: 0 0 6px 1px rgba(78, 120, 241, 0.5);
  }

  .thumbnail:focus {
    box-shadow: 0 0 6px 1px rgba(78, 120, 241, 0.5);
  }

  body.outlook p {
    display: inline !important;
  }

  body {
    font-weight: normal;
    font-size: 16px;
    line-height: 22px;
  }

  @media only screen and (max-width: 596px) {
    .small-float-center {
      margin: 0 auto !important;
      float: none !important;
      text-align: center !important;
    }
    .small-text-center {
      text-align: center !important;
    }
    .small-text-left {
      text-align: left !important;
    }
    .small-text-right {
      text-align: right !important;
    }
    .hide-for-large {
      display: block !important;
      width: auto !important;
      overflow: visible !important;
      max-height: none !important;
      font-size: inherit !important;
      line-height: inherit !important;
    }
    table.body table.container .hide-for-large {
      display: table !important;
      width: 100% !important;
    }
    table.body table.container .row.hide-for-large {
      display: table !important;
      width: 100% !important;
    }
    table.body table.container .callout-inner.hide-for-large {
      display: table-cell !important;
      width: 100% !important;
    }
    table.body table.container .show-for-large {
      display: none !important;
      width: 0;
      mso-hide: all;
      overflow: hidden;
    }
    table.body img {
      width: auto;
      height: auto;
    }
    table.body center {
      min-width: 0 !important;
    }
    table.body .container {
      width: 95% !important;
    }
    table.body .columns {
      height: auto !important;
      -moz-box-sizing: border-box;
      -webkit-box-sizing: border-box;
      box-sizing: border-box;
      padding-left: 16px !important;
      padding-right: 16px !important;
    }
    table.body .column {
      height: auto !important;
      -moz-box-sizing: border-box;
      -webkit-box-sizing: border-box;
      box-sizing: border-box;
      padding-left: 16px !important;
      padding-right: 16px !important;
    }
    table.body .columns .column {
      padding-left: 0 !important;
      padding-right: 0 !important;
    }
    table.body .columns .columns {
      padding-left: 0 !important;
      padding-right: 0 !important;
    }
    table.body .column .column {
      padding-left: 0 !important;
      padding-right: 0 !important;
    }
    table.body .column .columns {
      padding-left: 0 !important;
      padding-right: 0 !important;
    }
    table.body .collapse .columns {
      padding-left: 0 !important;
      padding-right: 0 !important;
    }
    table.body .collapse .column {
      padding-left: 0 !important;
      padding-right: 0 !important;
    }
    td.small-1 {
      display: inline-block !important;
      width: 8.333333% !important;
    }
    th.small-1 {
      display: inline-block !important;
      width: 8.333333% !important;
    }
    td.small-2 {
      display: inline-block !important;
      width: 16.666666% !important;
    }
    th.small-2 {
      display: inline-block !important;
      width: 16.666666% !important;
    }
    td.small-3 {
      display: inline-block !important;
      width: 25% !important;
    }
    th.small-3 {
      display: inline-block !important;
      width: 25% !important;
    }
    td.small-4 {
      display: inline-block !important;
      width: 33.333333% !important;
    }
    th.small-4 {
      display: inline-block !important;
      width: 33.333333% !important;
    }
    td.small-5 {
      display: inline-block !important;
      width: 41.666666% !important;
    }
    th.small-5 {
      display: inline-block !important;
      width: 41.666666% !important;
    }
    td.small-6 {
      display: inline-block !important;
      width: 50% !important;
    }
    th.small-6 {
      display: inline-block !important;
      width: 50% !important;
    }
    td.small-7 {
      display: inline-block !important;
      width: 58.333333% !important;
    }
    th.small-7 {
      display: inline-block !important;
      width: 58.333333% !important;
    }
    td.small-8 {
      display: inline-block !important;
      width: 66.666666% !important;
    }
    th.small-8 {
      display: inline-block !important;
      width: 66.666666% !important;
    }
    td.small-9 {
      display: inline-block !important;
      width: 75% !important;
    }
    th.small-9 {
      display: inline-block !important;
      width: 75% !important;
    }
    td.small-10 {
      display: inline-block !important;
      width: 83.333333% !important;
    }
    th.small-10 {
      display: inline-block !important;
      width: 83.333333% !important;
    }
    td.small-11 {
      display: inline-block !important;
      width: 91.666666% !important;
    }
    th.small-11 {
      display: inline-block !important;
      width: 91.666666% !important;
    }
    td.small-12 {
      display: inline-block !important;
      width: 100% !important;
    }
    th.small-12 {
      display: inline-block !important;
      width: 100% !important;
    }
    .columns td.small-12 {
      display: block !important;
      width: 100% !important;
    }
    .column td.small-12 {
      display: block !important;
      width: 100% !important;
    }
    .columns th.small-12 {
      display: block !important;
      width: 100% !important;
    }
    .column th.small-12 {
      display: block !important;
      width: 100% !important;
    }
    table.body td.small-offset-1 {
      margin-left: 8.333333% !important;
    }
    table.body th.small-offset-1 {
      margin-left: 8.333333% !important;
    }
    table.body td.small-offset-2 {
      margin-left: 16.666666% !important;
    }
    table.body th.small-offset-2 {
      margin-left: 16.666666% !important;
    }
    table.body td.small-offset-3 {
      margin-left: 25% !important;
    }
    table.body th.small-offset-3 {
      margin-left: 25% !important;
    }
    table.body td.small-offset-4 {
      margin-left: 33.333333% !important;
    }
    table.body th.small-offset-4 {
      margin-left: 33.333333% !important;
    }
    table.body td.small-offset-5 {
      margin-left: 41.666666% !important;
    }
    table.body th.small-offset-5 {
      margin-left: 41.666666% !important;
    }
    table.body td.small-offset-6 {
      margin-left: 50% !important;
    }
    table.body th.small-offset-6 {
      margin-left: 50% !important;
    }
    table.body td.small-offset-7 {
      margin-left: 58.333333% !important;
    }
    table.body th.small-offset-7 {
      margin-left: 58.333333% !important;
    }
    table.body td.small-offset-8 {
      margin-left: 66.666666% !important;
    }
    table.body th.small-offset-8 {
      margin-left: 66.666666% !important;
    }
    table.body td.small-offset-9 {
      margin-left: 75% !important;
    }
    table.body th.small-offset-9 {
      margin-left: 75% !important;
    }
    table.body td.small-offset-10 {
      margin-left: 83.333333% !important;
    }
    table.body th.small-offset-10 {
      margin-left: 83.333333% !important;
    }
    table.body td.small-offset-11 {
      margin-left: 91.666666% !important;
    }
    table.body th.small-offset-11 {
      margin-left: 91.666666% !important;
    }
    table.body table.columns td.expander {
      display: none !important;
    }
    table.body table.columns th.expander {
      display: none !important;
    }
    table.body .right-text-pad {
      padding-left: 10px !important;
    }
    table.body .text-pad-right {
      padding-left: 10px !important;
    }
    table.body .left-text-pad {
      padding-right: 10px !important;
    }
    table.body .text-pad-left {
      padding-right: 10px !important;
    }
    table.menu {
      width: 100% !important;
    }
    table.menu td {
      width: auto !important;
      display: inline-block !important;
    }
    table.menu th {
      width: auto !important;
      display: inline-block !important;
    }
    table.menu.vertical td {
      display: block !important;
    }
    table.menu.vertical th {
      display: block !important;
    }
    table.menu.small-vertical td {
      display: block !important;
    }
    table.menu.small-vertical th {
      display: block !important;
    }
    table.menu[align="center"] {
      width: auto !important;
    }
    table.button.small-expand {
      width: 100% !important;
    }
    table.button.small-expanded {
      width: 100% !important;
    }
    table.button.small-expand table {
      width: 100%;
    }
    table.button.small-expanded table {
      width: 100%;
    }
    table.button.small-expand table a {
      text-align: center !important;
      width: 100% !important;
      padding-left: 0 !important;
      padding-right: 0 !important;
    }
    table.button.small-expanded table a {
      text-align: center !important;
      width: 100% !important;
      padding-left: 0 !important;
      padding-right: 0 !important;
    }
    table.button.small-expand center {
      min-width: 0;
    }
    table.button.small-expanded center {
      min-width: 0;
    }
    table.body .container {
      width: 100% !important;
    }
  }

  @media only screen and (min-width: 732px) {
    table.body table.milkyway-email-card {
      width: 525px !important;
    }
    table.body table.emailer-footer {
      width: 525px !important;
    }
  }

  @media only screen and (max-width: 731px) {
    table.body table.milkyway-email-card {
      width: 320px !important;
    }
    table.body table.emailer-footer {
      width: 320px !important;
    }
  }

  @media only screen and (max-width: 320px) {
    table.body table.milkyway-email-card {
      width: 100% !important;
      border-radius: 0;
      box-sizing: none;
    }
    table.body table.emailer-footer {
      width: 100% !important;
      border-radius: 0;
      box-sizing: none;
    }
  }

  @media only screen and (max-width: 280px) {
    table.body table.milkyway-email-card .milkyway-content {
      width: 100% !important;
    }
  }

  @media (min-width: 596px) {
    .milkyway-header {
      width: 11%;
    }
  }

  @media (max-width: 596px) {
    .milkyway-header {
      width: 50%;
    }
    .emailer-footer .emailer-border-bottom {
      border-bottom: 0.5px solid #E2E5E7;
    }
    .emailer-footer .make-you-smile {
      margin-top: 24px;
    }
    .emailer-footer .make-you-smile .email-tag-line {
      width: 80%;
      position: relative;
      left: 10%;
    }
    .emailer-footer .make-you-smile .universe-address {
      margin-bottom: 10px !important;
    }
    .emailer-footer .make-you-smile .email-tag-line {
      margin-bottom: 10px !important;
    }
    .have-questions-text {
      width: 70%;
    }
    .hide-on-small {
      display: none;
    }
    .product-card-stacked-row .thumbnail-image {
      max-width: 32% !important;
    }
    .product-card-stacked-row .thumbnail-content p {
      width: 64%;
    }
    .welcome-subcontent {
      text-align: left;
      margin: 20px 0 10px;
    }
    .milkyway-title {
      padding: 16px;
    }
    .meta-data {
      text-align: center;
    }
    .label {
      text-align: center;
    }
    .welcome-email .wavey-background-subcontent {
      width: calc(100% - 32px);
    }
  }

  @media (min-width: 597px) {
    .emailer-footer .show-on-mobile {
      display: none;
    }
    .emailer-footer .emailer-border-bottom {
      border-bottom: none;
    }
    .have-questions-text {
      border-bottom: none;
    }
    .hide-on-large {
      display: none;
    }
    .milkyway-title {
      padding: 55px 55px 16px;
    }
  }

  @media only screen and (max-width: 290px) {
    table.container.your-tickets .tickets-container {
      width: 100%;
    }
  }
</style>
<table class="body" data-made-with-foundation="" style="background: #FAFAFA; border-collapse: collapse; border-spacing: 0; color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; height: 100%; line-height: 1.3; margin: 0; padding: 0; text-align: left; vertical-align: top; width: 100%"
  bgcolor="#FAFAFA">
  <tbody>
    <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
      <td class="center" align="center" valign="top" style="-moz-hyphens: auto; -webkit-hyphens: auto; border-collapse: collapse !important; color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; hyphens: auto; line-height: 1.3; margin: 0; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word">
        <center style="min-width: 580px; width: 100%">
          <table class=" spacer  float-center" align="center" style="border-collapse: collapse; border-spacing: 0; float: none; margin: 0 auto; padding: 0; text-align: center; vertical-align: top; width: 100%">
            <tbody>
              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                <td height="20px" style="-moz-hyphens: auto; -webkit-hyphens: auto; border-collapse: collapse !important; color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 20px; font-weight: normal; hyphens: auto; line-height: 20px; margin: 0; mso-line-height-rule: exactly; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word"
                  align="left" valign="top">&nbsp;</td>
              </tr>
            </tbody>
          </table>
          <table class="header-spacer spacer  float-center" align="center" style="border-collapse: collapse; border-spacing: 0; float: none; line-height: 60px; margin: 0 auto; padding: 0; text-align: center; vertical-align: top; width: 100%">
            <tbody>
              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                <td height="16px" style="-moz-hyphens: auto; -webkit-hyphens: auto; border-collapse: collapse !important; color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; hyphens: auto; line-height: 16px; margin: 0; mso-line-height-rule: exactly; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word"
                  align="left" valign="top">&nbsp;</td>
              </tr>
            </tbody>
          </table>
          <div class="milkyway-header float-center" align="center">
            <img src=""
              style="-ms-interpolation-mode: bicubic; clear: both; display: block; max-width: 100%; outline: none; text-decoration: none; width: auto">
          </div>
          <table class="header-spacer-bottom spacer  float-center" align="center" style="border-collapse: collapse; border-spacing: 0; float: none; line-height: 30px; margin: 0 auto; padding: 0; text-align: center; vertical-align: top; width: 100%">
            <tbody>
              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                <td height="16px" style="-moz-hyphens: auto; -webkit-hyphens: auto; border-collapse: collapse !important; color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; hyphens: auto; line-height: 16px; margin: 0; mso-line-height-rule: exactly; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word"
                  align="left" valign="top">&nbsp;</td>
              </tr>
            </tbody>
          </table>

          <table class="milkyway-email-card container float-center" align="center" style="background: #FFFFFF; border-collapse: collapse; border-radius: 6px; border-spacing: 0; box-shadow: 0 1px 8px 0 rgba(28,35,43,0.15); float: none; margin: 0 auto; overflow: hidden; padding: 0; text-align: center; vertical-align: top; width: 580px"
            bgcolor="#FFFFFF">
            <tbody>
              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                <td style="-moz-hyphens: auto; -webkit-hyphens: auto; border-collapse: collapse !important; color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; hyphens: auto; line-height: 1.3; margin: 0; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word"
                  align="left" valign="top">

                  <table class="milkyway-content confirmation-instructions container" align="center" style="background: #FFFFFF; border-collapse: collapse; border-spacing: 0; hyphens: none; margin: auto; max-width: 100%; padding: 0; text-align: inherit; vertical-align: top; width: 280px !important"
                    bgcolor="#FFFFFF">
                    <tbody>
                      <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                        <td style="-moz-hyphens: auto; -webkit-hyphens: auto; border-collapse: collapse !important; color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; hyphens: auto; line-height: 1.3; margin: 0; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word"
                          align="left" valign="top">
                          <table class=" spacer " style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                            <tbody>
                              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                              </tr>
                            </tbody>
                          </table>
                          <table class=" spacer " style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                            <tbody>
                              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                <td height="30px" style="-moz-hyphens: auto; -webkit-hyphens: auto; border-collapse: collapse !important; color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 30px; font-weight: normal; hyphens: auto; line-height: 30px; margin: 0; mso-line-height-rule: exactly; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word"
                                  align="left" valign="top">&nbsp;</td>
                              </tr>
                            </tbody>
                          </table>
                          <table class=" row" style="border-collapse: collapse; border-spacing: 0; display: table; padding: 0; position: relative; text-align: left; vertical-align: top; width: 100%">
                            <tbody>
                              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                <th class="header-padding small-12 large-12 columns first last" style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0 auto; padding: 0; text-align: left; width: 564px" align="left">
                                  <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                                    <tbody>
                                      <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                        <th style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left" align="left">
                                          <h1 class="welcome-header" style="color: inherit; font-family: Helvetica, Arial, sans-serif; font-size: 24px; font-weight: 600; hyphens: none; line-height: 30px; margin: 0 0 24px; padding: 0; text-align: left; width: 100%; word-wrap: normal" align="left">
                                            Bienvenue sur Instacam.
                                          </h1>
                                        </th>
                                        <th class="expander" style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left; visibility: hidden; width: 0" align="left"></th>
                                      </tr>
                                    </tbody>
                                  </table>
                                </th>
                              </tr>
                            </tbody>
                          </table>
                          <table class=" row" style="border-collapse: collapse; border-spacing: 0; display: table; padding: 0; position: relative; text-align: left; vertical-align: top; width: 100%">
                            <tbody>
                              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                <th class="body-content small-12 large-12 columns first last" style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0 auto; padding: 0; text-align: left; width: 564px" align="left">
                                  <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                                    <tbody>
                                      <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                        <th style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left" align="left">
                                          <h2 class="welcome-subcontent" style="color: #6F7881; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: 300; line-height: 22px; margin: 0; padding: 0; text-align: left; width: 100%; word-wrap: normal" align="left">
                                            Bonjour <span style="font-weight: 600">' . htmlspecialchars($user['name']) . '</span>,
                                          </h2>
                                        </th>
                                        <th class="expander" style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left; visibility: hidden; width: 0" align="left"></th>
                                      </tr>
                                    </tbody>
                                  </table>
                                </th>
                              </tr>
                            </tbody>
                          </table>
                          <table class=" row" style="border-collapse: collapse; border-spacing: 0; display: table; padding: 0; position: relative; text-align: left; vertical-align: top; width: 100%">
                            <tbody>
                              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                <th class="body-content-end small-12 large-12 columns first last" style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0 auto; padding: 0; text-align: left; width: 564px" align="left">
                                  <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                                    <tbody>
                                      <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                        <th style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left" align="left">
                                          <h2 class="welcome-subcontent" style="color: #6F7881; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: 300; line-height: 22px; margin: 0; padding: 0; text-align: left; width: 100%; word-wrap: normal" align="left">
                                            Votre compte a bien ete cree. Il ne vous reste plus qu\'a confirmer votre email pour pouvoir vous connecter.
                                          </h2>
                                        </th>
                                        <th class="expander" style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left; visibility: hidden; width: 0" align="left"></th>
                                      </tr>
                                    </tbody>
                                  </table>
                                </th>
                              </tr>
                            </tbody>
                          </table>
                          <table class=" spacer " style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                            <tbody>
                              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                <td height="30px" style="-moz-hyphens: auto; -webkit-hyphens: auto; border-collapse: collapse !important; color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 30px; font-weight: normal; hyphens: auto; line-height: 30px; margin: 0; mso-line-height-rule: exactly; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word"
                                  align="left" valign="top">&nbsp;</td>
                              </tr>
                            </tbody>
                          </table>
                          <table class="milkyway-content row" style="border-collapse: collapse; border-spacing: 0; display: table; hyphens: none; margin: auto; max-width: 100%; padding: 0; position: relative; text-align: left; vertical-align: top; width: 280px !important">
                            <tbody>
                              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                <th class="milkyway-padding small-12 large-12 columns first last" valign="middle" style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0 auto; padding: 0; text-align: left; width: 564px"
                                  align="left">
                                  <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                                    <tbody>
                                      <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                        <th style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left" align="left">
                                          <table class="cta-text primary radius expanded button" style="border-collapse: collapse; border-spacing: 0; font-size: 14px; font-weight: 400; line-height: 0; margin: 0 0 16px; padding: 0; text-align: left; vertical-align: top; width: 100% !important">
                                            <tbody>
                                              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                                <td style="-moz-hyphens: auto; -webkit-hyphens: auto; border-collapse: collapse !important; color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; hyphens: auto; line-height: 1.3; margin: 0; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word"
                                                  align="left" valign="top">
                                                  <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                                                    <tbody>
                                                      <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                                        <td style="-moz-hyphens: auto; -webkit-hyphens: auto; background: #4E78F1; border: 2px none #4e78f1; border-collapse: collapse !important; border-radius: 6px; color: #FFFFFF; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; hyphens: auto; line-height: 1.3; margin: 0; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word"
                                                          align="left" bgcolor="#4E78F1" valign="top">
                                                          <a href="' . $link . '" style="border: 0 solid #4e78f1; border-radius: 6px; color: #FFFFFF; display: inline-block; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: bold; line-height: 1.3; margin: 0; padding: 13px 0; text-align: center; text-decoration: none; width: 100%"
                                                            target="_blank">
                                                            <p class="text-center" style="color: white; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: 300; letter-spacing: 1px; line-height: 1.3; margin: 0; padding: 0; text-align: center" align="center">
                                                              Confirmer mon email
                                                            </p>
                                                          </a>
                                                        </td>
                                                      </tr>
                                                    </tbody>
                                                  </table>
                                                </td>
                                              </tr>
                                            </tbody>
                                          </table>
                                        </th>
                                        <th class="expander" style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left; visibility: hidden; width: 0" align="left"></th>
                                      </tr>
                                    </tbody>
                                  </table>
                                </th>
                              </tr>
                            </tbody>
                          </table>

                          <table class=" spacer " style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                            <tbody>
                              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                <td height="10px" style="-moz-hyphens: auto; -webkit-hyphens: auto; border-collapse: collapse !important; color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 10px; font-weight: normal; hyphens: auto; line-height: 10px; margin: 0; mso-line-height-rule: exactly; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word"
                                  align="left" valign="top">&nbsp;</td>
                              </tr>
                            </tbody>
                          </table>
                        </td>
                      </tr>
                    </tbody>
                  </table>

                </td>
              </tr>
            </tbody>
          </table>
          <table class=" spacer  float-center" align="center" style="border-collapse: collapse; border-spacing: 0; float: none; margin: 0 auto; padding: 0; text-align: center; vertical-align: top; width: 100%">
            <tbody>
              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                <td height="20px" style="-moz-hyphens: auto; -webkit-hyphens: auto; border-collapse: collapse !important; color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 20px; font-weight: normal; hyphens: auto; line-height: 20px; margin: 0; mso-line-height-rule: exactly; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word"
                  align="left" valign="top">&nbsp;</td>
              </tr>
            </tbody>
          </table>
          <table class="emailer-footer container float-center" align="center" style="background-color: transparent !important; border-collapse: collapse; border-spacing: 0; float: none; margin: 0 auto; padding: 0; text-align: center; vertical-align: top; width: 580px"
            bgcolor="transparent">
            <tbody>
              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                <td style="-moz-hyphens: auto; -webkit-hyphens: auto; border-collapse: collapse !important; color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; hyphens: auto; line-height: 1.3; margin: 0; padding: 0; text-align: left; vertical-align: top; word-wrap: break-word"
                  align="left" valign="top">
                  <table class=" row" style="border-collapse: collapse; border-spacing: 0; display: table; padding: 0; position: relative; text-align: left; vertical-align: top; width: 100%">
                    <tbody>
                      <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                        <th class=" small-12 large-4 columns first" style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0 auto; padding: 0 8px 16px 16px; text-align: left; width: 177.3333333333px"
                          align="left">
                          <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                            <tbody>
                              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                <th style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left" align="left">
                                </th>
                                <th class="emailer-border-bottom small-12 large-11 columns first" style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0 auto; padding: 0 0 16px; text-align: left; width: 91.666666%"
                                  align="left">
                                  <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                                    <tbody>
                                      <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                        <th style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left" align="left">
                                          <p class="text-left small-text-center" style="color: #6F7881; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.5; margin: 0; padding: 0; text-align: left" align="left">
                                            <a target="_blank" href="' . 'http://' . $_SERVER['HTTP_HOST'] . '/signin.php' . '" style="color: #4E78F1; font-family: Helvetica, Arial, sans-serif; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left; text-decoration: none">Connexion</a>
                                          </p>
                                        </th>
                                      </tr>
                                    </tbody>
                                  </table>
                                </th>
                                <th class="show-for-large small-12 large-1 columns last" style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0 auto; padding: 0 0 16px; text-align: left; width: 8.333333%" align="left">
                                  <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                                    <tbody>
                                      <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                        <th style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left" align="left">
                                          <p class="first-bullet" style="color: #6F7881; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; left: 6px; line-height: 1.5; margin: 0; padding: 0; position: relative; text-align: left" align="left">
                                            -
                                          </p>
                                        </th>
                                      </tr>
                                    </tbody>
                                  </table>
                                </th>
                              </tr>
                            </tbody>
                          </table>
                        </th>
                        <th class=" small-12 large-4 columns" style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0 auto; padding: 0 8px 16px; text-align: left; width: 177.3333333333px" align="left">
                          <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                            <tbody>
                              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                <th style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left" align="left">
                                </th>
                                <th class="emailer-border-bottom small-12 large-11 columns first" style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0 auto; padding: 0 0 16px; text-align: left; width: 91.666666%"
                                  align="left">
                                  <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                                    <tbody>
                                      <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                        <th style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left" align="left">
                                          <p class="text-center small-text-center" style="color: #6F7881; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.5; margin: 0; padding: 0; text-align: center" align="center">
                                            <a target="_blank" href="' . 'http://' . $_SERVER['HTTP_HOST'] . '" style="color: #4E78F1; font-family: Helvetica, Arial, sans-serif; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left; text-decoration: none">Instacam</a>
                                          </p>
                                        </th>
                                      </tr>
                                    </tbody>
                                  </table>
                                </th>
                                <th class="show-for-large small-12 large-1 columns last" style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0 auto; padding: 0 0 16px; text-align: left; width: 8.333333%" align="left">
                                  <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                                    <tbody>
                                      <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                        <th style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left" align="left">
                                          <p class="last-bullet" style="color: #6F7881; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; left: 22px; line-height: 1.5; margin: 0; padding: 0; position: relative; text-align: left" align="left">
                                            -
                                          </p>
                                        </th>
                                      </tr>
                                    </tbody>
                                  </table>
                                </th>
                              </tr>
                            </tbody>
                          </table>
                        </th>
                        <th class="emailer-border-bottom small-12 large-4 columns last" style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0 auto; padding: 0 16px 16px 8px; text-align: left; width: 177.3333333333px"
                          align="left">
                          <table style="border-collapse: collapse; border-spacing: 0; padding: 0; text-align: left; vertical-align: top; width: 100%">
                            <tbody>
                              <tr style="padding: 0; text-align: left; vertical-align: top" align="left">
                                <th style="color: #1C232B; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left" align="left">
                                  <p class="text-center small-text-center" style="color: #6F7881; font-family: Helvetica, Arial, sans-serif; font-size: 16px; font-weight: normal; line-height: 1.5; margin: 0; padding: 0; text-align: center" align="center">
                                    <a target="_blank" href="https://fkle.in" style="color: #4E78F1; font-family: Helvetica, Arial, sans-serif; font-weight: normal; line-height: 1.3; margin: 0; padding: 0; text-align: left; text-decoration: none">A propos</a>
                                  </p>
                                </th>
                              </tr>
                            </tbody>
                          </table>
                        </th>
                      </tr>
                    </tbody>
                  </table>
                </td>
              </tr>
            </tbody>
          </table>
        </center>
      </td>
    </tr>
  </tbody>
</table>

</body>';

// Creating boundary
$boundary = "-----=" . md5(rand());

// Subject
$subject = "Verifiez votre adresse email";

// Header
$header = "From: \"Instacam\"<instacam@fkle.in>" . $nl;
$header .= "MIME-Version: 1.0" . $nl;
$header .= "Content-Type: multipart/alternative;" . $nl . " boundary=\"$boundary\"" . $nl;

// Message
$msg = $nl . "--" . $boundary . $nl;
// Text part
$msg .= "Content-Type: text/plain; charset=\"ISO-8859-1\"" . $nl;
$msg .= "Content-Transfer-Encoding: 8bit" . $nl;
$msg .= $nl . $msg_txt . $nl;
$msg .= $nl . "--" . $boundary . $nl;
// HTML part
$msg .= "Content-Type: text/html; charset=\"ISO-8859-1\"" . $nl;
$msg .= "Content-Transfer-Encoding: 8bit" . $nl;
$msg .= $nl . $msg_html . $nl;
$msg .= $nl . "--" . $boundary . "--" . $nl;
$msg .= $nl . "--" . $boundary . "--" . $nl;

if (mail($user['email'], $subject, $msg, $header)) {
    header("Location: ../email.php?verify=success");
} else {
    header("Location: ../email.php?verify=failure");
}
