// **** INCLUDES *****
#include "LowPower.h"

void setup()
{
  Serial.begin(115200);

  Serial.println(F("INICIO LOWPOWER TEST"));
  
  pinMode(13,OUTPUT);
  
}

void loop()
{
  
  Serial.println(F("PLENO CONSUMO POR 4 SEGUNDOS"));
  Serial.flush();
  
  digitalWrite(13,HIGH);
  
  delay(4000);

  Serial.println(F("ANTES DE REDUCCION DE ENERGÍA"));
  Serial.flush();
  
  digitalWrite(13,LOW);
  
  LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,
                SPI_OFF, USART0_OFF, TWI_OFF);
  LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,
                SPI_OFF, USART0_OFF, TWI_OFF);
  LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,
                SPI_OFF, USART0_OFF, TWI_OFF);

}
