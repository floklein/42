import React, {Component} from 'react';

import './chatpanel.css';

class Messages extends Component {
  render() {
    return (
      <div className="chat__messages">
        <div className="chat__message mine">
          <div className="chat__msg-content">
            <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Asperiores consectetur corporis ducimus earum eum ex facere inventore molestiae nostrum sit!</p>
          </div>
        </div>
        <div className="chat__message yours">
          <div className="chat__msg-content">
            <p>Lorem ipsum dolor sit amet.</p>
          </div>
        </div>
        <div className="chat__message mine">
          <div className="chat__msg-content">
            <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Doloremque doloribus eaque esse et fuga illum iste iusto labore non obcaecati, officia optio praesentium quae recusandae repellat vero vitae voluptate voluptatibus.</p>
          </div>
        </div>
        <div className="chat__message yours">
          <div className="chat__msg-content">
            <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit.</p>
          </div>
        </div>
        <div className="chat__message yours">
          <div className="chat__msg-content">
            <p>Test!</p>
          </div>
        </div>
      </div>
    );
  }
}

export default Messages;