#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);
const byte address[6] = "00001";

int xPin = A0;
int yPin = A1;

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);

  char command = 'S';

  if (yVal < 300) {
    command = 'F';
  } else if (yVal > 400) {
    command = 'B';
  } else if (xVal < 300) {
    command = 'L';
  } else if (xVal > 400) {
    command = 'R';
  }

  radio.write(&command, sizeof(command));
  delay(50);
}
