#include <Ultrasonic.h>
#include <Servo.h>
int buzzPin = 4;
int buzzDelay;

#define TRIG 12
#define ECHO 11

Servo nya;
Ultrasonic ultra(TRIG, ECHO);

int a = 0;
int direc = 5;

void buzzKilla(int buzzDelay) {
  digitalWrite(buzzPin, HIGH);
  delay(buzzDelay);
  digitalWrite(buzzPin, LOW);
  delay(buzzDelay);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  nya.attach(9);
  nya.write(0);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  //Distancia en Centimetros
  float cm = ultra.read(CM);
  //Mandar datos
  Serial.print(int(cm));
  Serial.print(",");
  Serial.println(a);

 //Sonido
  if (cm >= 1 && cm <= 10) {
     buzzDelay = 50;
     buzzKilla(buzzDelay);
  } else if (cm >= 11 && cm <= 20) {
     buzzDelay =60 ;
     buzzKilla(buzzDelay);
  } else if (cm >= 21 && cm <= 40) {
     buzzDelay = 70;
     buzzKilla(buzzDelay);
  } else if (cm >= 41 && cm <= 55) {
     buzzDelay = 90;
     buzzKilla(buzzDelay);
  } else if (cm >= 56) {
    buzzDelay = 100;
     buzzKilla(buzzDelay);
  }

  a += direc;
  nya.write(a);

  if (a == 0) direc = 5;
  if (a == 180) direc = -5;
  delay(50);
}
