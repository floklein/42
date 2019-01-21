<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" type="text/css" media="screen" href="css/index.css">
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

  <div style="margin-top:210px;padding:15px 15px 2500px;font-size:30px">
    <p><b>This example demonstrates how to shrink a navigation bar when the user starts to scroll the page.</b></p>
    <p>Scroll down this frame to see the effect!</p>
    <p>Scroll to the top to remove the effect.</p>
    <p><b>Note:</b> We have also made the navbar responsive, resize the browser window to see the effect.</p>
    <p>Lorem ipsum dolor dummy text to enable scrolling, sit amet, consectetur adipiscing elit, sed do eiusmod tempor
      incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris
      nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum
      dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia
      deserunt mollit anim id est laborum.</p>
  </div>

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

</body>

</html>