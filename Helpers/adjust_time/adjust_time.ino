#include <Wire.h>
#include "DS1307.h"

/*
  Schematics:
  ds1307:
  GND - GND
  VCC - 5V DC
  SDA - Arduino A4 Pin
  SCL - Arduino A5 Pin
  
*/

DS1307 clock;//define a object of DS1307 class
void setup()
{
    Serial.begin(9600);
    Serial.println("Starting clock");
    clock.begin();
    Serial.println("Printing time: (hh:mm dd/MM/yyyy)");
    /*
    clock.fillByYMD(2021, 11, 02); //year, month, day
    clock.fillByHMS(22, 12, 50);  //hh:mm ss"
    clock.fillDayOfWeek(TUE); //MON, TUE, WED, THU, FRI, SAT or SUN
    clock.setTime();// write time to the RTC chip
    */

    printTime();
}
void loop()
{
    
}
    /*Function: Display time on the serial monitor*/
void printTime()
{
    clock.getTime();
    Serial.print(clock.hour, DEC);
    Serial.print(":");
    Serial.print(clock.minute, DEC);
    Serial.print(":");
    Serial.print(clock.second, DEC);
    Serial.print("  ");
    Serial.print(clock.dayOfMonth, DEC);
    Serial.print("/");
    Serial.print(clock.month, DEC);
    Serial.print("/");
    Serial.print(clock.year+2000, DEC);
    Serial.print(" - ");

    switch (clock.dayOfWeek)// Friendly printout the weekday
    {
        case MON:
        Serial.print("MON");
        break;
        case TUE:
        Serial.print("TUE");
        break;
        case WED:
        Serial.print("WED");
        break;
        case THU:
        Serial.print("THU");
        break;
        case FRI:
        Serial.print("FRI");
        break;
        case SAT:
        Serial.print("SAT");
        break;
        case SUN:
        Serial.print("SUN");
        break;
    }
    Serial.println(" ");
}
