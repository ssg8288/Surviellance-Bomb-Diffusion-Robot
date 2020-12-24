#include <SPI.h>

#include <RH_NRF24.h>

#include "I2Cdev.h"

#include "MPU6050_6Axis_MotionApps20.h"


#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE

#include "Wire.h"

#endif



MPU6050 mpu;

RH_NRF24 nrf24;

String inputString = "";

String encodedString = "";

boolean stringComplete = false;



bool dmpReady = false; // set true if DMP init was successful

uint8_t mpuIntStatus; // holds actual interrupt status byte from MPU

uint8_t devStatus; // return status after each device operation (0 = success, !0 = error)

uint16_t packetSize; // expected DMP packet size (default is 42 bytes)

uint16_t fifoCount; // count of all bytes currently in FIFO

uint8_t fifoBuffer[64]; // FIFO storage buffer



// orientation/motion vars

Quaternion q; // [w, x, y, z] quaternion container

VectorFloat gravity; // [x, y, z] gravity vector

float ypr[3]; // [yaw, pitch, roll] yaw/pitch/roll container and gravity vector



double movingAngleOffset = 0.1;



double yawD, rollD, flexValD;

int yaw, roll, flexVal;



volatile bool mpuInterrupt = false; // indicates whether MPU interrupt pin has gone high

void dmpDataReady()

{

mpuInterrupt = true;

}

void setup()

{

Serial.begin(115200);

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE

Wire.begin();

TWBR = 24; // 400kHz I2C clock (200kHz if CPU is 8MHz)

#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE

Fastwire::setup(400, true);

#endif

mpu.initialize();

mpu.testConnection();

devStatus = mpu.dmpInitialize();



mpu.setXGyroOffset(220);

mpu.setYGyroOffset(76);

mpu.setZGyroOffset(-85);

mpu.setZAccelOffset(1788);



if (devStatus == 0)

{

mpu.setDMPEnabled(true);

attachInterrupt(0, dmpDataReady, RISING);

mpuIntStatus = mpu.getIntStatus();

dmpReady = true;

packetSize = mpu.dmpGetFIFOPacketSize();

}

else

{

Serial.print(F("DMP Initialization failed (code "));

Serial.print(devStatus);

Serial.println(F(")"));

}

if (!nrf24.init())

Serial.println("init failed");

if (!nrf24.setChannel(1))

Serial.println("setChannel failed");

if (!nrf24.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))

Serial.println("setRF failed");

}





void loop()

{

if (!dmpReady) return;

while (!mpuInterrupt && fifoCount < packetSize)

{



}

mpuInterrupt = false;

mpuIntStatus = mpu.getIntStatus();

fifoCount = mpu.getFIFOCount();

if ((mpuIntStatus & 0x10) || fifoCount == 1024)

{

mpu.resetFIFO();

Serial.println(F("FIFO overflow!"));

}

else if (mpuIntStatus & 0x02)

{

while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

mpu.getFIFOBytes(fifoBuffer, packetSize);

fifoCount -= packetSize;

flexValD = analogRead(A0);

mpu.dmpGetQuaternion(&q, fifoBuffer);

mpu.dmpGetGravity(&gravity, &q);

mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

yawD = ypr[1] * 180/M_PI + 180;

rollD = ypr[2] * 180/M_PI + 180;

yaw = (int)yawD / 3;

roll = (int)rollD /3;

if(flexValD > 600){

flexVal = 0;

}else{

flexVal = 1;

}

inputString = (String)yaw + (String)roll + (String)flexVal;

Serial.println(inputString);

nrf24.send((const unsigned char *)inputString.c_str(),sizeof(inputString));

nrf24.waitPacketSent();

}

delay(10);

}
