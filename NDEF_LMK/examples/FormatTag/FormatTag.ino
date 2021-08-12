// Formats a Mifare Classic tags as an NDEF tag
// This will fail if the tag is already formatted NDEF
// nfc.clean will turn a NDEF formatted Mifare Classic tag back to the Mifare Classic format

#include <Wire.h>
#include <PN532_I2C_LMK.h>
#include <PN532_LMK.h>
#include <NfcAdapter_LMK.h>

PN532_I2C_LMK pn532_i2c(Wire);
NfcAdapter_LMK nfc = NfcAdapter_LMK(pn532_i2c);

void setup(void) {
    Serial.begin(9600);
    Serial.println("NDEF Formatter");
    nfc.begin();
}

void loop(void) {
    
    Serial.println("\nPlace an unformatted Mifare Classic tag on the reader.");
    if (nfc.tagPresent()) {

        bool success = nfc.format();
        if (success) {
          Serial.println("\nSuccess, tag formatted as NDEF.");
        } else {
          Serial.println("\nFormat failed.");
        }

    }
    delay(5000);
}