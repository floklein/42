import React, {useEffect, useState} from 'react';
import axios from 'axios';

import './App.css';

const App = () => {
  const [items, setItems] = useState([{id: 0, name: 'test'}]);
  const [newItem, setNewItem] = useState('');
  const [editingItem, setEditingItem] = useState({id: -1, name: ''});

  const getItems = async () => {
    try {
      const {data} = await axios.get('/todo');
      setItems(data);
    } catch (e) {
      console.error(e);
    }
  };

  useEffect(() => {
    getItems();
  }, []);

  const addItem = async e => {
    if (e) e.preventDefault();
    try {
      await axios.post('/todo', {name: newItem});
      await getItems();
      setNewItem('');
    } catch (e) {
      console.error(e);
    }
  };

  const handleChange = e => {
    setNewItem(e.target.value);
  };

  const deleteItem = item => async () => {
    try {
      await axios.delete(`/todo/${item.id}`);
      await getItems();
    } catch (e) {
      console.error(e);
    }
  }

  const handleEdit = item => () => {
    setEditingItem(item);
  };

  const handleEditSubmit = async e => {
    if (e) e.preventDefault();
    try {
      await axios.post(`/todo/${editingItem.id}`, {name: editingItem.name});
      await getItems();
      setEditingItem({id: -1, name: ''});
    } catch (e) {
      console.error(e);
    }
  };

  const handleEditChange = e => {
    setEditingItem({...editingItem, name: e.target.value});
  };

  return (
    <div className="app">
      <div className="logo">ToDo.</div>
      <form onSubmit={addItem} className="addItem">
        <input type="text" value={newItem} placeholder="New todo..." onChange={handleChange} className="addItem__input" />
        <input type="submit" value="+" className="addItem__button" />
      </form>
      <ul className="itemsList">
        {items.map(i => (
          <li className="itemsList__item">
            {editingItem.id === i.id ? (
              <form onSubmit={handleEditSubmit} className="itemsList__item__form">
                <input type="text" value={editingItem.name} onChange={handleEditChange} className="itemsList__item__input" />
                <input type="submit" value="ok" className="itemsList__item__button" />
              </form>
            ) : (
              <>
                <span className="itemsList__item__name">{i.name}</span>
                <button onClick={handleEdit(i)} className="itemsList__item__button">edit</button>
              </>
            )}
            <button onClick={deleteItem(i)} className="itemsList__item__button">done</button>
          </li>
        ))}
      </ul>
    </div>
  );
}

export default App;
