import React, {Component} from 'react';
import classnames from 'classnames';

class ConnectFour extends Component {
  state = {
    tab: Array(6).fill().map(() => Array(7).fill('W')),
    turn: Math.random() < 0.5 ? 'R' : 'Y',
    win: '',
    ai: false,
    computer: ''
  };

  nextTurn = () => {
    const {ai, turn} = this.state;
    if (ai) {
      this.computerPlay();
    } else {
      this.setState({
        turn: turn === 'R' ? 'Y' : 'R'
      });
    }
  };

  findFirstWhite = (tab, r, c) => {
    for (let i = 0; i < tab.length; i++) {
      if (tab[i][c] !== 'W') {
        return i - 1;
      }
    }
    return 5;
  };

  addPiece = (r, c) => {
    if (this.state.win !== '') {
      return;
    }
    let tab = [...this.state.tab];
    let white = this.findFirstWhite(tab, r, c);
    if (white === -1) {
      return;
    }
    tab[white][c] = this.state.turn;
    this.setState({
      tab: tab
    });
    if (!this.didWin(this.state.turn)) {
      this.nextTurn();
    }
  };

  computerPlay = () => {
    if (this.state.win !== '') {
      return;
    }
    let tab = [...this.state.tab];
    let c = Math.floor(Math.random() * 7);
    let white = this.findFirstWhite(tab, 0, c);
    let i = 1000;
    while (white === -1 && i++ <= 1000) {
      c = Math.floor(Math.random() * 7);
      white = this.findFirstWhite(tab, 0, c);
      if (i === 999) {
        alert('No winner!');
        return;
      }
    }
    tab[white][c] = this.state.computer;
    this.setState({
      tab: tab
    });
    this.didWin(this.state.computer);
  };

  didWin = (who) => {
    const tab = [...this.state.tab];
    for (let r = 0; r < tab.length; r++) {
      for (let c = 0; c < tab[r].length; c++) {
        let i = 0;
        while (i < 4 && r - i >= 0 && tab[r - i][c] === who) {
          i++;
          if (i === 4) {
            this.setState({
              win: who
            });
            return;
          }
        }
        i = 0;
        while (i < 4 && r - i >= 0 && c + i < 7 && tab[r - i][c + i] === who) {
          i++;
          if (i === 4) {
            this.setState({
              win: who
            });
            return;
          }
        }
        i = 0;
        while (i < 4 && c + i < 7 && tab[r][c + i] === who) {
          i++;
          if (i === 4) {
            this.setState({
              win: who
            });
            return;
          }
        }
        i = 0;
        while (i < 4 && r + i < 6 && c + i < 7 && tab[r + i][c + i] === who) {
          i++;
          if (i === 4) {
            this.setState({
              win: who
            });
            return;
          }
        }
        i = 0;
        while (i < 4 && r + i < 6 && tab[r + i][c] === who) {
          i++;
          if (i === 4) {
            this.setState({
              win: who
            });
            return;
          }
        }
        i = 0;
        while (i < 4 && r + i < 6 && c - i >= 0 && tab[r + i][c - i] === who) {
          i++;
          if (i === 4) {
            this.setState({
              win: who
            });
            return;
          }
        }
        i = 0;
        while (i < 4 && c - i >= 0 && tab[r][c - i] === who) {
          i++;
          if (i === 4) {
            this.setState({
              win: who
            });
            return;
          }
        }
        i = 0;
        while (i < 4 && r - i >= 0 && c - i >= 0 && tab[r - i][c - i] === who) {
          i++;
          if (i === 4) {
            this.setState({
              win: who
            });
            return;
          }
        }
      }
    }
  };

  restartGame = () => {
    this.setState({
      tab: Array(6).fill().map(() => Array(7).fill('W')),
      turn: Math.random() < 0.5 ? 'R' : 'Y',
      win: '',
      ai: false,
      computer: ''
    });
  };

  handleChange = (e) => {
    this.setState({
      [e.target.name]: e.target.checked,
      computer: this.state.turn === 'R' ? 'Y' : 'R'
    });
  };

  render() {
    const {tab, turn, win, ai} = this.state;
    return (
      <React.Fragment>
        <div className="title">
          ConnectFour
        </div>
        <form>
          <input
            id="ai"
            name="ai"
            type="checkbox"
            checked={ai}
            hidden
            onChange={this.handleChange}/>
          <label className="ai-label" htmlFor="ai">AI</label>
        </form>
        <div className="grid">
          {tab.map((row, r) => (
            row.map((piece, c) => (
              <div
                key={r + c}
                className={classnames('piece', {
                  'red': piece === 'R',
                  'yellow': piece === 'Y'
                })}
                onClick={() => {
                  this.addPiece(r, c)
                }}
              />
            ))
          ))}
        </div>
        <div className={classnames('message', {
          'red': turn === 'R',
          'yellow': turn === 'Y',
          'win': win !== ''
        })}>
          {win !== '' ? (win === 'R' ? 'Red' : 'Yellow') + ' won!' : (turn === 'R' ? 'Red' : 'Yellow') + '\'s turn'}
        </div>
        <button className={classnames('restart', {
          'shown': win !== ''
        })} onClick={this.restartGame}>Restart
        </button>
      </React.Fragment>
    );
  }
}

export default ConnectFour;