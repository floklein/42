const dvd = document.querySelector('.dvd');
let x = 0;
let y = 0;
let dx = 1;
let dy = 1;

let timeout = setInterval(() => {
  x += dx;
  y += dy;
  if (x + 200 >= window.innerWidth || x <= 0) {
    dx *= -1;
    randomColor(dvd);
  }
  if (y + 140 >= window.innerHeight || y <= 0) {
    dy *= -1;
    randomColor(dvd);
  }
  dvd.style.left = x + 'px';
  dvd.style.top = y + 'px';
}, 10);

const randomColor = (div) => {
  const r = Math.floor(Math.random() * 255);
  const g = Math.floor(Math.random() * 255);
  const b = Math.floor(Math.random() * 255);
  div.style.fill = `rgb(${r}, ${g}, ${b})`
};