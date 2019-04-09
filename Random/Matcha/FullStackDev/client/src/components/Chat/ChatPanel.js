import React, {Component} from 'react';

import './chatpanel.css';

class ChatPanel extends Component {
  render() {
    return (
      <React.Fragment>
        <div id="chatpanel">
          <div className="chat__title-bar">

          </div>
          <div className="chat__interface">
            <div className="chat__users-bar">

            </div>
            <div className="chat__messages">

            </div>
            <div className="chat__input-bar">

            </div>
          </div>
        </div>
      </React.Fragment>
    );
  }
}

export default ChatPanel;