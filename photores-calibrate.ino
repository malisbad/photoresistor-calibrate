/*
 * This program is meant to calibrate photoresistors with a few at a time to save time.
 * The delay is to smooth out the response between each photoresistor.
 */

const int photo0 = A0;
const int photo1 = A1;
const int photo2 = A2;
const int photo3 = A3;
const int photo4 = A4;
const int photo5 = A5;

const int led0 = 5;
const int led1 = 6;
const int led2 = 7;
const int led3 = 11;
const int led4 = 12;
const int led5 = 13; 

int resistors[] = { photo0, photo1, photo2, photo3, photo4, photo5 };
int leds[] = { led0, led1, led2, led3, led4, led5 };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  while (!Serial) {
    ; // wait for initialization
  }

  for (byte i = 0; i < (sizeof(leds)); i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int resistance = 0;
  int results[] = { 0, 0, 0, 0, 0, 0 };
  const int resultSize = sizeof(resistors) / sizeof(resistors[0]);
  
  for (byte i = 0; i < resultSize; i++) {
    digitalWrite(leds[i], HIGH);
    delay(1500);
    resistance = analogRead(resistors[i]);
    results[i] = resistance;
    digitalWrite(leds[i], LOW);
    delay(500);
  }

  Serial.print("[");
  for (byte j = 0; j < resultSize; j++) {
    Serial.print(results[j]);
    if (j != resultSize - 1) {
      Serial.print(",");
    }
  }
  Serial.println("]");
}
