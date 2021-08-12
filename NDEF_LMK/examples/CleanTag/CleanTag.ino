// Clean resets a tag back to factory-like state
// For Mifare Classic, tag is zero'd and reformatted as Mifare Classic
// For Mifare Ultralight, tags is zero'd and left empty

#include <Wire.h>
#include <PN532_I2C_LMK.h>
#include <PN532_LMK.h>
#include <NfcAdapter_LMK.h>

PN532_I2C_LMK pn532_i2c(Wire);
NfcAdapter_LMK nfc = NfcAdapter_LMK(pn532_i2c);

void setup(void) {
    Serial.begin(9600);
    Serial.println("NFC Tag Cleaner");
    nfc.begin();
}

void loop(void) {

    Serial.println("\nPlace a tag on the NFC reader to clean.");

    if (nfc.tagPresent()) {

        bool success = nfc.clean();
        if (success) {
            Serial.println("\nSuccess, tag restored to factory state.");
        } else {
            Serial.println("\nError, unable to clean tag.");
        }

    }
    delay(5000);
}
