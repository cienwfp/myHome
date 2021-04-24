import React, { Component } from 'react';
import Chart from 'react-google-charts';
import axios from 'axios';
import { headers, userAdaFruitOI } from "../util/config";

export default class LineChart extends Component {

  state = {}
  componentDidMount() {
    axios.get(
      `https://io.adafruit.com/api/v2/${userAdaFruitOI}/feeds/temperatura/data/chart?day=7`,
      { headers: headers })
      .then((response) => {
        this.setState({
          lenght: response.data.data.lenght,
          coluna: response.data.columns,
          dataOrig: response.data.data
        })
      })
  }

  render() {
    {
      if (this.state.dataOrig) {
        data = []
        var dataa = this.state.dataOrig.map(function (serie) {
          serie[0] = new Date(serie[0])
          serie[1] = parseFloat(serie[1])

          return serie
        })


        var data = [[
          { type: 'date', label: 'Tempo' },
          'Temp',
        ]]

        dataa.map((dat) => {
          return data.push(dat)
        }
        )
      }
    }  

    return (
      <div>
        <Chart
          width={'100%'}
          height={'250px'}
          chartType="Line"
          loader={<div>Loading Chart</div>}
          data={data}
          options={{
            chart: {
              title:
                'Temperatura Média do Quarto',
            },
            series: {
              // Gives each series an axis name that matches the Y-axis below.
              0: { axis: 'Temps' },
            },
            axes: {
              // Adds labels to each axis; they don't have to match the axis names.
              y: {
                Temps: { label: 'Temps (°C)' },
              },
            },
          }}
          rootProps={{ 'data-testid': '4' }}
        />
      </div>
    );
  }
}