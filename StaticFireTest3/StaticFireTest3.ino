#include <Servo.h>
#include "HX711.h"
#include <SPI.h>
#include <SD.h>

#define calibration_factor_1 398.12
#define calibration_factor_2 390.59
#define calibration_factor_3 392.31

#define LOADCELL_1_DOUT_PIN  6
#define LOADCELL_1_SCK_PIN  7

#define LOADCELL_2_DOUT_PIN  5
#define LOADCELL_2_SCK_PIN  4

#define LOADCELL_3_DOUT_PIN  3
#define LOADCELL_3_SCK_PIN  2

Servo servo1;
Servo servo2;  

HX711 LoadPoint1;
HX711 LoadPoint2;
HX711 LoadPoint3;

File file1;

int pos;
int pos2;
int zeroPos = 28;
int zeroPos2 = 73;
int maxPos = 43;
int maxPos2 = 81;
int minPos = 13;
int minPos2 = 66;
int dlay = 5;
const int buzzer = 14;

void setup() {
  pinMode(buzzer, OUTPUT);
  tone(buzzer, 1000);
  delay(100);
  noTone(buzzer);
  
  Serial.begin(9600);
  while (!Serial) {
  }
  Serial.print("\nInitializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("\nInitialization failed!");
    while (1);
  }
  Serial.println("\nInitialization done.");

  file1 = SD.open("Test3.txt", FILE_WRITE);
  if (file1) {
    Serial.println("\nFile opened successfully.");
    delay(1000);

    servo1.attach(9);
    servo2.attach(8);
    servo1.write(zeroPos);
    servo2.write(zeroPos2);

    LoadPoint1.begin(LOADCELL_1_DOUT_PIN, LOADCELL_1_SCK_PIN);
    LoadPoint1.set_scale(calibration_factor_1); 

    LoadPoint2.begin(LOADCELL_2_DOUT_PIN, LOADCELL_2_SCK_PIN);
    LoadPoint2.set_scale(calibration_factor_2);

    LoadPoint3.begin(LOADCELL_3_DOUT_PIN, LOADCELL_3_SCK_PIN);
    LoadPoint3.set_scale(calibration_factor_3);
    delay(10);
    terminalCount();
  } else {
    Serial.println("\nError opening Test1.txt");
  }
}

void loop() {
}

void terminalCount() {
  for (int i = 0; i < 30; i++) {
    tone(buzzer, 1000);
    delay(100);
    noTone(buzzer);
    delay(900);
  }
  file1.println("Setting TVC to zero positions...");
  delay(500);
  servo1.write(zeroPos);
  servo2.write(zeroPos2);
  file1.println("Beginning Tare...");
  LoadPoint1.tare();
  LoadPoint2.tare();
  LoadPoint3.tare();
  delay(1000);
  file1.println("Continuing with final countdown...");
  for (int i = 10; i > 0; i--) {
    tone(buzzer, 5000);
    delay(100);
    noTone(buzzer);
    delay(900);
    file1.println("T-" + String(i));
  }

  tone(buzzer, 5000);
  file1.println("Ignition");
  delay(1000);
  noTone(buzzer);
  file1.println("Force in Newtons: ");

  int i = 0;
  int t = 0;
  while (true) {
    if (i == 800) {
      break;
    }
    //Multiply by 0.009807 to convert from gram-force to Newtons
    float force1 = 0.009807*LoadPoint1.get_units();
    float force2 = 0.009807*LoadPoint2.get_units();
    float force3 = 0.009807*LoadPoint3.get_units();

    //Code for gimabling TVC mount to extreme vector positions (four corners)
    if(force1 >1 || force2>1 || force3>1){
      t++;
    }
    if(t > 20 && t<50){
      servo1.write(maxPos);
      servo2.write(maxPos2);
    }
    if(t > 50 && t<70){
      servo1.write(minPos);
    }
    if(t > 70 && t<90){
      servo2.write(minPos2);
    }
    if(t > 90 && t<110){
      servo1.write(maxPos);
    }
    if(t > 110){
      servo1.write(zeroPos);
      servo2.write(zeroPos2);
    }


    file1.print(force1, 10);
    file1.print(" ");
    file1.print(force2, 10);
    file1.print(" ");
    file1.print(force3, 10);
    file1.print(" \n");
    i++;
  }
  file1.close();
  Serial.println("Data written to file.");
  tone(buzzer, 1000);
  delay(100);
  noTone(buzzer);
}



