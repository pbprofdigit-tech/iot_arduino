#include <SD.h>

File myFile;

void setup() {
  // put your setup code here, to run once:

  if (!SD.begin(4)) {
   while (1);
  }


  myFile = SD.open("test.txt", FILE_WRITE);
  myFile.print("Riga 1");
  myFile.print("Riga 2");
  myFile.print("Riga 3");
  myFile.print("Riga 4");
  myFile.print("Riga 5");
  myFile.close();

}

void loop() {
  // put your main code here, to run repeatedly:
  myFile = SD.open("test.txt", FILE_WRITE);
  myFile.println("Loop 1");
  myFile.println("Loop 2");
  myFile.println("Loop 3");
  myFile.println("Loop 4");
  myFile.println("Loop 5");
  myFile.close();

  delay(5000);  
}
