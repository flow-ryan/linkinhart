#include "NoteButton.h"
#include "MPU.h"

// define the chords
int c_dur[] = {60, 64, 67, 72};
int g_dur[] = {67, 71, 74, 79};
int a_moll[] = {69, 72, 76, 81};
int f_dur[] = {65, 69, 72, 77};
int d_moll[] = {62, 65, 69, 74};
int drums[] = {36, 42, 40, 39};

int *tonart = c_dur;

// four notes of one triad
int root_note;
int third_note;
int fifth_note;
int root_note_high;

int inputA = 5;
int inputB = 6;
int inputC = 7;
int inputD = 8;

int inputE = 9;
int inputF = 10;
int inputG = 11;
int inputH = 12;

NoteButton buttonA (inputA);
NoteButton buttonB (inputB);
NoteButton buttonC (inputC);
NoteButton buttonD (inputD);

const int MPU_addr=0x68;
MPU mpu_object (MPU_addr);

double compAngleY;
int result;
int velocity = 127;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(inputA, INPUT);
  pinMode(inputB, INPUT);
  pinMode(inputC, INPUT);
  pinMode(inputD, INPUT);
  pinMode(inputE, INPUT);
  pinMode(inputF, INPUT);
  pinMode(inputG, INPUT);
  pinMode(inputH, INPUT);

  mpu_object.setup();

}

void loop() {

  // set the chord via the inputs E-H
  if (digitalRead(inputE) == LOW)
    tonart = g_dur;
  else if (digitalRead(inputF) == LOW)
    tonart = a_moll;
  else if (digitalRead(inputG) == LOW)
    tonart = f_dur;
  else if (digitalRead(inputH) == LOW)
    tonart = d_moll;
  else
    tonart = c_dur;

  root_note = tonart[0];
  third_note = tonart[1];
  fifth_note = tonart[2];
  root_note_high = tonart[3];
  
  buttonA.processButton(root_note, velocity);
  buttonB.processButton(third_note, velocity);
  buttonC.processButton(fifth_note, velocity);
  buttonD.processButton(root_note_high, velocity);
  
  delay(10);

  mpu_object.process();
  compAngleY = mpu_object.get_comp_angle_y();

  result = (127. / 360.) * compAngleY + 63.5;
  sendMidi(176, 95, result);

}

void sendMidi(byte command, byte data1, byte data2) //pass values out through standard Midi Command
{ 
   Serial.write(command);
   Serial.write(data1);
   Serial.write(data2);
}
