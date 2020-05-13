#include <LiquidCrystal.h>
LiquidCrystal lcd();

/*
  https://www.arduino.cc/en/Reference/LiquidCrystalConstructor
  
  1. Check if chipset is compatible
  2. Plug in correct parameters

*/


int pin = 8;

unsigned long duration;

unsigned long starttime;

unsigned long sampletime_ms = 30000;    //30 SECONDS

unsigned long lowpulseoccupancy = 0;    //TIME SPENT IN LOW STATE OF PWM

float ratio = 0;

float concentration = 0;

void setup() {

    Serial.begin(9600);
    
    pinMode(pin,INPUT);
    
    starttime = millis();   //GETS CURRENT TIME
    
    Serial.print("Low Pulse Occupancy");
    Serial.print(" | ");
    Serial.print("Ratio");
    Serial.print(" | ");
    Serial.println("Concentration");
}

void loop() {
    duration = pulseIn(pin, LOW);
    
    lowpulseoccupancy += duration;

    if ((millis()-starttime) > sampletime_ms) {
        
        ratio = lowpulseoccupancy/(sampletime_ms*10.0);   //CONVERTS TIME SPENT IN LOW STATE TO %
        
        concentration = 1.1 * pow(ratio,3) - 3.8 * pow(ratio,2) + 520 * ratio + 0.62;  // if x is ratio, then y = 1.1*​x^​3-​3.8*​x^​2+​520*​x+​0.62            


        lcd.setCursor(0, 0);
        lcd.print("PM10 ");
        lcd.setCursor(6, 0);
        lcd.print(concentration1,3);
        
        Serial.print(lowpulseoccupancy);
        Serial.print(", ");
        Serial.print(ratio);
        Serial.print(", ");
        Serial.println(concentration);


        if (concentration1 < 1000) {
         
          lcd.setCursor (0, 1);
         
//          for (int i = 0; i < 16; ++i)
//             {
//                lcd.write(' ');
//             }

          lcd.setCursor(4, 1);
          lcd.print("CLEAN");
    
        }
        else if (concentration1 >= 1000 && concentration1 < 10000) {
    
          lcd.setCursor (0, 1);
         
//          for (int i = 0; i < 16; ++i)
//            {
//                lcd.write(' ');
//            }
         
          lcd.setCursor(4, 1);
          lcd.print("GOOD");
         
        }
        else if (concentration1 >= 10000 && concentration1 < 20000) {
    
          lcd.setCursor (0, 1);
        
//          for (int i = 0; i < 16; ++i)
//            {
//                lcd.write(' ');
//            }
          
          lcd.setCursor(4, 1);
          lcd.print("ACCEPTABLE");
    
        }
        
        if (concentration1 >= 20000 && concentration1 < 50000) {
        
          lcd.setCursor (0, 1);
          
//          for (int i = 0; i < 16; ++i)
//            {
//                lcd.write(' ');
//            }
               
          lcd.setCursor(4, 1);
          lcd.print("HEAVY");
         
        }
    
        if (concentration1 >= 50000 ) {
          
          lcd.setCursor (0, 1);
          
//          for (int i = 0; i < 16; ++i)
//            {
//                lcd.write(' ');
//            }
          
          lcd.setCursor(4, 1);
          lcd.print("HAZARD");
        
        } 

        
        lowpulseoccupancy = 0;
        starttime = millis();
    }
}
