import React, { Component } from 'react';
import ReactSpeedometer from 'react-d3-speedometer';
import axios from 'axios';
import { headers, userAdaFruitOI } from "../util/config";
import dotenv from 'dotenv';

dotenv.config();

const values = [
  { label: 'Email Campaign', value: 189, fill: '#881' },
  { label: 'Google AdWords', value: 65, fill: '#188' },
  { label: 'Youtube Campaign', value: 49, fill: '#818' },
  { label: 'Facebook Campaign', value: 29, fill: '#bb4' },
];

export default class ReatingMeter extends Component {
  constructor(props) {
    super(props);
    this.state = { title: props.title }
  };
  state = {}


  componentDidMount() {
    if (this.state.title === 'Temp') {
      axios.get(
        `https://io.adafruit.com/api/v2/${userAdaFruitOI}/feeds/temperatura/data?limit=1`,
        { headers: headers })
        .then(response =>
          this.setState({
            temp: response.data[0].value
          })
        )
    } else {
      axios.get(
        `https://io.adafruit.com/api/v2/${userAdaFruitOI}/feeds/umidade/data?limit=1`,
        { headers: headers })
        .then(response =>
          this.setState({
            umid: response.data[0].value
          })
        )
    }
  }

  render() {

    return (
      <div style={{
        width: '100%',
        height: '120px',
      }}>
        {(this.state.title === 'Temp') ? (
          <ReactSpeedometer
            fluidWidth={true} I
            currentValueText={`${this.props.title} : ${this.state.temp} °C`}
            value={this.state.temp}
            maxValue={50}
            segments={5}
            needleColor="red"
            startColor="yellow"
            endColor="blue"

          // startColor will be ignored
          // endColor will be ignored
          />
        ) : (
            <ReactSpeedometer
              fluidWidth={true} I
              currentValueText={`${this.props.title} : ${this.state.umid} %`}
              value={this.state.umid}
              maxValue={100}
              segments={5}
              needleColor="red"
              startColor="yellow"
              endColor="blue"

            // startColor will be ignored
            // endColor will be ignored
            />
          )
        }
      </div>
    );
  }
}