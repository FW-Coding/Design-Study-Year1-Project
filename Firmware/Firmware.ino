
// Include Libraries
//#include "Arduino.h"
#include "FSR.h"
//#include "LiquidCrystal.h"


// Pin Definitions
#define FSRSQUARE_PIN_1	A10

bool heavy;
bool stiff;

float maxForce = 0;

// Global variables and defines

// object initialization
FSR fsrSquare(FSRSQUARE_PIN_1);
//LiquidCrystal lcd(7,8,9,10,11,12);


// define vars for testing menu
const int timeout = 100000;       //define timeout of 10 sec
char menuOption = 0;
long time0;
//THRESHOLD
float threshold = 20;
//THRESHOLD
bool aboveT;
int startT = 0;
int finishT = 0;
int totalT = 0;
int constant = 5000;
bool isHard;
bool isHeavy;

void printResult(){
  if (maxForce < 500){
    Serial.println("Soft Light");
    isHard = true;
    isHeavy = false;
  }else if(maxForce < 2000){
    Serial.println("Hard Light");
    isHard = true;
    isHeavy = false;
  } else{
    if(totalT > 7){
      Serial.println("Soft Heavy");
      isHard = false;
      isHeavy = true;
    }else{
      Serial.println("Hard Heavy");
      isHard = true;
      isHeavy = true;
    }
  }
}

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    analogReference(EXTERNAL);
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(115200);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    // set up the LCD's number of columns and rows
    //lcd.begin(16, 2);
    //menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    float fsrSquareForce = fsrSquare.getForce();
    int Force = int(fsrSquareForce); 
    //Serial.println(fsrSquareForce);
    //Serial.print("\t");
    //Serial.println(constant);
      /*if (fsrSquareForce > maxForce){
        maxForce = fsrSquareForce;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Max Force: ");
        lcd.print(int(maxForce));
      }*/
      if (fsrSquareForce > threshold){
        if (aboveT == false){
          aboveT = true;
          startT = int(millis());
          Serial.println("Above threshold");
        }
        if (fsrSquareForce > maxForce){
          public:
          
          maxForce = fsrSquareForce;

        }
      }
      else{
          if (aboveT == true){;
            finishT = int(millis());
            totalT = finishT - startT;
            aboveT = false;
  //          lcd.setCursor(1, 1);
  //          lcd.print("Time: ");
  //          lcd.print(totalT);
            Serial.println("Below Threshold");
            Serial.print("Max Force:");
            Serial.println(maxForce);
            Serial.print("Time: ");
            Serial.println(totalT);
            printResult();
            maxForce = 0;
            delay(1000);
          }
        }
        
    if (millis() - time0 > timeout)
    {
        return;
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
/*
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) Force Sensitive Resistor - Square"));
    Serial.println(F("(2) LCD 16x2"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing Force Sensitive Resistor - Square"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing LCD 16x2"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}

/*******************************************************

*    Circuito.io is an automatic generator of schematics and code for off
*    the shelf hardware combinations.

*    Copyright (C) 2016 Roboplan Technologies Ltd.

*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*    In addition, and without limitation, to the disclaimers of warranties 
*    stated above and in the GNU General Public License version 3 (or any 
*    later version), Roboplan Technologies Ltd. ("Roboplan") offers this 
*    program subject to the following warranty disclaimers and by using 
*    this program you acknowledge and agree to the following:
*    THIS PROGRAM IS PROVIDED ON AN "AS IS" AND "AS AVAILABLE" BASIS, AND 
*    WITHOUT WARRANTIES OF ANY KIND EITHER EXPRESS OR IMPLIED.  ROBOPLAN 
*    HEREBY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT 
*    NOT LIMITED TO IMPLIED WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT, AND THOSE ARISING BY 
*    STATUTE OR FROM A COURSE OF DEALING OR USAGE OF TRADE. 
*    YOUR RELIANCE ON, OR USE OF THIS PROGRAM IS AT YOUR SOLE RISK.
*    ROBOPLAN DOES NOT GUARANTEE THAT THE PROGRAM WILL BE FREE OF, OR NOT 
*    SUSCEPTIBLE TO, BUGS, SECURITY BREACHES, OR VIRUSES. ROBOPLAN DOES 
*    NOT WARRANT THAT YOUR USE OF THE PROGRAM, INCLUDING PURSUANT TO 
*    SCHEMATICS, INSTRUCTIONS OR RECOMMENDATIONS OF ROBOPLAN, WILL BE SAFE 
*    FOR PERSONAL USE OR FOR PRODUCTION OR COMMERCIAL USE, WILL NOT 
*    VIOLATE ANY THIRD PARTY RIGHTS, WILL PROVIDE THE INTENDED OR DESIRED
*    RESULTS, OR OPERATE AS YOU INTENDED OR AS MAY BE INDICATED BY ROBOPLAN. 
*    YOU HEREBY WAIVE, AGREE NOT TO ASSERT AGAINST, AND RELEASE ROBOPLAN, 
*    ITS LICENSORS AND AFFILIATES FROM, ANY CLAIMS IN CONNECTION WITH ANY OF 
*    THE ABOVE. 
********************************************************/
