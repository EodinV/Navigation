#include <Arduino.h>
#include <Wire.h>
#include <Windy.h>

int temp()
{
  //collect temperature from DHT 11 / DHT 22
  return 0;
}

int hygro()
{
  //collect Hygometric data from DHT 11 / DHT 22
  return 0;
}

int barometer()
{
  //collect barometric pressure via I2C from barometer
  return 0;
}

int correction()
{
  //use hygrometer and barometer to adjust windchill factor. shoud return an int.
  return 0;
}

int windchill()
{
  //calculate windchill to determine approximate windspeed
  return 0;
}

int direction()
{
  //compare temperatures of termistor-ring to determine/calculate wind direction
  return 0;
}


void setup() {
  Wire.begin();
  Serial.begin(9600);
  pinMode(N, INPUT);
  pinMode(NE, INPUT);
  pinMode(E, INPUT);
  pinMode(SE, INPUT);
  pinMode(S, INPUT);
  pinMode(SW, INPUT);
  pinMode(W, INPUT);
  pinMode(NW, INPUT);
  pinMode(BAROA, INPUT);
  pinMode(BAROL, INPUT);
  pinMode(HYGRO, INPUT);
  pinMode(TEMP, INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
}
