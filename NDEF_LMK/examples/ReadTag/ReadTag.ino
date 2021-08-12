#include <Wire.h>
#include <PN532_I2C_LMK.h>
#include <PN532_LMK.h>
#include <NfcAdapter_LMK.h>

PN532_I2C_LMK pn532_i2c(Wire);
NfcAdapter_LMK nfc = NfcAdapter_LMK(pn532_i2c);

void setup(void) {
    Serial.begin(9600);
    Serial.println("NDEF Reader");
    nfc.begin();
}

void loop(void) {
    Serial.println("\nScan a NFC tag\n");
    if (nfc.tagPresent())
    {
        NfcTag tag = nfc.read();
        tag.print();
    }
    delay(5000);
}