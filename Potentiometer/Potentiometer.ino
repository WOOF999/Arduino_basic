int sw=10;
int led_green=2;
int led_yellow=3;
int led_red=4;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_green,OUTPUT);
  pinMode(led_yellow,OUTPUT);
  pinMode(led_red,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int val =analogRead(A1)/4;
  Serial.println(val);
  analogWrite(led_yellow,val);
  analogWrite(led_green,val);
  analogWrite(led_red,val);
}
