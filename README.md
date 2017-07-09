# Glove MIDI controller

Use a glove as a MIDI controller to make music with nothing but the power of your gloved hands.
Two copper tapes at each of the glove finger tips can be used to close a circuit by establising contact between the two upon which a voltage signal is sent to an arduino board. Additionally a gyroscope is mounted on top of the glove to capture pitch and role movements of the whole hand. Both types of inputs are sent via a LAN cable to a computer as a MIDI signal on which music can be generated depending on the signal type.

## Prerequisites

What things you need to install the software and how to install them
The following hardware components are needed:

* Arduino UNO 
* 8 10K ohm resistors
* MPU6050
* 3 LAN cable
* 2 gloves
* 2 Prototype Universal PCB Circuit Board
* 10 copper tape
* ~ 30 Arduino wires

The following software is needed:

* Arduino IDE
* Hairless MIDI
* Ableton 9 (or any other DAW)

## Getting Started

Hardware:
* Connect Computer to Arduino UNO via LAN cable
* Connect Arduino to MPU and glove copper tapes (cmp. schematic)

Software:
* Upload file "linkinhart.ino" to arduino
* Set up Hairless MIDI according to http://projectgus.github.io/hairless-midiserial/
* Start Ableton 9 (alternative DAW)
* Audio Media Setup

## Schematic

The following schematic shows the base wiring of the arduino uno, the MPU and the respective resistors.

![project_schematic](https://github.com/flow-ryan/linkinhart/blob/marcel/project_schematic.png)

In the final project, four red VCC wires as well as one one black groud wire are connected to one glove and the other four VCC red wires, one black ground wire, one SCL wire, one SDA wire and one blue VCC wire are connected to the other glove. Due to stability reasons, the connecting wires of each glove are combined in one LAN cable. Also one prototype universal PCB circuit boards is used for each glove as a middle component to provide a robust connection of the resistors with their corresponding wires.

## File structure

All files needed for execution are located in the folder "linkinhart". The file "linkinhart.ino" implements the main functionality and needs to be uploaded to the arduino. The header files "MPU.h" and "NoteButton.h" provide class definition and corresponding functions for MPU and copper tape communication respectively.

## Project Demo



## Project Pictures

The following picture shows the Arduino UNO with its respective wiring according to the above schematic:

![Arduino UNO](https://github.com/flow-ryan/linkinhart/blob/marcel/arduino.JPG)

The following picture shows the glove with both the copper tapes and the MPU installed as well as their corresponding wiring.

![Glove with copper tapes and MPU wiring](https://github.com/flow-ryan/linkinhart/blob/marcel/glove_mpu_wiring.JPG)

The following picture shows two copper tapes touching on one glove.

![Glove showing copper plate touch](https://github.com/flow-ryan/linkinhart/blob/marcel/glove_copper_plate_touch.JPG)


## Disclaimer

* The examples are not extensively tested and only meant as simple explanations and for inspiration.
* NO WARRANTY of ANY KIND is provided.
* There are probably several things that can be improved or added.


## License

This project is licensed under the Apache License 2.0 License - see the [LICENSE.md](LICENSE.md) file for details


## Acknowledgements

The following sources have been used while creating this project:
* http://www.instructables.com/id/Easy-3-Pot-Potentiometer-Arduino-Uno-Effects-Midi-/
* https://learn.adafruit.com/midi-drum-glove/
* http://www.giuseppecaccavale.it/arduino/mpu-6050-gy-521-arduino-tutorial/
* http://42bots.com/tutorials/arduino-uno-and-the-invensense-mpu-6050-6dof-imu/
* http://www.pitt.edu/~mpd41/Angle.ino

The project was part of the course "Sketching with Hardware" from the Center for Digitnal Technology and Management (CTDM)
