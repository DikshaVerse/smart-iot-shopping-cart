#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

int totalPrice = 0;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  Serial.println("RFID Smart Cart Ready");
}

void loop() {

  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("Card UID: ");

  String content = "";

  for (byte i = 0; i < mfrc522.uid.size; i++) {
    content += String(mfrc522.uid.uidByte[i], HEX);
  }

  Serial.println(content);

  if (content == "a1b2c3") {
    totalPrice += 50;
    Serial.println("Item added: Product A - ₹50");
  }

  else if (content == "d4e5f6") {
    totalPrice += 30;
    Serial.println("Item added: Product B - ₹30");
  }

  Serial.print("Total Price: ");
  Serial.println(totalPrice);

  delay(2000);
}
