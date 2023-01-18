int R=7;
int G=6;
int B=5;

void setup() {
  // put your setup code here, to run once:
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(R,255),analogWrite(G,0),analogWrite(B,0);
  delay(1000);
  analogWrite(R,255),analogWrite(G,50),analogWrite(B,0);
  delay(1000);
  analogWrite(R,255),analogWrite(G,120),analogWrite(B,0);
  delay(1000);
  analogWrite(R,0),analogWrite(G,255),analogWrite(B,0);
  delay(1000);
  analogWrite(R,0),analogWrite(G,0),analogWrite(B,255);
  delay(1000);
  analogWrite(R,0),analogWrite(G,0),analogWrite(B,90);
  delay(1000);
  analogWrite(R,130),analogWrite(G,0),analogWrite(B,130);
  delay(1000);
}
