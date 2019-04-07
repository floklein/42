import React, {Component} from 'react';
import {config, Spring} from 'react-spring/renderprops'

import imgSuccess from '../../../assets/img/email-sent.svg'

export class Success extends Component {
  render() {
    const subtitleStyle = {padding: '0 10%', marginBottom: '1.5rem', lineHeight: '1.4rem'};

    return (
      <React.Fragment>
        <Spring
          config={config.molasses}
          from={{opacity: 0}}
          to={{opacity: 1}}
          leave={{opacity: 0}}>
          {props => <div style={props}>
            <img src={imgSuccess} alt="success"/>
            <h2>Vérifiez vos mails !</h2>
            <p className="subtitle" style={subtitleStyle}>Nous vous avons envoyé un mail de confirmation.</p>
          </div>}
        </Spring>
      </React.Fragment>);
  }
}

export default Success;