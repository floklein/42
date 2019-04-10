import React, {Component} from 'react';

import './chatpanel.css';

class Message extends Component {
  render() {
    const {content, date, whose} = this.props;

    return (
      <div className={'chat__message ' + whose}>
        <div className="chat__msg-content">
          <p>{content}</p>
        </div>
        <div className="chat__msg-date">{date}</div>
      </div>
    );
  }
}

export default Message;