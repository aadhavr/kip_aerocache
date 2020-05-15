#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 9, 4, 5, 6, 3);



int pin = 8;

unsigned long duration;

unsigned long starttime;

unsigned long sampletime_ms = 30000;    //30 SECONDS

unsigned long lowpulseoccupancy = 0;    //TIME SPENT IN LOW STATE OF PWM

float ratio = 0;

float concentration = 0;

void setup() {

    Serial.begin(9600);
    lcd.begin(18,2);
    
    pinMode(pin,INPUT);
    
    starttime = millis();   //GETS CURRENT TIME
    
    Serial.print("Low Pulse Occupancy");
    Serial.print(",  ");
    Serial.print("Ratio");
    Serial.print(", ");
    Serial.println("Concentration");
}

void loop() {
    duration = pulseIn(pin, LOW);
    
    lowpulseoccupancy += duration;

    if ((millis()-starttime) > sampletime_ms) {
        
        ratio = lowpulseoccupancy/(sampletime_ms*10.0);   //CONVERTS TIME SPENT IN LOW STATE TO %
        
        concentration = 1.1 * pow(ratio,3) - 3.8 * pow(ratio,2) + 520 * ratio + 0.62;  // IF x IS RATIO, THEN y = 1.1 *​x^​3-​3.8*​x^​2+​520*​x+​0.62            


        lcd.setCursor(0, 0);
        lcd.print("PM10 ");
        lcd.setCursor(6, 0);
        lcd.print(concentration, 3);
        
        Serial.print(lowpulseoccupancy);
        Serial.print(", ");
        Serial.print(ratio);
        Serial.print(", ");
        Serial.println(concentration);


        if (concentration < 1000) {
         
          lcd.setCursor (0, 1);
         
          for (int i = 0; i < 16; ++i)    //ALLOWS TEXT TO APPEAR CENTERED; VALUE SUBJECT TO CHANGE
             {
                lcd.write(' ');
             }

          lcd.setCursor(4, 1);
          lcd.print("CLEAN");
    
        }
        else if (concentration >= 1000 && concentration < 10000) {
    
          lcd.setCursor (0, 1);
         
          for (int i = 0; i < 16; ++i)
            {
                lcd.write(' ');
            }
         
          lcd.setCursor(4, 1);
          lcd.print("GOOD");
         
        }
        else if (concentration >= 10000 && concentration < 20000) {
    
          lcd.setCursor (0, 1);
        
          for (int i = 0; i < 16; ++i)
            {
                lcd.write(' ');
            }
          
          lcd.setCursor(4, 1);
          lcd.print("ACCEPTABLE");
    
        }
        
        if (concentration >= 20000 && concentration < 50000) {
        
          lcd.setCursor (0, 1);
          
          for (int i = 0; i < 16; ++i)
            {
                lcd.write(' ');
            }
               
          lcd.setCursor(4, 1);
          lcd.print("HEAVY");
         
        }
    
        if (concentration >= 50000 ) {
          
          lcd.setCursor (0, 1);
          
          for (int i = 0; i < 16; ++i)
            {
                lcd.write(' ');
            }
          
          lcd.setCursor(4, 1);
          lcd.print("HAZARD");
        
        } 

        
        lowpulseoccupancy = 0;
        starttime = millis();
    }
}
