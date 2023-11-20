#include <Arduino.h>
#include <Wire.h>
#include <Windy.h>
#include <DHT.h>

int temp()
{
  //collect temperature from DHT 11 / DHT 22
  uint8_t temp = dht.readTemperature();
  return temp;
}

int hygro()
{
  //collect Hygometric data from DHT 11 / DHT 22
  uint8_t hum = dht.readHumidity();
  return hum;
}

int barometer()
{
  //collect barometric pressure via I2C from barometer
  Wire.requestFrom(2, 8);
  uint8_t baro = Wire.read();
  return baro;
}

int correction()
{
  //use hygrometer and barometer to adjust windchill factor. shoud return an int.
  barometer();
  hygro();
  return 0;
}

int direction()
{
  //compare temperatures of termistor-ring to determine/calculate wind direction
  int dir = 0;
  int n = analogRead(N);
  int ne = analogRead(NE);
  int e = analogRead(E);
  int se = analogRead(SE);
  int s = analogRead(S);
  int sw = analogRead(SW);
  int w = analogRead(W);
  int nw = analogRead(NW);

  if (((nw + n + ne) / 3) > ((se + s + sw + w + e) / 5))
  {
    dir = 1;
  }

  if (((n + ne + e) / 3) > ((se + s + sw + w + nw) / 5))
  {
    dir = 2;
  }

  if (((ne + e + se) / 3) > ((n + s + sw + w + nw) / 5))
  {
    dir = 3;
  }

  if (((e + se + s) / 3) > ((ne + n + sw + w + nw) / 5))
  {
    dir = 4;
  }

  if (((se + s + sw) / 3) > ((ne + n + e + w + nw) / 5))
  {
    dir = 5;
  }

  if (((s + sw + w) / 3) > ((ne + n + e + se + nw) / 5))
  {
    dir = 6;
  }

  if (((sw + w + nw) / 3) > ((se + s + ne + e + n) / 5))
  {
    dir = 7;
  }

  if (((w + nw + n) / 3) > ((se + s + sw + e + ne) / 5))
  {
    dir = 8;
  }
  
  else
  {
    dir = 0;
  }
  
  switch (dir)
  {
  case 1:
    //Leds lit in correct direction
  case 2:

  case 3:

  case 4:

  case 5:

  case 6:

  case 7:

  case 8:

    break;
  
  default:
    // All Led turned off
    break;
  }
  

  return dir;
}

int windchill()
{
  //calculate windchill to determine approximate windspeed

  return 0;
}

int drive(bearing)
{
  return 0;
}


void setup() {
  dht.begin();
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
  pinMode(DHTPIN, INPUT);
  pinMode(LEDN, INPUT);
  pinMode(LEDNE, INPUT);
  pinMode(LEDE, INPUT);
  pinMode(LEDSE, INPUT);
  pinMode(LEDS, INPUT);
  pinMode(LEDSW, INPUT);
  pinMode(LEDW, INPUT);
  pinMode(LEDNW, INPUT);
}


void loop() {
  
  
  // put your main code here, to run repeatedly:
}
