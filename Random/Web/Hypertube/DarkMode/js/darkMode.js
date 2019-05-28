const toggleMode = () => {
  document.documentElement.classList.add('transition');
  if (document.querySelector('input[name=theme]').checked) {
    document.documentElement.setAttribute('data-theme', 'dark');
  } else {
    document.documentElement.setAttribute('data-theme', 'light');
  }
  setTimeout(() => {
    document.documentElement.classList.remove('transition');
  }, 500);
};