//Main code
#include <Wire.h>  
#include <Adafruit_GFX.h>  
#include <Adafruit_SSD1306.h>  
#include <Fonts/FreeMonoBold12pt7b.h>  
#define OLED_SDA 20  
#define OLED_SCL 21  
#define OLED_RESET –1

//Setup Oled display
Adafruit_SSD1306 display(128, 64, &Wire);  

//Traffic lights LED module 
const int LED_R1 = 2; 
const int LED_Y1 = 3; 
const int LED_G1 = 4;  
const int LED_R2 = 8;  
const int LED_Y2 = 9;  
const int LED_G2 = 10;  

//Setup temprature sensor
int val;  
int TempPin = A0; 

//Setup pressure sensor
const int pressureSensorPin = A1;  
const int minPressure = 0;  
const int maxPressure = 1023;  
const int redThreshold = 100;  
 
void setup() {  
  pinMode(LED_R1, OUTPUT);  
  pinMode(LED_Y1, OUTPUT);  
  pinMode(LED_G1, OUTPUT);  
  pinMode(LED_R2, OUTPUT);  
  pinMode(LED_Y2, OUTPUT);  
  pinMode(LED_G2, OUTPUT);  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  display.clearDisplay();  
  display.setTextColor(WHITE);  
  display.setTextSize(1);  
  display.setCursor(0, 0);  
  display.setFont(&FreeMonoBold12pt7b);  
  display.display();  
}  
 
void loop() {  
  int pressureValue = analogRead(pressureSensorPin);  
  val = analogRead(TempPin);  
  float mv = (val / 1024.0) * 5000;  
  float cel = mv / 10; 
  
 //Conditional change due to increase in pressure 
  if (pressureValue >= redThreshold) {  
    analogWrite(LED_R1, 255);  
    analogWrite(LED_Y1, 0);  
    analogWrite(LED_G1, 0);  
    analogWrite(LED_R2, 255);  
    analogWrite(LED_Y2, 0);  
    analogWrite(LED_G2, 0);  
    display.clearDisplay();  
    display.setCursor(25, 32);  
    display.setTextSize(1);  
    display.println("STOP");  
    display.setCursor(10, 48);  
    display.setTextSize(1);  
    display.print("T:");  
    display.print(cel);  
    display.print("*C");  
    display.display(); 
    delay(3000);  
    
 //Otherwise the normal traffic lights loop 
  } else {  
    analogWrite(LED_R1, 0);  
    analogWrite(LED_Y1, 0);  
    analogWrite(LED_G1, 255);  
    analogWrite(LED_R2, 255);  
    analogWrite(LED_Y2, 0);  
    analogWrite(LED_G2, 0);  
    display.clearDisplay();  
    display.setCursor(25, 32);  
    display.setTextSize(1);  
    display.println("STOP");  
    display.setCursor(10, 48);  
    display.setTextSize(1);  
    display.print("T:"); 
    display.print(cel);  
    display.print("*C");  
    display.display();  
    delay(5000);  
 
    analogWrite(LED_R1, 0);  
    analogWrite(LED_Y1, 255);  
    analogWrite(LED_G1, 0);  
    analogWrite(LED_R2, 0);  
    analogWrite(LED_Y2, 255);  
    analogWrite(LED_G2, 0);  
    delay(2000);  
 
    analogWrite(LED_R1, 255);  
    analogWrite(LED_Y1, 0);  
    analogWrite(LED_G1, 0);  
    analogWrite(LED_R2, 0);  
    analogWrite(LED_Y2, 0);  
    analogWrite(LED_G2, 255);  
    display.clearDisplay();  
    display.setCursor(25, 32);  
    display.setTextSize(1);  
    display.println("STOP");  
    display.setCursor(10, 48);  
    display.setTextSize(1);  
    display.print("T:");  
    display.print(cel);  
    display.print("*C"); 
    display.display();  
    delay(5000);  
 
    analogWrite(LED_R1, 0);  
    analogWrite(LED_Y1, 255);  
    analogWrite(LED_G1, 0);  
    analogWrite(LED_R2, 0);  
    analogWrite(LED_Y2, 255);  
    analogWrite(LED_G2, 0);  
    delay(2000); 
 
    analogWrite(LED_R1, 255);  
    analogWrite(LED_Y1, 0);  
    analogWrite(LED_G1, 0);  
    analogWrite(LED_R2, 255);  
    analogWrite(LED_Y2, 0);  
    analogWrite(LED_G2, 0);  
    display.clearDisplay();  
    display.setCursor(25, 32);  
    display.setTextSize(1);  
    display.println("WALK");  
    display.setCursor(10, 48);  
    display.setTextSize(1);  
    display.print("T:");  
    display.print(cel);  
    display.print("*C");  
    display.display();  
    delay(5000); 
  }  
}
