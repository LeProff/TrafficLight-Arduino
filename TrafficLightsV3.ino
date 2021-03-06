#include <IRremote.hpp>

int RECV_PIN = 7;

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
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
            break;
          case 0xE916FF00:
            Serial.println("1");   
            break;
          case 0xE619FF00:
            Serial.println("2");
            break;
          case 0xF20DFF00:
            Serial.println("3");
            break;
          case 0xF30CFF00:
            Serial.println("4");
            break;
          case 0xE718FF00:
            Serial.println("5");
            break;
          case 0xA15EFF00:
            Serial.println("6");
            break;
          case 0xF708FF00:
            Serial.println("7");
            break;
          case 0xE31CFF00:
            Serial.println("8");
            break;
          case 0xA55AFF00:
            Serial.println("9");
            break;
          case 0xAD52FF00:
            Serial.println("0");
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
 *  OK; HEX=0xBF40FF00; INT=3208707840
 *  ONE; HEX=0xE916FF00 ; INT=3910598400
 *  TWO; HEX=0xE619FF00 ; INT=3860463360
 *  THREE; HEX=0xF20DFF00 ; INT=4061003520
 *  FOUR; HEX=0xF30CFF00 ; INT=4077715200
 *  FIVE; HEX=0xE718FF00 ; INT=3877175040
 *  SIX; HEX=0xA15EFF00 ; INT=2707357440
 *  SEVEN; HEX=0xF708FF00 ; INT=4144561920
 *  EIGHT; HEX=0xE31CFF00 ; INT=3810328320
 *  NINE; HEX=0xA55AFF00 ; INT=2774204160
 *  ZERO; HEX=0xAD52FF00 ; INT=2907897600
 *  STAR; HEX=0xBD42FF00 ; INT=3175284480
 *  PAWN; HEX=0xB54AFF00 ; INT=3041591040
 */
