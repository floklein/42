import React, {Component} from 'react';

import imgSuccess from '../../../assets/img/email-sent.svg'

export class Success extends Component {
  render() {
    return (
      <React.Fragment>
        <img src={imgSuccess} alt="success"/>
        <h2>Vous êtes inscrit !</h2>
      </React.Fragment>);
  }
}

export default Success;