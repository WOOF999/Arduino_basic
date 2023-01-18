#include <IRremote.h>

int RECV_PIN=11;
int flame=A0;
int LED_R=4;
int LED_B=2;
int val=0;
int temp=0;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(flame,INPUT);
  pinMode(LED_R,OUTPUT);
  pinMode(LED_B,OUTPUT);
}

void loop() {
  val=analogRead(flame);
  if(val>300){
    digitalWrite(LED_R,HIGH);
    digitalWrite(LED_B,LOW);
  }
  else{
    digitalWrite(LED_R,LOW);
    digitalWrite(LED_B,HIGH);
  }


  if(irrecv.decode(&results)){
    Serial.println(results.value,HEX);
    if(results.value==0xFF6897){ 
      while(1){
        digitalWrite(LED_B,LOW);
        digitalWrite(LED_R,LOW);
        irrecv.resume();
        if(irrecv.decode(&results)){
          break;
        }
      }
    }
  }
  irrecv.resume();
}

