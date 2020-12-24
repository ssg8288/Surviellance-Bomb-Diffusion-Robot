/*Wireless Hand Gesture Robotic Arm

* Receiver Code


*

* Control A Robotic Arm Wirelessly Using a Glove With Flex and Motion Sensors

*

* Robotic Arm Wiring:

* All VCC - 5V (separate from the Arduino power)

* All GND - GND (power source GND and Arduino GND should be connected)

* Base Servo Control - D3

* Arm Extend Control - D6 and D9 (had to combine because of DOF of controller and wireless data constraints)

* Grip Control - D5

*

* NRF24 Wiring:

* VCC - 3.3V (or use an adapter for 5V, like I did)

* GND - GND

* CE - D8

* CSN - D10

* SCK - D13

* MOSI - D11

* MISO - D12

* IRQ - N/C

*/

#include <SPI.h>

#include <RH_NRF24.h>



int servoBase = 3;

int servoGrip = 5;

int servoExt1 = 6;

int servoExt2 = 9;



RH_NRF24 nrf24;

int yaw, roll, grip;

double posBase, posExt, posGrip;

String receivedString;



void setup()

{

pinMode(servoBase, OUTPUT);

pinMode(servoGrip, OUTPUT);

pinMode(servoExt1, OUTPUT);

pinMode(servoExt2, OUTPUT);



servoWrite(1500, servoBase);

servoWrite(1000, servoGrip);

servoWrite(1500, servoExt1);

servoWrite(1500, servoExt2);





Serial.begin(9600);

if (!nrf24.init())

Serial.println("init failed");

if (!nrf24.setChannel(1))

Serial.println("setChannel failed");

if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))

Serial.println("setRF failed");

}



void loop()

{

if (nrf24.available())

{

uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];

uint8_t len = sizeof(buf);

if (nrf24.recv(buf, &len)){

receivedString = (char*)buf;

receivedString.remove(6);

//Serial.println(receivedString);

yaw = receivedString.substring(0,2).toInt();

roll = receivedString.substring(2,4).toInt();

grip = receivedString.substring(4,5).toInt();

Serial.print(yaw);

Serial.print(" ");

Serial.print(roll);

Serial.print(" ");

Serial.println(grip);

posBase = roll*8.33333*2;

posExt = yaw*8.333333*2;

servoWrite(posBase, servoBase);

servoWrite(posExt, servoExt2);

servoWrite(posExt, servoExt1);

if(grip == 1){

posGrip = 1000;

}else{

posGrip = 2000;

}

servoWrite(posGrip, servoGrip);

}

else{

Serial.println("recv failed");

}

}

}

void servoWrite(double pulseWidth, int servo){

digitalWrite(servo, HIGH);

delayMicroseconds(pulseWidth);

digitalWrite(servo, LOW);

}
