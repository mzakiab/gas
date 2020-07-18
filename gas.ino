/*
 * Ini adalah sistem untuk mengesan kehadiran gas dalam
 * kandungan udara sekeliling. Ia menggunakan sensor MQ-9
 * dan terdapat 2 LED indicator. HIJAU - Keadaan normal 
 * dan MERAH - Terdapat gas dalam kandungan udara 
 * sekeliling. Ia juga dilengkapi dengan LCD Display 
 * 16 x 2 untuk mempamerkan bacaan kandungan gas.
 * 
 * Videonya di: https://youtu.be/e96hMi42EaM
 * 
 * Ditulis oleh:
 * 9W2KEY OJ15dx
 * July, 2020
 */
 
#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>

LiquidCrystal_PCF8574 lcd(0x27);

int pinRedLed = 11;
int pinGreenLed = 8;
int pinSensor = A0;
int THRESHOLD = 100;


void setup() {
pinMode (pinRedLed, OUTPUT);
pinMode (pinGreenLed, OUTPUT);
pinMode (pinSensor, INPUT);
Serial.begin (9600);
while (!Serial)

Wire.begin();
Wire.beginTransmission(0x27);
lcd.begin(16,2);

lcd.setBacklight(255);
lcd.setCursor(0,0);
lcd.print("  Pengesan gas");
lcd.setCursor(0,1);
lcd.print("  Oleh: 9W2KEY");
delay(3000);
lcd.clear();
delay(1000);
lcd.setCursor(0,0);
lcd.print("LED: HIJAU-OKAY!");
lcd.setCursor(0,1);
lcd.print("Bawah nilai 100");
delay(3000);
lcd.clear();
delay(1000);
lcd.setCursor(0,0);
lcd.print("LED: MERAH-AWAS!");
lcd.setCursor(0,1);
lcd.print("ADA GAS BOCOR!!!");
delay(5000);
lcd.clear();

lcd.setCursor(0,0);
lcd.print("Sistem bermula:");
lcd.setCursor(0,1);
lcd.print(">");
delay(500);
lcd.print(">");
delay(300);
lcd.print(">");
delay(1000);
lcd.print(">");
delay(500);
lcd.print(">");
delay(10);
lcd.print(">");
delay(500);
lcd.print(">");
delay(300);
lcd.print(">");
delay(1000);
lcd.print(">");
delay(500);
lcd.print(">");
delay(1000);
lcd.clear();
}

void loop() {
int analogValue = analogRead (pinSensor);
Serial.println ("Val: " + String(analogValue));

// lcd.setBacklight(255);
lcd.setCursor(0,0);
lcd.print("Bacaan tahap gas");
lcd.setCursor(0,1);
lcd.print("< 9W2KEY >  " + String(analogValue));

if (analogValue >= THRESHOLD) {
digitalWrite (pinGreenLed, LOW);
digitalWrite (pinRedLed, HIGH);
}
else {
digitalWrite (pinRedLed, LOW);
digitalWrite (pinGreenLed, HIGH);
}
delay (500); 
lcd.clear();
}
