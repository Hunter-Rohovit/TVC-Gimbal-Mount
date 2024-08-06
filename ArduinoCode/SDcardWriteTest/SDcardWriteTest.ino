#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("\nInitializing SD card...");

  if (!SD.begin(10)) {
    Serial.println("\ninitialization failed!");
    while (1);
  }
  Serial.println("\ninitialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test3.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("\nWriting to test2.txt...");
    myFile.println("testing 1, 2, 3.");
    myFile.println("\ntesting 1, 2, 3.");
    myFile.println("\ntesting 1, 2, 3.");
    // close the file:
    myFile.close();
    Serial.println("\ndone.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("\nerror opening test2.txt");
  }
}
void loop(){}
