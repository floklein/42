<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <title>Instacam</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" type="text/css" media="screen" href="css/index.css">
  <script>
    window.onscroll = function () { scrollFunction() };

    function scrollFunction() {
      if (document.body.scrollTop > 80 || document.documentElement.scrollTop > 80) {
        document.getElementById("navbar").style.padding = "10px 10px";
        document.getElementById("logo").style.fontSize = "30px";
      } else {
        document.getElementById("navbar").style.padding = "40px 10px";
        document.getElementById("logo").style.fontSize = "60px";
      }
    }
  </script>
</head>

<body>

  <div id="navbar">
    <a href="#feed" id="logo" class="left-buttons">Instacam</a>
    <div id="navbar-right">
      <a href="#camera"><img src="/img/camera.png"></a>
      <a href="#feed"><img src="/img/feed.png"></a>
      <a href="#account"><img src="/img/account.png"></a>
    </div>
  </div>
  <div id="feed">
    <div id="feed-box">
      <div id="feed-header">
        <div id="feed-user-pic" style="background-image: url('/resources/profile-pics/0.jpg');">
        </div>
        <div id="feed-user-login">
          <a href="#user"><p>florentklein</p></a>
        </div>
      </div>
      <div id="feed-pic" style="background-image: url('/resources/feed-pics/0.jpg');">
      </div>
    </div>
    <div id="feed-box">
    </div>
    <div id="feed-box">
    </div>
    <div id="feed-box">
    </div>
  </div>
</body>

</html>
