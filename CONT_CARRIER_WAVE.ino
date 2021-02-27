#include <SPI.h>
#include "RF24_MOD.h"
#include "nRF24L01.h"

RF24 radio(8,9);    //SCK -> 13//MISO -> 12//MOSI -> 11//CSN -> 9//CE -> 8

void setup(void)
{
  radio.begin();                                 //Mandatory  
  radio.setDataRate(RF24_250KBPS);               //Data Transfer Rate
  radio.write_register(CONFIG, 0x0A);            //Setting CONFIG Register
  delay(1500);
  radio.write_register(RF_SETUP, 0x93);    //Setting RF_SETUP Register
  delay(10);
  radio.setChannel(50);                          //SET Channel
  digitalWrite(8, HIGH);                         //Setting CE pin HIGH  
}

void loop(void)
{
  // Dont write anything here for obtaining CONTINEOUS CARRIER WAVE
}
