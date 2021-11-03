#include <Wire.h>
#include "DS1307.h"

/*
  Schematics:
  ds1307:
  GND - GND
  VCC - 5V DC
  SDA - Arduino A4 Pin
  SCL - Arduino A5 Pin

  Relay:
  GND - GND
  VCC - 5V DC
  S - D2 (if other please adjust RELAY_PIN)
*/

#define RELAY_PIN 2

struct TimeInterval {
  int startTime;
  int endTime;
};


#define QUANTITY_OF_INTERVALS 4
TimeInterval intervals[QUANTITY_OF_INTERVALS] = { {1600, 1700}, {1730, 2100}, {2130, 2359}, {0, 600} };


DS1307 clock;//define a object of DS1307 class

void setup()
{
  Serial.begin(9600);
  
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  
  
  Serial.println("Starting Simple Arduino Outlet");
  Serial.println("Current time:");
  clock.begin();
  
  
  printTime();

}

void loop()
{
  Serial.println("Verifing time");
  if(shouldEnableRelay()){
    Serial.println("Enabling Relay");
    digitalWrite(RELAY_PIN, HIGH);
  }
  else{
    Serial.println("Disabling Relay");
    digitalWrite(RELAY_PIN, LOW);  
  }

  sleepForHalfHour();
}

bool shouldEnableRelay()
{
    clock.getTime();
    int current_time = clock.hour * 100 + clock.minute;

    for(int i = 0; i < QUANTITY_OF_INTERVALS; i++)
      if(current_time >= intervals[i].startTime && current_time <= intervals[i].endTime)
        return true;
    
    return false;
}

void sleepForHalfHour()
{
  for(int i = 0; i < 225; i++) {
    delay(8000);
  }
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
