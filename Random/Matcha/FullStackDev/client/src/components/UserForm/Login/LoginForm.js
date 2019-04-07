import React, {Component} from 'react';

export class LoginForm extends Component {
  render() {
    return (
      <React.Fragment>
        <h2>Se connecter.</h2>
        <p className="subtitle">Pas de compte ? <span onClick={this.props.gotoRegister}>Inscrivez-vous !</span></p>
        <input type="text" name="login" placeholder="Votre pseudo ou votre email"
               title="Votre pseudo ou votre email" required minLength="1" maxLength="64"/>
        <p>&nbsp;</p>
        <input type="password" name="password" placeholder="Votre mot de passe"
               title="Votre mot de passe" required
               minLength="8" maxLength="64"/>
        <p>&nbsp;</p>
        <button className="green">Connexion</button>
      </React.Fragment>);
  }
}

export default LoginForm;