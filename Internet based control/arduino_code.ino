int forward_pin=2;
int left_pin=12;
int right_pin=10;
int backward_pin=9;

#define Left_motor_A 3 // Left motor H bridge, input A
#define Left_motor_B 11 // Left motor H bridge, input B
#define Right_motor_A 5 // Right motor H bridge, input A
#define Right_motor_B 6 // Right motor H bridge, input B
#define v 255

#include <Servo.h>

int pos = 0;
// the setup routine runs once when you press reset:
void setup() {

pinMode(forward_pin,INPUT); // initialize serial communication at 9600 bits per second:
pinMode(left_pin,INPT);
pinMode(right_pin,INPUT);
pinMode(backward_pin,INPUT);
Serial.begin(9600);
digitalWrite(forward_pin,LOW);
digitalWrite(left_pin,LOW);
digitalWrite(right_pin,LOW);
digitalWrite(backward_pin,LOW);

//288000
// this is different on the serial monitor not sure if it is up or down
// Serial.begin(14400);
}
int lls=0;
int rls=0;
int al=0;
// the loop routine runs over and over again forever:
void loop() {
// read the input on analog pin 0:
int sensorValue1 = digitalRead(forward_pin);
int sensorValue2 = digitalRead(left_pin);
int sensorValue3 = digitalRead(right_pin);
int sensorValue4 = digitalRead(backward_pin);
// print out the value you read:
Serial.print(sensorValue1);
Serial.print(" : ");
Serial.print(sensorValue2);
Serial.print(" : ");
Serial.print(sensorValue3);
Serial.print(" : ");
Serial.println(sensorValue4);
delay(25); // delay in between reads for stability

if (sensorValue1 == 1) {
analogWrite(Right_motor_A,0);
analogWrite(Right_motor_B,120);
analogWrite(Left_motor_A,0);
analogWrite(Left_motor_B,120);
delay (500);
analogWrite(Right_motor_A,0);
analogWrite(Right_motor_B,0);
analogWrite(Left_motor_A,0);
analogWrite(Left_motor_B,0);
// myservo.write(10);
// delay (500);
}
else{
analogWrite(Right_motor_A,0);
analogWrite(Right_motor_B,0);
analogWrite(Left_motor_A,0);
analogWrite(Left_motor_B,0);
}
if (sensorValue2 == 1) {
// digitalWrite(led, HIGH);
analogWrite(Right_motor_A,0);
analogWrite(Right_motor_B,250);
analogWrite(Left_motor_A,250);
analogWrite(Left_motor_B,0);
delay (100);
analogWrite(Right_motor_A,0);
analogWrite(Right_motor_B,0);
analogWrite(Left_motor_A,0);
analogWrite(Left_motor_B,0);
// myservo.write(10);
// delay (500);
}
else
{
analogWrite(Right_motor_A,0);
analogWrite(Right_motor_B,0);
analogWrite(Left_motor_A,0);
analogWrite(Left_motor_B,0);
}
if (sensorValue4 == 1) {
// digitalWrite(led, HIGH);
analogWrite(Right_motor_A,250);
analogWrite(Right_motor_B,0);
analogWrite(Left_motor_A,0);
analogWrite(Left_motor_B,250);
delay (100);
analogWrite(Right_motor_A,0);
analogWrite(Right_motor_B,0);
analogWrite(Left_motor_A,0);
analogWrite(Left_motor_B,0);
// myservo.write(10);
// delay (500);
}
else
{
analogWrite(Right_motor_A,0);
analogWrite(Right_motor_B,0);
analogWrite(Left_motor_A,0);
analogWrite(Left_motor_B,0);
}
if (sensorValue3 == 1) {
// digitalWrite(led, HIGH);
analogWrite(Right_motor_A,120);
analogWrite(Right_motor_B,0);
analogWrite(Left_motor_A,120);
analogWrite(Left_motor_B,0);
delay (500);
analogWrite(Right_motor_A,0);
analogWrite(Right_motor_B,0);
analogWrite(Left_motor_A,0);
analogWrite(Left_motor_B,0);
// myservo.write(10);
// delay (500);
}
else
{
analogWrite(Right_motor_A,0);
analogWrite(Right_motor_B,0);
analogWrite(Left_motor_A,0);
analogWrite(Left_motor_B,0);
}
}


server.show(“”);
// remote control for rover
ledState <- 0;
function blink()
{
// Change state
ledState = ledState?0:1;
server.log("ledState val: "+ledState);
// Reflect state to the pin
hardware.pin9.write(ledState);
}
// input class for LED control channel
class inputHTTP extends InputPort
{
name = “power control”
type = “number”
function set(httpVal)
{
server.log("Received val: "+httpVal);
if(httpVal == 1) {
hardware.pin9.write(1);
imp.sleep(0.1);
hardware.pin9.write(0);
}
else if(httpVal == 2) {
hardware.pin8.write(1);
imp.sleep(0.1);
hardware.pin8.write(0);
}
else if(httpVal == 3) {
hardware.pin2.write(1);
imp.sleep(0.1);
hardware.pin2.write(0);
}
else if(httpVal == 4) {
hardware.pin1.write(1);
imp.sleep(0.1);
hardware.pin1.write(0);
}
else{
;
} } }
function watchdog() {
imp.wakeup(60,watchdog);
server.log(httpVal);
}

hardware.pin9.configure(DIGITAL_OUT_OD_PULLUP);
hardware.pin8.configure(DIGITAL_OUT_OD_PULLUP);
hardware.pin2.configure(DIGITAL_OUT_OD_PULLUP);
hardware.pin1.configure(DIGITAL_OUT_OD_PULLUP);
// Register with the server
imp.configure(“Reomote Control for Rover”, [inputHTTP()], []);