#include "NoteButton.h"

int velocity = 127;
int factor;

int noteA = 60;
int noteB = 64;
int noteC = 67;

int inputA = 6;
int inputB = 4;
int inputC = 2;

NoteButton buttonA (inputA);
NoteButton buttonB (inputB);
NoteButton buttonC (inputC);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(inputA, INPUT);
  pinMode(inputB, INPUT);
  pinMode(inputC, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  buttonA.processButton(noteA, velocity);
  buttonB.processButton(noteB, velocity);
  buttonC.processButton(noteC, velocity);
  
  delay(10);

}
