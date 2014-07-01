
void readTag(String &tagReturnString){
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
  uint8_t uidLength;
  String hexReturnString;
  String tmpTagString;
  
  if (nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength)){
    for (int i = 0; i < uidLength; i++){
      printHex(uid[i], hexReturnString);

      tmpTagString += hexReturnString;

      if (i == uidLength - 1){ 
        tagReturnString = tmpTagString;
      } else {
        tmpTagString += ":";
      }
    }  
  }
}

void printHex(int num, String &hexString) {
      char tmp[16];
      char format[128];
 
      sprintf(format, "%%.%dX", 2);
      sprintf(tmp, format, num);
 
      hexString = tmp;
}
