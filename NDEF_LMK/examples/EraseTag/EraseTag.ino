// Erases a NFC tag by writing an empty NDEF message 

#include <Wire.h>
#include <PN532_I2C_LMK.h>
#include <PN532_LMK.h>
#include <NfcAdapter_LMK.h>

PN532_I2C_LMK pn532_i2c(Wire);
NfcAdapter_LMK nfc = NfcAdapter_LMK(pn532_i2c);

void setup(void) {
    Serial.begin(9600);
    Serial.println("NFC Tag Eraser");
    nfc.begin();
}

void loop(void) {
    Serial.println("\nPlace a tag on the NFC reader to erase.");

    if (nfc.tagPresent()) {

        bool success = nfc.erase();
        if (success) {
            Serial.println("\nSuccess, tag contains an empty record.");        
        } else {
            Serial.println("\nUnable to erase tag.");
        }

    }
    delay(5000);
}