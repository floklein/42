import React, {Component} from 'react'
import {Provider} from 'react-redux'

import './css/normalize.css'
import './css/global.css'
import './css/index.css'

import triChat from './assets/img/tri-chat.svg'
import triCouple from './assets/img/tri-couple.svg'
import triMap from './assets/img/tri-map.svg'

import store from './store'
import Navbar from "./components/Navbar/navbar";
import Footer from "./components/Footer/footer";

class App extends Component {

  render() {
    return (
      <Provider store={store}>
        <div id="wrapper">
          <Navbar/>
          <div id="container">
            <div id="carousel" className="centered">
              <div>
                <div>
                  <div className="intro">
                    <h1>Likez. Matchez. Aimez.</h1>
                    <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Aliquid aperiam aspernatur
                      cupiditate
                      dolor doloribus incidunt inventore natus similique sunt vitae!</p>
                  </div>
                </div>
                <div>
                  <div className="login">
                    <h2>Créer un compte.</h2>
                    <form>
                      <input className="validation" type="text" name="username" placeholder="Nom d'utilisateur"
                             title="4 à 30 lettres minuscules" required pattern="^[a-z]{4,30}$" minLength="4"
                             maxLength="30"/>
                      <p>&nbsp;</p>
                      <input className="validation" type="email" name="email" placeholder="Email"
                             title="example@soulmatch.com" required minLength="1" maxLength="64"/>
                      <p>&nbsp;</p>
                      <input className="smaller-input validation" style={{marginRight: 3 + '%'}} type="text"
                             name="lastname" placeholder="Nom" title="1 à 30 lettres" required
                             pattern="^([a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+(( |')[a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+)*)+([-]([a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+(( |')[a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+)*)+)*$"
                             minLength="1" maxLength="30"/>
                      <input className="smaller-input validation" type="text" name="firstname"
                             placeholder="Prénom" title="1 à 30 lettres" required
                             pattern="^([a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+(( |')[a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+)*)+([-]([a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+(( |')[a-zA-Zàáâäçèéêëìíîïñòóôöùúûü]+)*)+)*$"
                             minLength="1" maxLength="30"/>
                      <p>&nbsp;</p>
                      <select className="validation" name="gender" title="gender" required>
                        <option value="" selected disabled hidden>Genre</option>
                        <option value="male">Homme</option>
                        <option value="female">Femme</option>
                        <option value="other">Autre</option>
                      </select>
                      <p>&nbsp;</p>
                      <input className="validation" type="password" name="password" placeholder="Mot de passe"
                             title="8 caractères min. dont 1 majuscule et 1 chiffre" required
                             pattern="^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).{8,64}$" minLength="8" maxLength="64"/>
                      <p>&nbsp;</p>
                      <input className="validation" type="password" name="confirm"
                             placeholder="Confirmez le mot de passe"
                             title="8 caractères min. dont 1 majuscule et 1 chiffre" required
                             pattern="^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).{8,64}$" minLength="8" maxLength="64"/>
                      <p>&nbsp;</p>
                      <button className="">S'inscrire</button>
                    </form>
                  </div>
                </div>
              </div>
            </div>
            <div id="triptych" className="centered">
              <div>
                <div>
                  <img src={triCouple} alt="test"/>
                  <h2>Trouvez votre soulmate</h2>
                  <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Ex, fuga.</p>
                </div>
                <div>
                  <img src={triMap} alt="test"/>
                  <h2>Autour de vous</h2>
                  <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Ex, fuga.</p>
                </div>
                <div>
                  <img src={triChat} alt="test"/>
                  <h2>Matchez et chattez</h2>
                  <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Ex, fuga.</p>
                </div>
              </div>
            </div>
          </div>
          <div id="map">
            <iframe width="3000" height="450" frameBorder="0"
                    src="https://www.google.com/maps/embed/v1/view?zoom=11&center=48.8566,2.3522&key=AIzaSyCS-B9GHmUTQhuflOJsynB2YgOhqK9btCM"/>
          </div>
          <Footer/>
        </div>
      </Provider>
    )
  }
}

export default App
