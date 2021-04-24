import React, { Component } from 'react';
import './App.css';
import { Button, Container, Divider, Grid, Header, Segment } from 'semantic-ui-react';


import ReatingMeter from './component/ReatingMeter';
import ButtonToggleLuzSala1 from './component/buttonToggleLuzSala1';
import ButtonToggleLuzSala2 from './component/buttonToggleLuzSala2';
import ButtonToggleLuzQuarto1 from './component//buttonToggleLuzQuarto1';
import ButtonToggleLuzQuarto2 from './component//buttonToggleLuzQuarto2';
import ButtonToggleLuzCorredor from './component//buttonToggleLuzCorredor';
import ApexChart from './component/tempUmidCharts';

class App extends Component {

  render() {
    return (
      <>
        <h1>Minha Casa</h1>
        <div className='Segment'>
          <div className='Janela'>
            <ReatingMeter
              title='Temp'
            />
          </div>
          <div className='Janela'>
            <ReatingMeter
              title='Umid. Rel.'
            />
          </div>
        </div>
        <Segment>
          <Header as='h2' floated='right'>
            Iluminação
          </Header>
          <Divider clearing />
          <div className='Segment'>
            <div className='Janela'>
              <ButtonToggleLuzSala1
                title='Luz da Sala' />
            </div>
            <div className='Janela'>
              <ButtonToggleLuzSala2
                title='Luz Mesa' />
            </div>
            <div className='Janela'>
              <ButtonToggleLuzQuarto1
                title='Luz Quarto' />
            </div>
            <div className='Janela'>
              <ButtonToggleLuzQuarto2
                title='Luz Helena' />
            </div>
            <div className='Janela'>
              <ButtonToggleLuzCorredor
                title='Luz Corredor' />
            </div>
          </div>
        </Segment>
         <Segment>
          <ApexChart />
         </Segment>
      </>
    );
  }
};

export default App;
