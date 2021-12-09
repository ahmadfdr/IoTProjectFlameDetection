#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0X27, 16, 2);
int Api;
const int FlamePin = 12;
const int BuzzerPin = 13;
const int redLED = 2;
const int yellowLED = 3;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(FlamePin, INPUT);
  pinMode(BuzzerPin, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  lcd.setBacklight(HIGH);
  
  Api = digitalRead(FlamePin);

  if (Api == LOW)
  { 
    lcd.clear();
    delay(500);
    lcd.setCursor(1,0);
    lcd.print("PERINGATAN");
    lcd.setCursor(1,1);
    lcd.print("ADA API!!!!!!");
    Serial.println("ADA API!!!!"); 
    digitalWrite(BuzzerPin, HIGH);
    delay(100);
    digitalWrite(BuzzerPin, LOW);
    delay(100);
    digitalWrite(BuzzerPin, HIGH);
    delay(100);
    digitalWrite(BuzzerPin, LOW);
    delay(100);
    digitalWrite(BuzzerPin, HIGH);
    delay(100);
    digitalWrite(BuzzerPin, LOW);
    delay(100);
    digitalWrite(BuzzerPin, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
    delay(500);
    digitalWrite(redLED, LOW);
    delay(500);
    digitalWrite(redLED, HIGH);
    delay(500);
    digitalWrite(redLED, LOW);
    delay(500);
    digitalWrite(redLED, HIGH);
    delay(500);
  }
  else
  {
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("TIDAK ADA API");
    Serial.println("TIDAK ADA API!!!!"); 
    delay(500);
    digitalWrite(BuzzerPin, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED,LOW);
  }
}
