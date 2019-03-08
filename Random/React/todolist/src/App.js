import React, { Component } from 'react';
import { BrowserRouter as Router, Route } from 'react-router-dom';
import Todos from './components/Todos';
import Header from './components/layout/Header';
import AddTodo from './components/AddTodo';
import About from './components/pages/About';
import uuid from 'uuid';
import axios from 'axios';

import './App.css';

const online = false;

class App extends Component {
  state = {
    todos: []
  }
  componentDidMount() {
    if (online) {
      axios.get('https://jsonplaceholder.typicode.com/todos?_limit=10')
        .then(res => this.setState({ todos: res.data }))
    }
  }
  // Toggle Complete
  markComplete = (id) => {
    this.setState({
      todos: this.state.todos.map(todo => {
        if (todo.id === id) {
          todo.completed = !todo.completed;
        }
        return todo;
      })
    });
  }
  // Delete Todo
  delTodo = (id) => {
    if (online) {
      axios.delete(`https://jsonplaceholder.typicode.com/todos/${id}`)
        .then(this.setState({ todos: [...this.state.todos.filter(todo => todo.id !== id)] }));
    } else {
      this.setState({ todos: [...this.state.todos.filter(todo => todo.id !== id)] });
    }
  }
  addTodo = (title) => {
    if (online) {
      axios.post('https://jsonplaceholder.typicode.com/todos', {
        title,
        completed: false
      })
        .then(res => this.setState({ todos: [...this.state.todos, res.data] }));
    } else {
      const newTodo = {
        title,
        id: uuid.v4()
      }
      this.setState({ todos: [...this.state.todos, newTodo] });
    }
  }
  render() {
    return (
      <Router>
        <div className="App">
          <div className="container">
            <Header />
            <Route exact path="/" render={props => (
              <React.Fragment>
                <AddTodo addTodo={this.addTodo} />
                <Todos todos={this.state.todos} markComplete={this.markComplete} delTodo={this.delTodo} />
              </React.Fragment>
            )} />
            <Route path="/about" component={About} />
          </div>
        </div>
      </Router>
    );
  }
}

export default App;
