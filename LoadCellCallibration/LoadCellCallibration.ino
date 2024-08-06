#include "HX711.h"

const int LOADCELL1_DT = 6;
const int LOADCELL2_DT = 5;
const int LOADCELL3_DT = 3;
const int LOADCELL1_SCK = 7;
const int LOADCELL2_SCK = 4;
const int LOADCELL3_SCK = 2;

HX711 loadPoint1;
HX711 loadPoint2;
HX711 loadPoint3;

void setup() {
  //Load Cell Setup
  Serial.begin(9600);
  loadPoint1.begin(LOADCELL1_DT, LOADCELL1_SCK);
  loadPoint2.begin(LOADCELL2_DT, LOADCELL2_SCK);
  loadPoint3.begin(LOADCELL3_DT, LOADCELL3_SCK);
  //Servo Setup
}

void loop() {
  //Callibrating the Scale

  //Callibratiing LoadCell1
  /*if (loadPoint1.is_ready()) {
      loadPoint1.set_scale();    
      Serial.println("Tare... remove any weights from the scale.");
      delay(10000);
      loadPoint1.tare();
      Serial.println("Tare done...");
      Serial.print("Place a known weight on the scale...");
      delay(10000);
      long reading = loadPoint1.get_units(10);
      Serial.print("Load Point 1 Result: ");
      Serial.println(reading);
    } 
    else {
      Serial.println("HX711 LoadPoint1 not found.");
    }
    delay(10000);

    //Callibratiing LoadCell2
   if (loadPoint2.is_ready()) {
      loadPoint2.set_scale();    
      Serial.println("Tare... remove any weights from the scale.");
      delay(10000);
      loadPoint2.tare();
      Serial.println("Tare done...");
      Serial.print("Place a known weight on the scale...");
      delay(10000);
      long reading = loadPoint2.get_units(10);
      Serial.print("LoadPoint2 Result: ");
      Serial.println(reading);
    } 
    else {
      Serial.println("HX711 LoadPoint2 not found.");
    }
    delay(10000);*/

    //Callibratiing LoadCell3
   if (loadPoint3.is_ready()) {
      loadPoint3.set_scale();    
      Serial.println("Tare... remove any weights from the scale.");
      delay(10000);
      loadPoint3.tare();
      Serial.println("Tare done...");
      Serial.print("Place a known weight on the scale...");
      delay(10000);
      long reading = loadPoint3.get_units(10);
      Serial.print("Load Point 3 Result: ");
      Serial.println(reading);
    } 
    else {
      Serial.println("HX711 LoadPoint3 not found.");
    }
    delay(10000);

  

}


