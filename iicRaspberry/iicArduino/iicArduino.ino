// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

// pins A4 (SDA), A5 (SCL)
//freq 100000 (standard mode) 100kHz
#include <Wire.h>

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
//  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

unsigned int x=24;
//char x='9';
unsigned int y=11;

void loop() {  
  delay(1000);
//  Serial.println(y);
  x=analogRead(0);
  y=analogRead(1);
  Serial.println(x+1); 
  
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent( ) {
//  String msg = { x + y}
  char msg [4];
  msg[0]= x & 0x00ff;
  msg[1]= (x & 0xff00)>>8;
  msg[2]= y & 0x00ff;
  msg[3]=(y & 0xff00)>>8;
  

//  msg[0]=x;
//  msg[1]=y;
//  Wire.write(x);
  Wire.write(msg,sizeof(msg));
//  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}
