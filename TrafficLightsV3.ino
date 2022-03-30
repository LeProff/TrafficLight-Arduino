#include <IRremote.hpp>

int LED_PIN = 0;
int RECV_PIN = 7;
int SEND_PIN = 12;
bool power = false;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(SEND_PIN, OUTPUT);
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  digitalWrite(LED_PIN, HIGH);
}

void loop()
{
  if (IrReceiver.decode())
  {
    if (IrReceiver.decodedIRData.decodedRawData != 0) {
        // Serial.print("Hex: ");
        // Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); //As HEX 
        // Serial.print("Int: ");
        // Serial.println(IrReceiver.decodedIRData.decodedRawData); //As Int
        switch(IrReceiver.decodedIRData.decodedRawData){     
          case 0xBF40FF00:
            Serial.println("OK");
            digitalWrite(SEND_PIN, HIGH);
            break;
          case 0xE916FF00:
            Serial.println("ONE");
            break;
          case 0xE619FF00:
            Serial.println("TWO");
            break;
          case 0xF20DFF00:
            Serial.println("THREE");
            break;
          case 0xF30CFF00:
            Serial.println("FOUR");
            break;
          case 0xE718FF00:
            Serial.println("FIVE");
            break;
          case 0xA15EFF00:
            Serial.println("SIX");
            break;
          case 0xF708FF00:
            Serial.println("SEVEN");
            break;
          case 0xE31CFF00:
            Serial.println("EIGHT");
            break;
          case 0xA55AFF00:
            Serial.println("NINE");
            break;
          case 0xAD52FF00:
            Serial.println("ZERO");
            break;
          case 0xBD42FF00:
            Serial.println("STAR");
            break;
          case 0xB54AFF00:
            Serial.println("PAWN");
            break;
    }
      }
    IrReceiver.resume();
  }
}

/* LIST OF CODES [ELEGOO MINI REMOTE]
 *  OK; HEX=0xBF40FF00; INT=3208707840      POWER
 *  ONE; HEX=0xE916FF00 ; INT=3910598400    
 *  TWO; HEX=0xE619FF00 ; INT=3860463360
 *  THREE; HEX=0xF20DFF00 ; INT=4061003520
 *  FOUR; HEX=0xF30CFF00 ; INT=4077715200
 *  FIVE; HEX=0xE718FF00 ; INT=3877175040
 *  SIX; HEX=0xA15EFF00 ; INT=2707357440
 *  SEVEN; HEX=0xF708FF00 ; INT=4144561920
 *  EIGHT; HEX=0xE31CFF00 ; INT=3810328320
 *  NINE; HEX=0xA55AFF00 ; INT=2774204160
 *  ZERO; HEX=0xAD52FF00 ; INT=2907897600   OVERRIDE ALL
 *  STAR; HEX=0xBD42FF00 ; INT=3175284480   OVERRIDE TRAFFIC
 *  PAWN; HEX=0xB54AFF00 ; INT=3041591040   OVERRIDE PEDESTRIAN
 */
