const express = require('express');
const path = require('path');
const logger = require('morgan');

const todoRouter = require('./routes/todo.js');

const cors = require('cors');
const app = express();

app.use(cors());

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(express.static(path.join(__dirname, '/front/build')));

app.use('/', todoRouter);

app.use(function(req, res, next) {
  return res.sendStatus(404);
});

app.use(function(err, req, res, next) {
  res.status(err.status || 500);
  return res.send(err);
});

module.exports = app;
