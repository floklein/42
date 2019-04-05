import React, {Component} from 'react';

import './navbar.css'

import logo from '../../assets/img/logo.svg'

class Navbar extends Component {

  render() {

    return (
      <div id="navbar">
        <div className="nav-items">
          <div>
            <div><a href="">Accueil</a></div>
            <div className="vr"/>
            <div><a href="#">Soulmatcher</a></div>
            <div className="vr"/>
            <div><a href="#">Recherche</a></div>
          </div>
          <div className="logo">
            <a href=""><img src={logo} alt="logo"/></a>
          </div>
          <div>
            <div>
              <svg xmlns="http://www.w3.org/2000/svg" width="30" height="30" viewBox="0 0 24 24" fill="none"
                   stroke="#000000" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                <path d="M22 17H2a3 3 0 0 0 3-3V9a7 7 0 0 1 14 0v5a3 3 0 0 0 3 3zm-8.27 4a2 2 0 0 1-3.46 0"/>
              </svg>
            </div>
            <div>
              <svg xmlns="http://www.w3.org/2000/svg" width="30" height="30" viewBox="0 0 24 24" fill="none"
                   stroke="#000000" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                <path d="M20 21v-2a4 4 0 0 0-4-4H8a4 4 0 0 0-4 4v2"/>
                <circle cx="12" cy="7" r="4"/>
              </svg>
            </div>
            <div>
              <svg xmlns="http://www.w3.org/2000/svg" width="30" height="30" viewBox="0 0 24 24" fill="none"
                   stroke="#000000" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                <path d="M10 3H6a2 2 0 0 0-2 2v14c0 1.1.9 2 2 2h4M16 17l5-5-5-5M19.8 12H9"/>
              </svg>
            </div>
          </div>
        </div>
      </div>
    );
  }
}

export default Navbar;
