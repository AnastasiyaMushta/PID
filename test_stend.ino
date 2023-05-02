#include <Servo.h>

Servo myservo;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  pinMode(A4, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A6, INPUT);
  pinMode(A0, INPUT_PULLUP);

  digitalWrite(2, 1);

  digitalWrite(3, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 1);

  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(12, 0);

  digitalWrite(A4, 0);
  digitalWrite(A3, 0);
  digitalWrite(A2, 0);
  digitalWrite(A1, 0);

  Serial.begin(115200);
  printHead();
  myservo.attach(11);

  myservo.write(0);

}

float Pe = 0;
float Ie = 0;
float De = 0;
float e0 = 0;

float k1 =  0.1;
float k2 =  0.001;
float k3 = -1;

float val0 = 128;
float val1 = 0;
float val = 0;

void printHead()
{
  Serial.print("val");
  Serial.print(" ");
  Serial.print("val0");
  Serial.print(" ");
  Serial.print("val1");
  Serial.print(" ");
//  Serial.print("Pe");
//  Serial.print(" ");
//  Serial.print("Ie");
//  Serial.print(" ");
//  Serial.print("De");
  Serial.print("\n");
}

void printAll()
{
  Serial.print(val);
  Serial.print(" ");
  Serial.print(val0);
  Serial.print(" ");
  Serial.print(val1);
  Serial.print(" ");
//  Serial.print(Pe);
//  Serial.print(" ");
//  Serial.print(Ie);
//  Serial.print(" ");
//  Serial.print(De);
  Serial.print("\n");
}

void loop()
{
  val1 = analogRead(A6) / 6;
  Pe =  val0 - val1;
  Ie += Pe;
  De = Pe - e0; e0 = Pe;
  val = k1 * Pe + k2 * Ie + k3 * De;
  myservo.write(val);
  printAll();  
  delay(15);
}
