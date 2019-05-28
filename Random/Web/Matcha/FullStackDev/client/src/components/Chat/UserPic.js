import React, {Component} from 'react';

import './chatpanel.css';

class UserPic extends Component {
  render() {
    // CHANGE TO ID
    const {userId, notif} = this.props;
    const chatUserPicClasses = 'chat__user-pic ' + (notif ? 'notif' : '');

    return (
      <div className="chat__user-div">
        <div className={chatUserPicClasses}/>
        <div className="chat__user-overlay">{userId}</div>
      </div>
    );
  }
}

export default UserPic;