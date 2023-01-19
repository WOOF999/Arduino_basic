#include <IRremote.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <OzOLED.h>

#define DHTPIN A2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,&Wire,OLED_RESET);

int RECV_PIN=A1;
int Relaypin=8;
int PIRpin=9;
int redPin=6;
int greenPin=5;
int bluePin=4;
int red,green,blue=0;
int count;


bool state = false;
bool State_Relay;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  OzOled.init();

  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(Relaypin,OUTPUT);
}

void loop() {
  int h =dht.readHumidity();
  int t =dht.readTemperature();
  Serial.print("humidity : ");
  Serial.println(h);
  Serial.print("temperature : ");
  Serial.println(t);
  OzOled.printString("*** EDUINO ***",0,0);
  delay(1500);
  OzOled.printString("IoT Smart Home Kit",0,1);
  delay(1500);
  OzOled.printString("humidity : ",0,2);
  OzOled.printString(h);
  delay(1500);
  OzOled.printString("temperature : ",0,3);
  OzOled.printString(t);
  delay(1500);
  OzOled.clearDisplay();

  Serial.println(digitalRead(PIRpin));
  int PirVal=digitalRead(PIRpin);

  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)){
    if(results.value==0xFF6897){
      for (int i =0;i<3;i++){
        digitalWrite(redPin,1);
        delay(200);
        digitalWrite(redPin,0);
        digitalWrite(greenPin,1);
        delay(200);
        digitalWrite(greenPin,0);
        digitalWrite(bluePin,1);
        delay(200);
        digitalWrite(bluePin,0);
      }
      State_Relay =! State_Relay;
      if(State_Relay==0){
        count=0;
      }
    }
    Serial.println(results.value,HEX);
    Serial.println((String)results.value);
    control_LED((String)results.value);
    irrecv.resume();
  }
  digitalWrite(Relaypin,State_Relay);
  if(PirVal==HIGH){
    state=true;
    if(count>1){
      setColor_S(HIGH);
    }
    else{
      setColor_S(LOW);
      if(state==true){
        count++;
        state=false;
      }
    }
  }
  delay(100);
}

void setColor_S(int light){
  digitalWrite(redPin,light);
  digitalWrite(greenPin,light);
  digitalWrite(bluePin,light);
}

void control_LED(String remote_Val){
  if(remote_Val=="16769055"){// "-" 전체 끄기
    red=LOW;
    green=LOW;
    blue=LOW;
  }
  else if(remote_Val=="16754775"){// "+" 전체 켜기
    red=HIGH;
    green=HIGH;
    blue=HIGH;
  }
  else if(remote_Val=="16724175"){// "1" RED ON/OFF
    if(red==HIGH){
      red=LOW;
    }
    else{
      red=HIGH;
    }
    green=LOW;
    blue=LOW;
  }
  else if(remote_Val=="16718055"){// "2" GREEN ON/OFF
    if(green==HIGH){
      green=LOW;
    }
    else{
      green=HIGH;
    }
    red=LOW;
    blue=LOW;
  }
  else if(remote_Val=="16743045"){// "3" BLUE ON/OFF
    if(blue==HIGH){
      blue=LOW;
    }
    else{
      blue=HIGH;
    }
    red=LOW;
    green=LOW;
  }
  else if(remote_Val=="16748655"){// "EQ" 점멸 후 ON
    for(int i=0;i<5;i++){
      red=LOW;
      green=LOW;
      blue=LOW;
      setColor(red,green,blue);
      delay(250);
      red=HIGH;
      green=HIGH;
      blue=HIGH;
      setColor(red,green,blue);
      delay(400);
    }
    
  }
  setColor(red,green,blue);
}
void setColor(int red, int green, int blue){
  digitalWrite(redPin,red);
  digitalWrite(greenPin,green);
  digitalWrite(bluePin,blue);
}
