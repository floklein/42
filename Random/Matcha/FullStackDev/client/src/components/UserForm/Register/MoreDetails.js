import React, {Component} from 'react';
import {Spring, config} from 'react-spring/renderprops';

export class MoreDetails extends Component {
  continue = e => {
    e.preventDefault();
    this.props.nextStep();
  };

  previous = e => {
    e.preventDefault();
    this.props.prevStep();
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
            <h2>À propos de vous.</h2>
            <p className="subtitle">Dites-nous en plus...</p>
            <input className="validation" type="text" name="username" placeholder="Choisissez un pseudo"
                   title="4 à 30 lettres minuscules" required pattern="^[a-zA-Z]{4,30}$" minLength="4" maxLength="30"
                   onChange={handleChange('username')} defaultValue={values.username}/>
            <p>&nbsp;</p>
            <input className="smaller-input validation" style={{marginRight: 3 + '%'}} type="text" name="lastname"
                   placeholder="Nom" title="1 à 30 lettres" required
                   pattern="^([a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+(( |')[a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+)*)+([-]([a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+(( |')[a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+)*)+)*$"
                   minLength="1" maxLength="30"
                   onChange={handleChange('lastName')} defaultValue={values.lastName}/>
            <input className="smaller-input validation" type="text" name="firstname" placeholder="Prénom"
                   title="1 à 30 lettres" required
                   pattern="^([a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+(( |')[a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+)*)+([-]([a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+(( |')[a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+)*)+)*$"
                   minLength="1" maxLength="30"
                   onChange={handleChange('firstName')} defaultValue={values.firstName}/>
            <p>&nbsp;</p>
            <select className="validation" name="gender" title="gender" required
                    onChange={handleChange('gender')} defaultValue={values.gender}>
              <option value="" disabled hidden>Genre</option>
              <option value="male">Homme</option>
              <option value="female">Femme</option>
              <option value="other">Autre</option>
            </select>
            <p>&nbsp;</p>
            <button className="back-btn" onClick={this.previous}>&nbsp;</button>
            <button className="pink" onClick={this.continue}>S'inscrire</button>
          </div>}
        </Spring>
      </React.Fragment>);
  }
}

export default MoreDetails;