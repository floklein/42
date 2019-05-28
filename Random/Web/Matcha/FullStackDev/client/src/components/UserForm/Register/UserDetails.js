import React, {Component} from 'react';
import {Spring, config} from 'react-spring/renderprops';

export class UserDetails extends Component {
  continue = e => {
    e.preventDefault();
    this.props.nextStep();
  };

  render() {
    const {values, handleChange} = this.props;

    return (
      <React.Fragment>
        <Spring
          config={config.molasses}
          from={{opacity: 0}}
          to={{opacity: 1}}>
          {props => <div style={props}>
            <h2>Créer un compte.</h2>
            <p className="subtitle">Déjà inscrit ? <span onClick={this.props.gotoLogin}>Connectez-vous !</span></p>
            <input className="validation" type="email" name="email" placeholder="Votre adresse email"
                   title="example@soulmatch.com" required minLength="1" maxLength="64"
                   onChange={handleChange('email')} defaultValue={values.email}/>
            <p>&nbsp;</p>
            <input className="validation" type="password" name="password" placeholder="Choisissez un mot de passe"
                   title="8 caractères min. dont 1 majuscule et 1 chiffre" required
                   pattern="^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).{8,64}$" minLength="8" maxLength="64"
                   onChange={handleChange('password')} defaultValue={values.password}/>
            <p>&nbsp;</p>
            <input className="validation" type="password" name="confirm" placeholder="Confirmez le mot de passe"
                   title="8 caractères min. dont 1 majuscule et 1 chiffre" required
                   pattern="^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).{8,64}$" minLength="8" maxLength="64"
                   onChange={handleChange('confirm')} defaultValue={values.confirm}/>
            <p>&nbsp;</p>
            <button className="blue" onClick={this.continue}>Suivant</button>
          </div>}
        </Spring>
      </React.Fragment>);
  }
}

export default UserDetails;