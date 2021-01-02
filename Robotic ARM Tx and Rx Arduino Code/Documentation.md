#Internet based Robotic Arm Control Documentation
---
In this section we will talk about the Wi-Fi Browser Controlled Robotic Arm over arduino and ESP8266 interfacing. So, before we get started let's first talk about the essentials of the project.

<h3> What is an Arduino? </h3>

Arduino is an open-source electronics platform based on easy-to-use hardware and software. Arduino boards are able to read inputs - light on a sensor, a finger on a button, or a Twitter message - and turn it into an output - activating a motor, turning on an LED, publishing something online. You can tell your board what to do by sending a set of instructions to the microcontroller on the board. To do so you use the Arduino programming language (based on Wiring), and the Arduino Software (IDE), based on Processing.

<h3> Why Arduino? </h3>

Thanks to its simple and accessible user experience, Arduino has been used in thousands of different projects and applications. The Arduino software is easy-to-use for beginners, yet flexible enough for advanced users. It runs on Mac, Windows, and Linux. Teachers and students use it to build low cost scientific instruments, to prove chemistry and physics principles, or to get started with programming and robotics. Designers and architects build interactive prototypes, musicians and artists use it for installations and to experiment with new musical instruments. Makers, of course, use it to build many of the projects exhibited at the Maker Faire, for example. Arduino is a key tool to learn new things. Anyone - children, hobbyists, artists, programmers - can start tinkering just following the step by step instructions of a kit, or sharing ideas online with other members of the Arduino community.

Arduino also simplifies the process of working with microcontrollers, but it offers some advantage for teachers, students, and interested amateurs over other systems:

* Inexpensive - Arduino boards are relatively inexpensive compared to other microcontroller platforms. The least expensive version of the Arduino module can be assembled by hand, and even the pre-assembled Arduino modules cost less than \$50

* Cross-platform - The Arduino Software (IDE) runs on Windows, Macintosh OSX, and Linux operating systems. Most microcontroller systems are limited to Windows.

* Simple, clear programming environment - The Arduino Software (IDE) is easy-to-use for beginners, yet flexible enough for advanced users to take advantage of as well. For teachers, it's conveniently based on the Processing programming environment, so students learning to program in that environment will be familiar with how the Arduino IDE works.

* Open source and extensible software - The Arduino software is published as open source tools, available for extension by experienced programmers. The language can be expanded through C++ libraries, and people wanting to understand the technical details can make the leap from Arduino to the AVR C programming language on which it's based. Similarly, you can add AVR-C code directly into your Arduino programs if you want to.

* Open source and extensible hardware - The plans of the Arduino boards are published under a Creative Commons license, so experienced circuit designers can make their own version of the module, extending it and improving it. Even relatively inexperienced users can build the breadboard version of the module in order to understand how it works and save money.

---

<h3> How Do I Use Arduino </h3>

To as to get started: [see this guide](https://www.arduino.cc/en/Guide).

To see project over a variety of them: [projects](https://create.arduino.cc/projecthub).

To see Tutorials: [Tutorial](https://www.arduino.cc/en/Tutorial/HomePage).

To see Arduino Reference: [Read](https://www.arduino.cc/reference/en/).

Arduino playground: [Read](https://playground.arduino.cc/).

---

Now as we got familiar with the Arduino and its concepts and working let's work on the prime objective of this project:

A robotic arm is a type of mechanical arm, usually programmable, with similar functions to a human arm; the arm may be the sum total of the mechanism or may be part of a more complex robot. The links of such a manipulator are connected by joints allowing either rotational motion (such as in an articulated robot) or translational (linear) displacement.The links of the manipulator can be considered to form a kinematic chain. The terminus of the kinematic chain of the manipulator is called the end effector and it is analogous to the human hand. Which is a 6-joint robotic arm.

In the previous project model I controlled it using NRF24L01 which is transreciever and a flex sensor which measured the resistance caused due to bending and acted as a variable resistance and a MPU6050 which has a 3-axis gyroscope which analyzed the yaw, pitch and roll movements with a DMP controller.

But, this time we will control it remotelly using an ESP8266 WiFi module. For this we first need to construct an html interface to control Arduino and ESP82666. To control some servomotors remotely in a wi-fi network, using an ordinary internet browser (Firefox, for instance). This might be used in several applications: toys, robots, drones, camera pan/tilt, other operations as well.

So, you need a robotic arm with 6 joints or you can build one by yourself. 

The following tools and materials were used in this project:

Tools and materials:
* Solder iron and wire. I had to solder some terminals to Nunchuk's wires in order to connect it to the Arduino;
* Shrinking tube. Some pieces of shrinking tube were used for a better isolation of the conductors;
* Screwdriver. The structure is mounted using some bolts and nuts;
* 6-axis mechanical desktop robotic arm. This awesome kit already comes with several components. It's reliable and easy to assemble;
* 12V power supply (2A or more);
* ESP8266-01. It's used as a 'WiFi modem'. It receives signals from the control interface to be performed by the Arduino;
* Male-female jumper wires (5 wires);
* Arduino Mega. 

desktop arm already comes with the following components:

* Arduino Mega 2560 R3 
* Control board shield
* NRF24L01+ Wireless Transceiver Module
* MPU6050 3-axis gyroscope and a 3-axis accelerometer
* 71 x M3X8 screw
* 47 x M3 nut
* 2 x U bracket
* 5 x servo bracket
* 4 x 9kg servo 
* 2 x 20kg servo 
* 6 x metal servo tray
* 3 x U bracket
* 21 x right-angled bracket
* 3 x flange bearing
* 1 x gripper (in the claws of this gripper try attaching some blades so that it can act as an cutter while we are using it for defusing bombs).

The arm should be assembled in this fashion.


<p align="center">
<img src="https://user-images.githubusercontent.com/43617730/103358351-66ec7d80-4adb-11eb-8156-ce24c569a367.png" alt="Browser Controlled Robotic Arm"/>
</p>

---

<h3> Setting Up the Connections </h3>


---

<h3> Block Diagram </h3>

<p align="center">
<img src="https://user-images.githubusercontent.com/72822597/103462209-a6b89c80-4d49-11eb-9d89-8716dbecd4ad.png" alt=""/>
</p>

---

