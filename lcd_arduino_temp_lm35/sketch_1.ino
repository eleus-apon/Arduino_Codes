#include <LiquidCrystal.h>

LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
 
const int LED_RED=10;
const int LED_GREEN=11;
 
const int up_key=3;
const int down_key=2;
 
int SetPoint=30;

void setup(){
  pinMode(LED_RED,OUTPUT);
  pinMode(LED_GREEN,OUTPUT);  
  pinMode(up_key,INPUT);
  pinMode(down_key,INPUT);
  
  digitalWrite(up_key,HIGH);
  digitalWrite(down_key,HIGH); 

  lcd.begin(16, 2);
  lcd.setCursor(0,1);
  lcd.print("Temp. Controller");
  digitalWrite(LED_GREEN,HIGH);  
  digitalWrite(LED_RED,LOW);        
  delay(2000);
}

void loop(){
  double Temperature = ((5.0/1024.0) * analogRead(A0)) * 100; 
 
  lcd.setCursor(0,0);
  lcd.print("Temperature:");  
  lcd.print(Temperature);
  
  if(digitalRead(down_key)==LOW)
  {
    if(SetPoint>0)
    {
      SetPoint--;    
    }
  }
  if(digitalRead(up_key)==LOW)
  {
    if(SetPoint<150)
    {
      SetPoint++;
    }
  }
 
  lcd.setCursor(0,1);
  lcd.print("Set Point:");
  lcd.print(SetPoint);
  lcd.print("C   ");
 
if(Temperature > SetPoint)
{
   digitalWrite(LED_RED,HIGH);
   digitalWrite(LED_GREEN,LOW); 
}
else
{
  digitalWrite(LED_GREEN,HIGH);
  digitalWrite(LED_RED,LOW); 
}
 
  delay(100);
}
