#include <Arduino.h>
#include <EEPROM.h>
//#include <SoftwareSerial.h>

// Debug related definitions
#define DEBUG
#ifdef DEBUG
#define DEBUG_SERIAL_BEGIN() Serial2.begin(19200)
#define DEBUG_LOG(string) Serial2.print(string)
#define DEBUG_LOG_LN(string) Serial2.println(string)
#else
#define DEBUG_SERIAL_BEGIN()
#define DEBUG_LOG(string)
#define DEBUG_LOG_LN(string)
#endif
#define DEBUG_LOG_FREE_RAM()  \
  DEBUG_LOG(F("Free RAM: ")); \
  DEBUG_LOG_LN(FreeRam())
  



// #define MAX3059_AQUABUS_ADAPTER gfgfhgfhfg

// Include header files
#include <AquaBusDev.h>
#include <AquaBusLib.h>
//#include <EB8.h>
//#include <PM2.h>
#include <PM1.h>
//#include <PM3.h>
//#include <VDM.h>

// SoftwareSerial Serial2(3, 2); // 8 is RX, 9  is TX
AquaBusLib gAquaBusLib(1);


PM1 gPM1(0x7777);

int incomingByte = 0; // for incoming serial data

void setup()
{
  gAquaBusLib.setup();
  // Initialize the serial communication for debugging
  DEBUG_SERIAL_BEGIN();
  DEBUG_LOG_LN(F("Starting Aqua Bus Device sketch ..."));
  /*
#ifdef MAX3059_AQUABUS_ADAPTER
  //ON MAX3059 based boards, drive RS pin LOW and TERM pin High to match Apex cofiguration
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
#endif
*/
  //AB Address Init
  eeprom_update_byte(0, 0);
//PM1 Init
  eeprom_update_byte((uint8_t *)3, 0);
  eeprom_update_word((uint16_t *)4, 0xFFF2);
  eeprom_update_word((uint16_t *)6, 0xFFF9);
  eeprom_update_word((uint16_t *)8, 0xFFF0);
  eeprom_update_word((uint16_t *)10, 0x0238);
  eeprom_update_word((uint16_t *)12, 0x1000);
  eeprom_update_word((uint16_t *)14, 0x0B55);
  eeprom_update_word((uint16_t *)16, 0x0E60);
  eeprom_update_word((uint16_t *)18, 0x1086);


  //DEBUG_LOG_LN("eeprom_update_byte... ");
}

void loop()
{
 // DEBUG_LOG_LN(F("loop..."));
  gAquaBusLib.loop();
  

}