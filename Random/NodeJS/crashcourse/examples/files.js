const fs = require('fs');
const path = require('path');

// Create directory
fs.mkdir(path.join(__dirname, '/test'), {}, err => {
  if (err) throw err;
  console.log('Folder created.');
});

// Create & write to file
fs.writeFile(path.join(__dirname, '/test', 'hello.txt'), 'Hello World!', err => {
  if (err) throw err;
  console.log('File created.');
  // Append file
  fs.appendFile(path.join(__dirname, '/test', 'hello.txt'), ' This is Node.js', err => {
    if (err) throw err;
    console.log('Text appended.');
  });
});

//Read file
fs.readFile(path.join(__dirname, '/test', 'hello.txt'), 'utf8', (err, data) => {
  if (err) throw err;
  console.log(data);
});