#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);
String perintah;

void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
}
void loop() {
  while (BT.available()) {
    delay(10);
    char c = BT.read();
    perintah += c;
  }
  if (perintah.length() > 0) {
    Serial.println(perintah);

    if (perintah == "hidupkan sepeda motor")
    {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
    }
    if (perintah == "matikan sepeda motor")
    {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
    }
    else if (perintah == "hidupkan mesin")
    {
      digitalWrite(4, LOW);
      delay (1000);
      digitalWrite(4, HIGH);
    }

    else if (perintah == "buka kunci stang")
    {
      digitalWrite(5, LOW);
    }
    else if (perintah == "tutup kunci stang")
    {
      digitalWrite(5, HIGH);
    }

    perintah = "";
  }
}
