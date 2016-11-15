/*
   SENSORES DE TEMPERATURA Y HUMEDAD SE ALIMENTAN DESDE PIN 9 (max 40mA)
   DEL PROCESADOR.

   EL PIN A5 MONITOREA ESTADO DE LA BATERIA.

   SI EL VOLTAJE DE LA BATERIA CAE DABAJO DE 4 VOLTS, AUMENTA EL TIEMPO
   DE IDLE.
*/

#include <SimpleDHT.h>
#include "LowPower.h"

#define DHT_A       4
#define DHT_B       5
#define BATERIA     A5
#define POWER       9

// for DHT11,
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2

SimpleDHT11 dht11;

byte temp = 0;
byte hum = 0;
float BAT = 0;

void setup() {
  Serial.begin(115200);

  pinMode(POWER, OUTPUT);
  digitalWrite(POWER, LOW);

  // start working...
  Serial.println("=================================");
  Serial.println(F("INICIA DHT LONG TEST"));
  Serial.flush();
}

void loop()
{
  Serial.println(F("ACTIVA SENSORES X 2 SEG."));
  digitalWrite(POWER, HIGH);
  delay(2000);

  //Descarta primera lectura
  dht11.read(DHT_A, &temp, &hum, NULL);
  delay(1000);
  if (dht11.read(DHT_A, &temp, &hum, NULL)) {
    Serial.println(F("DHT_A failed."));
  }
  else
  {
    Serial.print(F("DHT_A OK: "));
    Serial.print((float)temp); Serial.print(F(" *C, "));
    Serial.print((float)hum); Serial.println(F(" %"));
  }

  //Descarta primera lectura
  dht11.read(DHT_B, &temp, &hum, NULL);
  delay(1000);
  if (dht11.read(DHT_B, &temp, &hum, NULL)) {
    Serial.println(F("DHT_A failed."));
  }
  else
  {
    Serial.print(F("DHT_B OK: "));
    Serial.print((float)temp); Serial.print(F(" *C, "));
    Serial.print((float)hum); Serial.println(F(" %"));
  }

  Serial.println(F("APAGA TODO POR 8 SEGUNDOS"));
  Serial.flush();

  digitalWrite(POWER, LOW);

  // APAGA TODO x 8 SEG
  LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,
                SPI_OFF, USART0_OFF, TWI_OFF);

  //VERIFICA ESTADO DE BATERIA
  analogRead(BATERIA); //Descarto primera lectura
  int batdigi = analogRead(BATERIA);
  if (batdigi < 818) //BATERIA < 4 Voltios
  {
    Serial.println(F("BATERIA BAJA. APAGA TODO OTROS 24 SEGUNDOS"));
    Serial.flush();
    LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,
                  SPI_OFF, USART0_OFF, TWI_OFF);
    LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,
                  SPI_OFF, USART0_OFF, TWI_OFF);
    LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,
                  SPI_OFF, USART0_OFF, TWI_OFF);
  }
  Serial.println(F("ENCIENDE TODO"));
  Serial.flush();
}
