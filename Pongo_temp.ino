#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
// 8-as bemenetbe dugd a hőmérő DATA szálát
#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
void setup(void)
{
  Serial.begin(9600);
  Serial.println("DS18B20 Programed by PongoPongo");
  sensors.begin();
   lcd.begin(20,4); //20 karakteres 4 soros kijelző (20,4) / 16 karakteres 2 soros (16,2) (Olyanra rakd amilyen kijelződ van)
    lcd.backlight(); 
  lcd.clear();
  lcd.setCursor(0,0);
}
void loop(void)
{
  sensors.requestTemperatures();
  float x=sensors.getTempCByIndex(0);
   lcd.setCursor(0,0);
    lcd.print("Homerseklet: "); 
      lcd.setCursor(0,1);
      lcd.print("      C"); // (C) = Celsius fok °C
        lcd.setCursor(0,1); 
  lcd.print(x); 

   Serial.print(" "); 
 sensors.requestTemperatures();
 Serial.println(" "); 
/********************************************************************/
 Serial.print("Homerseklet: "); 
 Serial.print(sensors.getTempCByIndex(0));  
   delay(1000); 
}
