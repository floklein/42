import React, {Component} from 'react';
import {Provider} from 'react-redux';

import './css/normalize.css';
import './css/global.css';
import './css/index.css';

import triChat from './assets/img/tri-chat.svg';
import triCouple from './assets/img/tri-couple.svg';
import triMap from './assets/img/tri-map.svg';

import store from './store';
import Navbar from "./components/Navbar/navbar";
import Sidebar from './components/Sidebar/sidebar';
import Footer from "./components/Footer/footer";
import UserForm from "./components/UserForm/UserForm";
import ChatPanel from "./components/Chat/ChatPanel";

class App extends Component {
  render() {
    return (
      <Provider store={store}>
        <React.Fragment>
          <Sidebar/>
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
                      <UserForm/>
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
              <iframe title="map" width="3000" height="500" frameBorder="0"
                      src="https://www.google.com/maps/d/embed?mid=1-57radknCCRjqVekxyooWmvh-jQdV0_w&z=6&ll=47.048454, 3.105408"/>
            </div>
            <Footer/>
            <ChatPanel/>
          </div>
        </React.Fragment>
      </Provider>
    )
  }
}

export default App
