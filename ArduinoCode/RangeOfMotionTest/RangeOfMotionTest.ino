#include <Servo.h>

Servo servo1;
Servo servo2;  

int pos;
int pos2;
int zeroPos = 28;
int zeroPos2 = 78;
int maxPos = 43;
int maxPos2 = 83;
int minPos = 13;
int minPos2 = 63;
int dlay = 5;
int radiusX = 15;
int radiusY = 5;

void setup() {
  //Servo Setup
  servo1.attach(9);
  servo2.attach(8);
  servo1.write(zeroPos);
  servo2.write(zeroPos2);
  delay(1000);
 
 //tvcCode();
 //fourCorners();

 /*for(int i = 0; i<4; i++){
    circularMotion();
  }
  servo1.write(zeroPos);
  servo2.write(zeroPos2);*/


}

void loop() {
 //tvcCode(); 
 //circularMotion();
fourCorners();
delay(2000);
servo1.write(zeroPos);
  servo2.write(zeroPos2);
  delay(3000);

/*servo1.write(zeroPos);
  servo2.write(zeroPos2);
  delay(3000);*/


}
void tvcCode(){
  //Range of Motion Test
  //Oscillates between max and min positions
  //First is X-axis (Upper Servo)
  //Second is Y-axis (Lower Servo)
  for(pos=zeroPos; pos<=maxPos; pos+=1)
  {
    servo1.write(pos);
    delay(dlay);
  }
  for(pos=maxPos; pos>=minPos; pos-=1)
  {
    servo1.write(pos);
    delay(dlay);
  }
  for(pos=minPos; pos<=zeroPos; pos+=1)
  {
    servo1.write(pos);
    delay(dlay);
  }

  for(pos2=zeroPos2; pos2<=maxPos2; pos2+=1)
  {
    servo2.write(pos2);
    delay(dlay);
  }
  for(pos2=maxPos2; pos2>=minPos2; pos2-=1)
  {
    servo2.write(pos2);
    delay(dlay);
  }
  for(pos2=minPos2; pos2<=zeroPos2; pos2+=1)
  {
    servo2.write(pos2);
    delay(dlay);
  }
}

void circularMotion() {
  for (int i = 0; i < 360; i += 1) {
    int xPos = zeroPos + radiusX * cos(radians(i));
    int yPos = zeroPos2 + radiusY * sin(radians(i));
    
    servo1.write(xPos);
    servo2.write(yPos);
    delay(dlay);
  }
}

void fourCorners(){
  servo1.write(maxPos);
  servo2.write(maxPos2);
  delay(400);
  servo1.write(minPos);
  delay(400);
  servo2.write(minPos2);
  delay(400);
  servo1.write(maxPos);
  delay(400);

}
