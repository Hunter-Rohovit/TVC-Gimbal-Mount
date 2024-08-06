#include "HX711.h"

//L1 (6,7) = 394.86
//L2(2,3) = -393.09
//L3(4,5) = 392.33
#define calibration_factor_1 394.86
#define calibration_factor_2 393.09
#define calibration_factor_3 392.33

#define LOADCELL_1_DOUT_PIN  6
#define LOADCELL_1_SCK_PIN  7

#define LOADCELL_2_DOUT_PIN  5
#define LOADCELL_2_SCK_PIN  4

#define LOADCELL_3_DOUT_PIN  3
#define LOADCELL_3_SCK_PIN  2

HX711 LoadPoint1;
HX711 LoadPoint2;
HX711 LoadPoint3;

void setup() {
  Serial.begin(9600);
  Serial.println("LoadPointMeasurements");

  LoadPoint1.begin(LOADCELL_1_DOUT_PIN, LOADCELL_1_SCK_PIN);
  LoadPoint1.set_scale(calibration_factor_1); 

  LoadPoint2.begin(LOADCELL_2_DOUT_PIN, LOADCELL_2_SCK_PIN);
  LoadPoint2.set_scale(calibration_factor_2);

  LoadPoint3.begin(LOADCELL_3_DOUT_PIN, LOADCELL_3_SCK_PIN);
  LoadPoint3.set_scale(calibration_factor_3);
  Serial.println("Beginning Tare: ");
  LoadPoint1.tare();
  LoadPoint2.tare();
  LoadPoint3.tare();

  Serial.println("Readings:");
  int i=0;
  while(i<800){
    Serial.print("Load 1: ");
    Serial.print(LoadPoint1.get_units(), 1); 
    Serial.print(" g"); 
    Serial.print("________________");
    Serial.print("Load 2: ");
    Serial.print(LoadPoint2.get_units(), 1); 
    Serial.print(" g"); 
    Serial.print("________________");
    Serial.print("Load 3: ");
    Serial.print(LoadPoint3.get_units(), 1); 
    Serial.print(" g"); 
    Serial.print("________________");
    Serial.println();
    i++;
  }
}

void loop() {
  
}
