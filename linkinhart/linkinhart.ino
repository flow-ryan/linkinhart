#include "NoteButton.h"
#include "MPU.h"

// define the chords as a set of 4 notes (root, third, fifth, root_high)
int c_dur[] = {60, 64, 67, 72};
int g_dur[] = {67, 71, 74, 79};
int a_moll[] = {69, 72, 76, 81};
int f_dur[] = {65, 69, 72, 77};
int d_moll[] = {62, 65, 69, 74};
int drums[] = {36, 42, 40, 39};

int *chord; 
int root_note, third_note, fifth_note, root_note_high;

// play all notes at constant velocity
int velocity = 127;

// four inputs for playing the Notes
int inputA = 5;
int inputB = 6;
int inputC = 7;
int inputD = 8;
NoteButton buttonA (inputA);
NoteButton buttonB (inputB);
NoteButton buttonC (inputC);
NoteButton buttonD (inputD);

// four inputs for selecting the chords
int inputE = 9;
int inputF = 10;
int inputG = 11;
int inputH = 12;

// define the MPU object
const int MPU_addr=0x68;
MPU mpu_object (MPU_addr);

// calculating variables
double comp_angle_y;
int filter_val;
int filter_count = 0;

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

  // Select the chord
  if (digitalRead(inputE) == LOW)
    chord = g_dur;
  else if (digitalRead(inputF) == LOW)
    chord = a_moll;
  else if (digitalRead(inputG) == LOW)
    chord = f_dur;
  else if (digitalRead(inputH) == LOW)
    chord = d_moll;
  else
    chord = c_dur;

  root_note = chord[0];
  third_note = chord[1];
  fifth_note = chord[2];
  root_note_high = chord[3];

  // play the notes
  buttonA.processButton(root_note, velocity);
  buttonB.processButton(third_note, velocity);
  buttonC.processButton(fifth_note, velocity);
  buttonD.processButton(root_note_high, velocity);

  filter_count++;

  // the filter only gets updated every 5 iterations to not overload the connection
  // process all MPU data
  mpu_object.process();
  // get the Y angle
  comp_angle_y = mpu_object.get_comp_angle_y();
  // send filter value via midi
  filter_val = (127. / 360.) * comp_angle_y + 63.5;
  
  if (filter_count == 5) {
    sendMidi(176, 95, filter_val);
    filter_count = 0;
  }

  // 50 hz update freq
  delay(20);

}

void sendMidi(byte command, byte data1, byte data2) {
   Serial.write(command);
   Serial.write(data1);
   Serial.write(data2);
}

