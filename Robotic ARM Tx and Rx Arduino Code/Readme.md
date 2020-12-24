<h3> Wireless Hand Gesture Robotic Arm </h3>

---

<p align="center"> Controller/Transmitter Wiring </p>




* Control A Robotic Arm Wirelessly Using a Glove With Flex and Motion Sensors

---

* NRF24 Wiring:

* VCC - 3.3V (or use an adapter for 5V, like I did)

* GND - GND

* CE - D8

* CSN - D10

* SCK - D13

* MOSI - D11

* MISO - D12

* IRQ - N/C

---

* MPU6050 Wiring:

* VCC - 5V

* GND - GND

* SDA - A4

* SCL - A5

* INT - D2

---

<p align="center"> Robotic Arm Wiring: </p>

* All VCC - 5V (separate from the Arduino power)

* All GND - GND (power source GND and Arduino GND should be connected)

* Base Servo Control - D3

* Arm Extend Control - D6 and D9 (had to combine because of DOF of controller and wireless data constraints)

* Grip Control - D5

---

* NRF24 Wiring:

* VCC - 3.3V (or use an adapter for 5V, like I did)

* GND - GND

* CE - D8

* CSN - D10

* SCK - D13

* MOSI - D11

* MISO - D12

* IRQ - N/C

---

### Make Sure you used these following header files in your arduino code.

>>SPI.h

>>RH_NRF24.h

>>"I2Cdev.h"

>>"MPU6050_6Axis_MotionApps20.h"

>>I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE

>>"Wire.h"

---

<h3> Circuit Diagram </h3>

<h5> ARM Tx </h5>

![sensor](https://user-images.githubusercontent.com/43617730/103088166-f42d5f00-460f-11eb-8627-39b03dfb8256.jpg)

<h5> ARM Rx </h5>

![servo](https://user-images.githubusercontent.com/43617730/103088216-2212a380-4610-11eb-8c9d-3dc17bea8958.jpg)

<h3> Block Diagram </h3>

![bdh](https://user-images.githubusercontent.com/43617730/103088430-ceed2080-4610-11eb-91cc-633919adacb0.jpg)
