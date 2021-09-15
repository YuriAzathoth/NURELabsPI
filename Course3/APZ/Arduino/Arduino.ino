#include <DHT.h>

#define PIN_DETECTOR 2

DHT dht(PIN_DETECTOR, DHT11);

float h;
float t;

void setup()
{
  pinMode(PIN_DETECTOR, OUTPUT);
  dht.begin();
  Serial.begin(9600);
}

void loop()
{
  delay(1000);

  h = dht.readHumidity();
  t = dht.readTemperature();

  Serial.print("<");
  Serial.print(t);
  Serial.print(";");
  Serial.print(h);
  Serial.print(">");
}
