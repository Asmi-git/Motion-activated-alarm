#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int pirLeftPin = 2;
const int pirRightPin = 3;
const int buzzerPin = 8;
const int ledLeftPin = 4;
const int ledRightPin = 5;

bool motionLeftDetected = false;
bool motionRightDetected = false;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(pirLeftPin, INPUT);
  pinMode(pirRightPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledLeftPin, OUTPUT);
  pinMode(ledRightPin, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.print("Motion System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {

  if (digitalRead(pirLeftPin) == HIGH) {
    if (!motionLeftDetected) {
      tone(buzzerPin, 1000); 
      digitalWrite(ledLeftPin, HIGH);
      lcd.clear();
      lcd.print("Motion: LEFT");
      motionLeftDetected = true;
    }
  } else {
    if (motionLeftDetected) {
      noTone(buzzerPin);
      digitalWrite(ledLeftPin, LOW);
      motionLeftDetected = false;
    }
  }

  if (digitalRead(pirRightPin) == HIGH) {
    if (!motionRightDetected) {
      tone(buzzerPin, 1000); 
      digitalWrite(ledRightPin, HIGH);
      lcd.clear();
      lcd.print("Motion: RIGHT");
      motionRightDetected = true;
    }
  } else {
    if (motionRightDetected) {
      noTone(buzzerPin); 
      digitalWrite(ledRightPin, LOW);
      motionRightDetected = false;
    }
  }

  delay(100); 
}