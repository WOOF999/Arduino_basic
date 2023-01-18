int sw=10;
int led_yello=3;
int led_green=2;
int led_red=4;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_yello,OUTPUT);
  pinMode(led_green,OUTPUT);
  pinMode(led_red,OUTPUT);
  pinMode(sw,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  for(int color=2;color<5;color++){
    if(digitalRead(sw)==LOW){
      color=2;
    }
    turn_on_led(color);
  }
}
void turn_on_led(int color){
  digitalWrite(color,HIGH);
  switch(color){
    case 2:
      delay(3000);
      digitalWrite(color,LOW);
      break;
    case 3:
      delay(1000);
      digitalWrite(color,LOW);
      break;
    case 4:
      delay(3000);
      digitalWrite(color,LOW);
      break;
  }

}

