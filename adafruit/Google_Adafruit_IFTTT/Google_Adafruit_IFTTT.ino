/*
   Exemplo: Acionamento de Rele ESP8266 - Adafruit IO
   Por: cienwfp
*/

/************************ Configurações do Adafruit IO *******************************/
//Insira seu nome de usuário e chave. Você encontra essas informações acessando
//sua conta no Adafruit IO
#define IO_USERNAME "{usernameADAFRUIT}"
#define IO_KEY "accessKeyAdafruit"

/********************* Configuração do WIFI **************************************/

//Insira o SSID e Senha da rede WIFI a qual você irá conectar
#define WIFI_SSID "{yourWifiName}"
#define WIFI_PASS "{wifiPassword}"


/***************Configurações do comunicaçaão************/
#include "AdafruitIO_WiFi.h"

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

/************************ Mapeamento de IO *******************************/
#define RELE1 5   //pino de saida para acionamento da Luz Ambiente
#define RELE2 4   //pino de saida para acionamento da Luz da Sala
#define RELE3 0   //pino de saida para acionamento da Luz da Mesa
#define RELE4 2   //pino de saida para acionamento da Luz do Corredor
#define RELE5 14   //pino de saida para acionamento da Luz do Quanto 1 (Helena)
#define RELE6 12   //pino de saida para acionamento da Luz do Meu Quarto
#define RELE7 13   //pino de saida para acionamento da Tomanda
#define RELE8 15   //pino de saida para acionamento da Regador


/************************ Configuração dos tópicos *******************************/

// configura o tópico "fs_embarcados/feeds/rele_1"
AdafruitIO_Feed *feedRele1 = io.feed("luz-sanca");
AdafruitIO_Feed *feedRele2 = io.feed("luz-sala-1");
AdafruitIO_Feed *feedRele3 = io.feed("luz-sala-2");
AdafruitIO_Feed *feedRele4 = io.feed("luz-corredor");
AdafruitIO_Feed *feedRele5 = io.feed("luz-quarto-1");
AdafruitIO_Feed *feedRele6 = io.feed("luz-quarto-2");
AdafruitIO_Feed *feedRele7 = io.feed("tomada-sala");
AdafruitIO_Feed *feedRele8 = io.feed("regador");


/************************ Função setup *******************************/

void setup() {

  //configura pino da Lampada como saída
  pinMode(RELE1, OUTPUT);
  pinMode(RELE2, OUTPUT);
  pinMode(RELE3, OUTPUT);
  pinMode(RELE4, OUTPUT);
  pinMode(RELE5, OUTPUT);
  pinMode(RELE6, OUTPUT);
  pinMode(RELE7, OUTPUT);
  pinMode(RELE8, OUTPUT);

  // configura comunicação serial
  Serial.begin(115200);

  // Aguarda serial monitor
  while (! Serial);

  conectaBroker(); //função para conectar ao broker


}

/************************ Função loop *******************************/

void loop() {

  // processa as mensagens e mantêm a conexão ativa
  byte state = io.run();

  //verifica se está conectado
  if (state == AIO_NET_DISCONNECTED | state == AIO_DISCONNECTED) {
    conectaBroker(); //função para conectar ao broker
  }

}

/****** Função de tratamento dos dados recebidos em L1***************/

void handleRele1(AdafruitIO_Data *data) {

  // Mensagem
  Serial.print("Recebido  <- ");
  Serial.print(data->feedName());
  Serial.print(" : ");
  Serial.println(data->value());

  //Aciona saída conforme dado recebido
  if (data->isTrue()) {
    digitalWrite(RELE1, LOW);
    delay(2000);
  }
  else {
    digitalWrite(RELE1, HIGH);
    delay(2000);
  }
}

void handleRele2(AdafruitIO_Data *data) {

  // Mensagem
  Serial.print("Recebido  <- ");
  Serial.print(data->feedName());
  Serial.print(" : ");
  Serial.println(data->value());

  //Aciona saída conforme dado recebido
  if (data->isTrue()) {
    digitalWrite(RELE2, LOW);
    delay(2000);
  }
  else {
    digitalWrite(RELE2, HIGH);
    delay(2000);
  }
}

void handleRele3(AdafruitIO_Data *data) {

  // Mensagem
  Serial.print("Recebido  <- ");
  Serial.print(data->feedName());
  Serial.print(" : ");
  Serial.println(data->value());

  //Aciona saída conforme dado recebido
  if (data->isTrue()) {
    digitalWrite(RELE3, LOW);
    delay(2000);
  }
  else {
    digitalWrite(RELE3, HIGH);
    delay(2000);
  }
}

void handleRele4(AdafruitIO_Data *data) {

  // Mensagem
  Serial.print("Recebido  <- ");
  Serial.print(data->feedName());
  Serial.print(" : ");
  Serial.println(data->value());

  //Aciona saída conforme dado recebido
  if (data->isTrue()) {
    digitalWrite(RELE4, LOW);
    delay(2000);
  }
  else {
    digitalWrite(RELE4, HIGH);
    delay(2000);
  }
}

void handleRele5(AdafruitIO_Data *data) {

  // Mensagem
  Serial.print("Recebido  <- ");
  Serial.print(data->feedName());
  Serial.print(" : ");
  Serial.println(data->value());

  //Aciona saída conforme dado recebido
  if (data->isTrue()) {
    digitalWrite(RELE5, LOW);
    delay(2000);
  }
  else {
    digitalWrite(RELE5, HIGH);
    delay(2000);
  }
}

void handleRele6(AdafruitIO_Data *data) {

  // Mensagem
  Serial.print("Recebido  <- ");
  Serial.print(data->feedName());
  Serial.print(" : ");
  Serial.println(data->value());

  //Aciona saída conforme dado recebido
  if (data->isTrue()) {
    digitalWrite(RELE6, LOW);
    delay(2000);
  }
  else {
    digitalWrite(RELE6, HIGH);
    delay(2000);
  }
}

void handleRele7(AdafruitIO_Data *data) {

  // Mensagem
  Serial.print("Recebido  <- ");
  Serial.print(data->feedName());
  Serial.print(" : ");
  Serial.println(data->value());

  //Aciona saída conforme dado recebido
  if (data->isTrue()) {
    digitalWrite(RELE7, LOW);
    delay(2000);
  }
  else {
    digitalWrite(RELE7, HIGH);
    delay(2000);
  }
}

void handleRele8(AdafruitIO_Data *data) {

  // Mensagem
  Serial.print("Recebido  <- ");
  Serial.print(data->feedName());
  Serial.print(" : ");
  Serial.println(data->value());

  //Aciona saída conforme dado recebido
  if (data->isTrue()) {
    digitalWrite(RELE8, LOW);
    delay(2000);
  }
  else {
    digitalWrite(RELE8, HIGH);
    delay(2000);
  }
}

/****** Função para conectar ao WIFI e Broker***************/

void conectaBroker() {

  //mensagem inicial
  Serial.print("Conectando ao Adafruit IO");

  // chama função de conexão io.adafruit.com
  io.connect();

  // instancia um novo handler para recepção da mensagem do feed Rele
  feedRele1->onMessage(handleRele1);
  feedRele2->onMessage(handleRele2);
  feedRele3->onMessage(handleRele3);
  feedRele4->onMessage(handleRele4);
  feedRele5->onMessage(handleRele5);
  feedRele6->onMessage(handleRele6);
  feedRele7->onMessage(handleRele7);
  feedRele8->onMessage(handleRele8);

  // Aguarda conexação ser estabelecida
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // Conectado
  Serial.println();
  Serial.println(io.statusText());

  // certifique-se de que todos os feeds obtenham seus valores atuais imediatamente
  feedRele1->get();
  feedRele2->get();
  feedRele3->get();
  feedRele4->get();
  feedRele5->get();
  feedRele6->get();
  feedRele7->get();
  feedRele8->get();
}
