# linkinhart
Sketching with Hardware Project from the CDTM

# Glove MIDI controller

Use a glove as a MIDI controller to make music with nothing but the power of your gloved hands.
Two copper tapes at each of the glove finger tips can be used to close a circuit by establising contact between the two upon which a voltage signal is sent to an arduino board. Additionally a gyroscope is mounted on top of the glove to capture pitch and role movements of the whole hand. Both types of inputs are sent via a LAN cable to a computer as a MIDI signal on which music can be generated depending on the signal type.

### Prerequisites

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
* Upload "" file to arduino
* Set up Hairless MIDI according to http://projectgus.github.io/hairless-midiserial/
* Start Ableton 9 (alternative DAW)
* Audio Media Setup

# Schematic

The following schematic shows the base wiring of the arduino uno, the MPU and the respective resistors.

![project_schematic](https://github.com/flow-ryan/linkinhart/blob/marcel/project_schematic.png)

In the final project, four red VCC wires as well as one one black groud wire are connected to one glove and the other four VCC red wires, one black ground wire, one SCL wire, one SDA wire and one blue VCC wire are connected to the other glove. Due to stability reasons, the connecting wires of each glove are combined in one LAN cable. Also one prototype universal PCB circuit boards is used for each glove as a middle component to provide a robust connection of the resistors with their corresponding wires.

# Project Pictures

The following picture shows the Arduino UNO with its respective wiring according to the above schematic:

![Arduino UNO](https://github.com/flow-ryan/linkinhart/blob/marcel/arduino.JPG)

The following picture shows the glove with both the copper tapes and the MPU installed as well as their corresponding wiring.

![Glove with copper tapes and MPU wiring](https://github.com/flow-ryan/linkinhart/blob/marcel/glove_mpu_wiring.JPG)

The following picture shows two copper tapes touching on one glove.

![Glove showing copper plate touch](https://github.com/flow-ryan/linkinhart/blob/marcel/glove_copper_plate_touch.JPG)


# Disclaimer

* The examples are not extensively tested and only meant as simple explanations and for inspiration.
* NO WARRANTY of ANY KIND is provided.
* There are probably several things that can be improved or added.


## License

This project is licensed under the Apache License 2.0 License - see the [LICENSE.md](LICENSE.md) file for details


# Acknowledgements

The following sources have been used while creating this project:
* http://www.instructables.com/id/Easy-3-Pot-Potentiometer-Arduino-Uno-Effects-Midi-/
* https://learn.adafruit.com/midi-drum-glove/
* http://www.giuseppecaccavale.it/arduino/mpu-6050-gy-521-arduino-tutorial/
* http://42bots.com/tutorials/arduino-uno-and-the-invensense-mpu-6050-6dof-imu/
* http://www.pitt.edu/~mpd41/Angle.ino

The project was part of the course "Sketching with Hardware" from the Center for Digitnal Technology and Management (CTDM)


```
Give examples
```

### Installing

A step by step series of examples that tell you have to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone who's code was used
* Inspiration
* etc
