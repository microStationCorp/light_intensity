#include <IRremote.h>

int sensor = 3;
int out = A1;

IRrecv ip(sensor);
decode_results results;

void setup() {
  Serial.begin(9600);
  ip.enableIRIn();
  pinMode(sensor, INPUT);
  pinMode(out, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (ip.decode(&results))
  {
    switch (results.value)
    {
      case 0x80BF49B6: analogWrite(out, (1000 * 1) / 9);
        break;

      case 0x80BFC936: analogWrite(out, (1000 * 2) / 9);
        break;

      case 0x80BF33CC: analogWrite(out, (1000 * 3) / 9);
        break;

      case 0x80BF718E: analogWrite(out, (1000 * 4) / 9);
        break;

      case 0x80BFF10E: analogWrite(out, (1000 * 5) / 9);
        break;

      case 0x80BF13EC: analogWrite(out, (1000 * 6) / 9);
        break;

      case 0x80BF51AE: analogWrite(out, (1000 * 7) / 9);
        break;

      case 0x80BFD12E: analogWrite(out, (1000 * 8) / 9);
        break;

      case 0x80BF23DC: analogWrite(out, (1000 * 9) / 9);
        break;

      case 0x80BF53AC: analogWrite(out, 1023);
        break;

      case 0x80BF4BB4: analogWrite(out, 0);
        break;
    }
    ip.resume();
    delay(20);
  }
}
