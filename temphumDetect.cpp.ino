#include <dht.h>

#include <LiquidCrystal.h>

#define DHT11_PIN 7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;
float prevTemp = 0.00;
float prevHum = 0.00;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);

}

void loop() {
  // put your main code here, to run repeatedly:
  int readData = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0);
  lcd.print("HUM: ");
  lcd.setCursor(0,1);
  lcd.print("TEMP: ");

  float temp = DHT.temperature;
  float hum = DHT.humidity;

  if(temp != prevTemp){
    lcd.setCursor(6,1);
    lcd.print(temp);
    lcd.print((char)223);
    lcd.print("C");
    prevTemp = temp;
  }
  if(hum != prevHum){
    lcd.setCursor(5,0);
    lcd.print(hum);
    lcd.print("%");
    prevHum = hum;
  }

  delay(2000);
}
