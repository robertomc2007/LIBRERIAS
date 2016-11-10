// **** INCLUDES *****
#include "LowPower.h"

void setup()
{
  Serial.begin(115200);

  Serial.println(F("INICIO LOWPOWER TEST"));
}

void loop()
{
  Serial.println(F("ANTES DE POWERDOWN"));
  Serial.flush();
  // Enter power down state for 8 s with ADC and BOD module disabled
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  delay(1);
  Serial.println(F("ANTES DE IDLE"));
  Serial.flush();
  LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,
                SPI_OFF, USART0_OFF, TWI_OFF);
  delay(1);
  Serial.println(F("DESPUES DE IDLE"));
  Serial.flush();


}
