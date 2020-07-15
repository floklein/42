const express = require('express');
const router = express.Router();

let toDoItems = [
  {
    id: 0,
    name: 'Trouver un stage'
  }
];

//Récupérer la liste des items
router.get('/todo', function(req, res, next) {
  res.json(toDoItems);
});

//Creer un nouvel item
router.post('/todo', function(req, res, next) {
  if (req.body.name.length === 0) {
    res.status(400);
    return res.end();
  }
  toDoItems.push({id: toDoItems.length, name: req.body.name});
  res.json();
});

//Modifier un item
router.post('/todo/:id', function(req, res, next) {
  if (req.body.name.length === 0) {
    res.status(400);
    return res.end();
  }
  const { id } = req.params;
  toDoItems.forEach((item, i) => {
    if (item.id == id) {
      toDoItems[i].name = req.body.name;
    }
  });
  res.json(id);
});

//Supprimer un item
router.delete('/todo/:id', function(req, res, next) {
  const { id } = req.params;
  toDoItems = toDoItems.filter(item => item.id != id);
  res.json(id);
});
module.exports = router;