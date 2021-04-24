import React, { Component } from 'react';
import { Button, Icon } from 'semantic-ui-react';
import axios from 'axios';
import { headers, userAdaFruitOI} from '../util/config';

class buttonToggleLuzQuarto1 extends Component {
  constructor() {
    super()
  }
  state = {
  }

  componentDidMount() {
    axios.get(
      `https://io.adafruit.com/api/v2/${userAdaFruitOI}/feeds/luz-quarto-1/data?limit=1`,
      { headers: headers })
      .then((response) => {
        if (response.data[0].value === '1') {
          this.setState((prevState) => ({ active: !prevState.active }))
        }
      })
  }

  handleClick = () => {
    this.setState((prevState) => ({ active: !prevState.active }));
    if (this.state.active) {
      axios.post(
        `https://io.adafruit.com/api/v2/${userAdaFruitOI}/feeds/luz-quarto-1/data`,
        {
          value: 0
        },
        {
          headers: headers
        },
      )
        .then((response) => { console.log(response.status) })
    } else {

      axios.post(
        `https://io.adafruit.com/api/v2/${userAdaFruitOI}/feeds/luz-quarto-1/data`,
        {
          value: 1
        },
        {
          headers: headers
        },
      )
        .then((response) => { console.log(response.status) })
    }
  };

  render() {
    const { active } = this.state
    return (
      <div className='Button'>
        <Button
          tabIndex
          fluid
          toggle
          size='medium'
          active={active}
          onClick={this.handleClick}>
          <Icon
            name='lightbulb outline'
          />
          <p>{this.props.title}</p>
        </Button>
      </div>
    )
  }
}

export default buttonToggleLuzQuarto1;