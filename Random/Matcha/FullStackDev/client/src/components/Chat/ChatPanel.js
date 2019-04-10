import React, {Component} from 'react';

import UserPic from './UserPic';
import Messages from './Messages';

import './chatpanel.css';

class ChatPanel extends Component {
  state = {
    shown: false
  };

  toggleChat = () => {
    const {shown} = this.state;

    this.setState({
      shown: !shown
    });
  };

  render() {
    const styleChat = {height: this.state.shown ? '21rem' : '0'};

    return (
      <React.Fragment>
        <div id="chatpanel">
          <div className="chat__title-bar" onClick={this.toggleChat}>
            <div className="chat__title-text">
              <h4>Discussion instantanée</h4>
            </div>
            <div className="chat__title-notifs">
              <div className="chat__notifs-div">
                <p>10</p>
              </div>
            </div>
          </div>
          <div className="chat__interface" style={styleChat}>
            <div className="chat__users-bar">
              <UserPic userId="Florent" notif={true}/>
              <UserPic userId="Tanguy" notif={false}/>
              <UserPic userId="Shana" notif={true}/>
              <UserPic userId="Yannis" notif={false}/>
              <UserPic userId="Arnaud" notif={false}/>
              <UserPic userId="Pierre-Antoine" notif={true}/>
              <UserPic userId="Léa" notif={false}/>
              <UserPic userId="BOT" notif={false}/>
            </div>
            <Messages/>
            <div className="chat__input-bar">

            </div>
          </div>
        </div>
      </React.Fragment>
    );
  }
}

export default ChatPanel;