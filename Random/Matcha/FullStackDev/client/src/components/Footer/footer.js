import React, {Component} from 'react';

import './footer.css'

class Footer extends Component {

  render() {

    return (
      <div id="footer" className="centered">
        <div>
          <div>
            <h4>Soulmatch</h4>
            <a href=""><p>Accueil</p></a>
            <a href=""><p>Soulmatcher</p></a>
            <a href=""><p>Recherche</p></a>
          </div>
          <div>
            <h4>Mon compte</h4>
            <a href=""><p>Mon profil</p></a>
            <a href=""><p>Mes préférences</p></a>
            <a href=""><p>Déconnexion</p></a>
          </div>
          <div>
            <h4>L'équipe</h4>
            <a href=""><p>Florent Klein</p></a>
            <a href=""><p>Tanguy Boissel</p></a>
          </div>
          <div>
            <h4>À propos</h4>
            <a href=""><p>© 2019 Soulmatch</p></a>
          </div>
        </div>
      </div>
    );
  }
}

export default Footer;
