int val;

int nb;

void setup() {

// setup code here run once:

Serial.begin(9600);

pinMode(9,OUTPUT);

pinMode(8,OUTPUT);

pinMode(7,OUTPUT);

pinMode(6,INPUT);

}

// main code here, to run repeatedly:

void loop()

{
if(Serial.available()>0)

{

int data= Serial.read();

Stop();

if(data=='R')

{

digitalWrite(9,HIGH);

digitalWrite(8,LOW);

digitalWrite(6,HIGH);

digitalWrite(7,LOW);

}

else if(data=='L')

{

digitalWrite(9,LOW);

digitalWrite(8,HIGH);

digitalWrite(6,LOW);

digitalWrite(7,HIGH);

}else if(data=='F'){

digitalWrite(9,LOW);

digitalWrite(8,HIGH);

digitalWrite(6,HIGH);

digitalWrite(7,LOW);

}else if(data=='B'){

digitalWrite(9,HIGH);

digitalWrite(8,LOW);

digitalWrite(6,LOW);

digitalWrite(7,HIGH);

}

}

}

void Stop()

{

digitalWrite(9,LOW);

digitalWrite(8,LOW);

digitalWrite(6,LOW);

digitalWrite(7,LOW);
}
