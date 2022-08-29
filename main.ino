#include <LiquidCrystal.h
#define trigger 10
#define echo 11
#define motor 12
#define buzzer 3
LiquidCrystal lcd(9,8,7,6,5,4);
float time=0.0,distance=0.0;
int temp = 0;
void setup() {
lcd.begin(16,2);
pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
pinMode(motor, OUTPUT);
pinMode(buzzer, OUTPUT);
lcd.print(" Water Level ");
lcd.setCursor(0,1);
lcd.print(" Indicator ");
delay(2000);
}
void loop()
{
 lcd.clear();
digitalWrite(trigger,LOW);
delayMicroseconds(2);
digitalWrite(trigger,HIGH);
delayMicroseconds(10);
digitalWrite(trigger,LOW);
delayMicroseconds(2);
time=pulseIn(echo,HIGH);
distance=time*340.0/20000.0;
lcd.clear();
lcd.print("Water Space In ");
lcd.setCursor(0,1);
lcd.print("Tank is: ");
lcd.print(distance);
lcd.print("Cm");
delay(500);
if(distance<5 && temp == 0)
{
 digitalWrite(motor, LOW);
 digitalWrite(buzzer, HIGH);
 lcd.clear();
 lcd.print("distance:");
lcd.print(distance);
 lcd.setCursor(0,1);
 lcd.print("Motor Turned OFF");
 delay(2000);
 digitalWrite(buzzer, LOW);
 delay(3000);
 temp = 1;
}
else if(distance<5 && temp == 1)
{
 digitalWrite(motor, LOW);
 digitalWrite(buzzer,LOW );
 lcd.clear();
 lcd.print("distance:");
 lcd.print(distance);
 lcd.setCursor(0,1);
 lcd.print("Motor Turned OFF");
 delay(2000);
 digitalWrite(buzzer, LOW);
 delay(3000);
 }
else if(distance>16)
{
 digitalWrite(motor, HIGH);
 lcd.clear();
 lcd.print("distance");
 lcd.print(distance);
 lcd.setCursor(0,1);
 lcd.print("Motor Turned ON");
 delay(5000);
 temp = 0;
}

}
