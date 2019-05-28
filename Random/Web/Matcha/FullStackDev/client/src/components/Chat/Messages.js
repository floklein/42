import React, {Component} from 'react';

import Message from './Message';

import './chatpanel.css';

class Messages extends Component {
  render() {
    return (
      <div className="chat__messages">
        <Message
          content={'Lorem ipsum dolor sit amet, consectetur adipisicing elit. Blanditiis delectus eaque enim ex exercitationem nemo officia quas sapiente sint, voluptate!'}
          date={'19:37'}
          whose={'mine'}
        />
        <Message
          content={'Je suis un message.'}
          date={'19:45'}
          whose={'yours'}
        />
        <Message
          content={'Salut sa va ??'}
          date={'20:02'}
          whose={'mine'}
        />
        <Message
          content={'Lorem ipsum dolor sit amet, consectetur adipisicing elit. Ad distinctio magni nemo pariatur quasi sequi.'}
          date={'20:21'}
          whose={'yours'}
        />
      </div>
    );
  }
}

export default Messages;