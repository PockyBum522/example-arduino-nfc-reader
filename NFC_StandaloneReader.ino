#include <Wire.h>  
#include <Adafruit_NFCShield_I2C.h>  
Adafruit_NFCShield_I2C nfc(2, 3); // Pin 2 is IRQ, Pin 3 is RESET (By default on shield) Pins can be changed here.
void setup(void) {Serial.begin(9600);  pinMode(13, OUTPUT);  nfc.begin();  nfc.SAMConfig();}

String database[][3] = {
//    Friendly Name                                 Tag UID                                 User's First Name
  "David's Left Hand",                       "FE:E2:70:5A",                                      "David",
  "David's Right Hand",                      "FE:E2:70:5A",                             "David"
}; int dbSize = sizeof(database) / sizeof(database[0]);

void loop(void) {
  String tagString;
  readTag(tagString);
  
  for (int dbIndex = 0; dbIndex < dbSize; dbIndex++){
    if (tagString == database[dbIndex][1]) {      
      Serial.print("Read ");  Serial.print(database[dbIndex][2]);  Serial.println("'s tag.");  // This line will only fire if a chip is matched from the DB. Put stuff to do if an authorized chip is presented here.
      break;
    } if (dbIndex == dbSize-1){  
      Serial.print("Unrecognized card: "); Serial.println(tagString);  // This line will only fire if a chip that is NOT in the database is presented. It reads out the UID over serial so you can copy and paste easily into the sketch, if so desired.
    }  
  }
}
