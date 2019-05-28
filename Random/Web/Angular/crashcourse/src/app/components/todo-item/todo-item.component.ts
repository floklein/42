import {Component, Input, OnInit} from '@angular/core';
import {Todo} from '../../models/Todo';

@Component({
  selector: 'app-todo-item',
  templateUrl: './todo-item.component.html',
  styleUrls: ['./todo-item.component.css']
})
export class TodoItemComponent implements OnInit {
  @Input() todo: Todo;

  constructor() {
  }

  ngOnInit() {
  }

  setClasses() {
    return {
      todo: true,
      'is-complete': this.todo.completed
    };
  }

}
