import React, {Component} from 'react';

import UserDetails from './UserDetails';
import MoreDetails from './MoreDetails';
import Success from './Success';

export class RegisterForm extends Component {
  state = {
    step: 1,
    email: '',
    password: '',
    confirm: '',
    username: '',
    firstName: '',
    lastName: '',
    gender: ''
  };

  // Go to next step
  nextStep = () => {
    const {step} = this.state;

    this.setState({
      step: step + 1
    });
  };

  // Go back to previous step
  prevStep = () => {
    const {step} = this.state;

    this.setState({
      step: step - 1
    });
  };

  // Handle fields change
  handleChange = input => e => {
    this.setState({[input]: e.target.value});
  };

  render() {
    const {step} = this.state;
    const {username, email, password, confirm, firstName, lastName, gender} = this.state;
    const values = {username, email, password, confirm, firstName, lastName, gender};

    switch (step) {
      default:
      case 1:
        return (
          <UserDetails
            gotoLogin={this.props.gotoLogin}
            nextStep={this.nextStep}
            handleChange={this.handleChange}
            values={values}
          />
        );
      case 2:
        return (
          <MoreDetails
            nextStep={this.nextStep}
            prevStep={this.prevStep}
            handleChange={this.handleChange}
            values={values}
          />
        );
      case 3:
        return (
          <Success/>
        );
    }
  }
}

export default RegisterForm;