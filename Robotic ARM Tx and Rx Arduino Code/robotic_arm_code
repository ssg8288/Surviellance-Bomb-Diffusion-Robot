// Browser controlled robotic arm by Igor Fonseca Albuquerque

//Include libraries
#include <Servo.h>

//define variables
#define DEBUG true //display ESP8266 messages on Serial Monitor
#define SERV1 8    //servo 1 on digital port 8
#define SERV2 9    //servo 2 on digital port 9
#define SERV3 10   //servo 3 on digital port 10
#define SERV4 11   //servo 4 on digital port 11
#define SERV5 12   //servo 5 on digital port 12
#define SERV6 13   //servo 6 on digital port 13

Servo s1; //servo 1
Servo s2; //servo 2
Servo s3; //servo 3
Servo s4; //servo 4
Servo s5; //servo 5
Servo s6; //servo 6

//define starting angle for each servo
//choose a safe position to start from
//it will try to move instantaniously to that position when powered up!
//those angles will depend on the angle of each servo during the assemble
int angle1 = 90; //servo 1 current angle
int angle2 = 30; //servo 2 current angle
int angle3 = 0;  //servo 3 current angle
int angle4 = 90; //servo 4 current angle
int angle5 = 90; //servo 5 current angle
int angle6 = 45; //servo 6 current angle
int servo_speed = 6; //speed of the servos

int angle1sp = 90; //servo 1 set point
int angle2sp = 30; //servo 2 set point
int angle3sp = 0;  //servo 3 set point
int angle4sp = 90; //servo 4 set point
int angle5sp = 90; //servo 5 set point
int angle6sp = 45; //servo 6 set point

boolean display_angles = true; //boolean used to update the angle of each servo on Serial Monitor

//SETUP
void setup() {
    //attach each servo to a pin and start its position
    s1.attach(SERV1);
    s1.write(angle1);
    s2.attach(SERV2);
    s2.write(angle2);
    s3.attach(SERV3);
    s3.write(angle3);
    s4.attach(SERV4);
    s4.write(angle4);
    s5.attach(SERV5);
    s5.write(angle5);
    s6.attach(SERV6);
    s6.write(angle6);

    //start serial communication
    Serial.begin(9600);
    Serial.println("Connecting...");
    Serial3.begin(9600);

    //Wi-Fi connection 
    sendData("AT+RST\r\n", 2000, DEBUG); //reset module
    sendData("AT+CWMODE=1\r\n", 1000, DEBUG); //set station mode
    sendData("AT+CWJAP=\"XXXXX\",\"YYYYY\"\r\n", 2000, DEBUG);   //connect wifi network
    while(!Serial3.find("OK")) { //wait for connection
    } 
    sendData("AT+CIFSR\r\n", 1000, DEBUG); //show IP address
    sendData("AT+CIPMUX=1\r\n", 1000, DEBUG); //allow multiple connections
    sendData("AT+CIPSERVER=1,80\r\n", 1000, DEBUG); // start web server on port 80
}

void loop() {  

  if (Serial3.available())  //check if there is data available on ESP8266
    {
    if (Serial3.find("+IPD,")) //if there is a new command
      {
        String msg;
        Serial3.find("?"); //run cursor until command is found
        msg = Serial3.readStringUntil(' '); //read the message
        String command = msg.substring(0, 3); //command is informed in the first 3 characters. "srs" = command to move the six servos
        String valueStr1 = msg.substring(4, 7);   //next 3 characters inform the desired angle
        String valueStr2 = msg.substring(8,11);   //next 3 characters inform the desired angle
        String valueStr3 = msg.substring(12,15);   //next 3 characters inform the desired angle
        String valueStr4 = msg.substring(16,19);   //next 3 characters inform the desired angle
        String valueStr5 = msg.substring(20,23);   //next 3 characters inform the desired angle
        String valueStr6 = msg.substring(24,27);   //next 3 characters inform the desired angle
        int angle1sp = valueStr1.toInt();         //convert to integer
        int angle2sp = valueStr2.toInt();         //convert to integer
        int angle3sp = valueStr3.toInt();         //convert to integer
        int angle4sp = valueStr4.toInt();         //convert to integer
        int angle5sp = valueStr5.toInt();         //convert to integer
        int angle6sp = valueStr6.toInt();         //convert to integer
        
        if (DEBUG) { //print received command
          Serial.print(command);
          Serial.print(": ");
          Serial.print(angle1sp);
          Serial.print(", ");
          Serial.print(angle2sp);
          Serial.print(", ");
          Serial.print(angle3sp);
          Serial.print(", ");
          Serial.print(angle4sp);
          Serial.print(", ");
          Serial.print(angle5sp);
          Serial.print(", ");
          Serial.println(angle6sp);
        }
      }
    }               

  if (angle1 > angle1sp) {
    angle1 -= 1;
    s1.write(angle1);
  }
  if (angle1 < angle1sp) {
    angle1 += 1;
    s1.write(angle1);
  }

  if (angle2 > angle2sp) {
    angle2 -= 1;
    s2.write(angle2);
  }
  if (angle2 < angle2sp) {
    angle2 += 1;
    s2.write(angle2);
  }

  if (angle3 > angle3sp) {
    angle3 -= 1;
    s3.write(angle3);
  }
  if (angle3 < angle3sp) {
    angle3 += 1;
    s3.write(angle3);
  }

  if (angle4 > angle4sp) {
    angle4 -= 1;
    s4.write(angle4);
  }
  if (angle4 < angle4sp) {
    angle4 += 1;
    s4.write(angle4);
  }

  if (angle5 > angle5sp) {
    angle5 -= 1;
    s5.write(angle5);
  }
  if (angle5 < angle5sp) {
    angle5 += 1;
    s5.write(angle5);
  }

  if (angle6 > angle6sp) {
    angle6 -= 1;
    s6.write(angle6);
  }
  if (angle6 < angle6sp) {
    angle6 += 1;
    s6.write(angle6);
  }

  delay(100/servo_speed);

}


//********************
// Auxiliary functions
//********************

//send data to ESP8266
String sendData(String command, const int timeout, boolean debug)
{
  String response = "";
  Serial3.print(command);
  long int time = millis();
  while ( (time + timeout) > millis())
  {
    while (Serial3.available())
    {
      char c = Serial3.read();
      response += c;
    }
  }
  if (debug)
  {
    Serial.print(response);
  }
  return response;
}
