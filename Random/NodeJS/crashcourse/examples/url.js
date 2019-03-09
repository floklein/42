const url = require('url');

const myUrl = new URL('https://fkle.in:8080/index.html?id=1&status=200');

// Serialized URL
console.log(myUrl.href);

// Host
console.log(myUrl.host);
console.log(myUrl.hostname)

// Pathname
console.log(myUrl.pathname);

// Query
console.log(myUrl.search);
console.log(myUrl.searchParams);
myUrl.searchParams.append('search', 'test');
console.log(myUrl.searchParams);
myUrl.searchParams.forEach((value, name) => {
  console.log(`${name}: ${value}`);
})