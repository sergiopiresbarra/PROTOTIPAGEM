#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f,2,1,0,4,5,6,7,3, POSITIVE);
#include <dht.h>
Adafruit_BMP085 bmp180;
#define dht_dpin A1
int mostrador = 0;
dht DHT;
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);
  if (!bmp180.begin()) 
  {
    Serial.println("Sensor nao encontrado !!");
    while (1) {}
  }
}
  
void loop() 
{   
   DHT.read11(dht_dpin);
  Serial.print("Umidade = ");
  Serial.print(DHT.humidity);
  Serial.print(" %  ");
  Serial.print("Temperatura = ");
  Serial.print(DHT.temperature); 
  Serial.println(" Celsius  ");
  
   lcd.setCursor(0, 0);
   lcd.print("Temp. :  ");
   Serial.print("Temperatura : ");
   if ( bmp180.readTemperature() < 10)
   {
     lcd.print(" "); 
     lcd.print(bmp180.readTemperature());
     Serial.print(bmp180.readTemperature());
     Serial.println(" C");
   }
   else
   {
     lcd.print(bmp180.readTemperature(),1);
     Serial.print(bmp180.readTemperature(),1);
     Serial.println(" C");
   }
   lcd.print(" ");
   lcd.print((char)223); 
   lcd.print("C   ");
      
   if (mostrador == 0)
   {
     lcd.setCursor(0, 1);
     lcd.print("                ");
     lcd.setCursor(0, 1);
     lcd.print("Humi. : ");
     lcd.print(DHT.humidity);
     lcd.print(" %");  
    }
   if (mostrador == 1)
   {
     lcd.setCursor(0, 1);
     lcd.print("                ");
     lcd.setCursor(0, 1);
     lcd.print("Press.: ");
     Serial.print("Pressao : ");
     lcd.print(bmp180.readPressure());  
     Serial.print(bmp180.readPressure());  
     Serial.println(" Pa");
     lcd.print(" Pa");
   }
   
   delay(3000);
   mostrador = !mostrador;
}
