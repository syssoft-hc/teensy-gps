#include <Arduino.h>

#include <GPS.h>

// ***********************************************************************
// GPS_Test - Teensy 3.0 Version
//
// GPS Navilock NL-552ETTL via UART
// +5V, GND, Shield = GND, TX->UART1(RX, Pin 0), RX->UART1(TX, Pin 1)
// ***********************************************************************

oxoo2a::GPS gps(&Serial1);

boolean gps_fixed;

const int busyPin = 13;

void setup() {
  Serial.begin(115200);
  Serial.println("GPS Test");
  
  // Busy LED on while CPU in loop()
  pinMode(busyPin, OUTPUT);
  
  // Initialize Navilock GPS with default configuration
  gps.Init(9600);
    
  gps_fixed = false;
}

void loop() {
  if (millis() / 1000 % 2 == 0)
    digitalWrite(busyPin, HIGH);
  else
    digitalWrite(busyPin, LOW);;

  // Catch any message sent from GPS device as a single string
  char *message = gps.GPSMessage(NULL,false);
  Serial.println(message);
}
