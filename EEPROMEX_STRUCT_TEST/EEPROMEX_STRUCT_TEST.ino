#include <EEPROMex.h>
//#include <EEPROMVar.h>

int address = 0;
int maxAllowedWrites = 10;

struct Parametros {
  byte MIID;
  byte maxesclavo;
  boolean  dump;
  unsigned long maxping;
  byte ip1;
  byte ip2;
  byte ip3;
  byte ip4;
  byte gw1;
  byte gw2;
  byte gw3;
  byte gw4;
};

Parametros ParametrosInput;
//Parametros ParametrosOutput;

void setup()
{
  Serial.begin(115200);

  Serial.println(F("INICIA EEPROMEX TEST\n\r\n\r*** MENU ***"));
  MuestraMenu();

  EEPROM.setMaxAllowedWrites(maxAllowedWrites);

  EEPROM.readBlock(address, ParametrosInput);

  Serial.println(F("*** PARAMETROS AL ARRANQUE ***\n\r"));

  MuestraParametros();

  Serial.println(F("\n\r***************************"));

}

void loop() {

  //Comandos via puerto serie
  if ( Serial.available())
  {

    char ch = Serial.read();
    switch (ch)
    {
      //    case '0'...'9':
      //      //v = v * 10 + ch - '0';
      //      v = ch - '0';
      //      break;
      case 'd': //Vuelco
        {
          ParametrosInput.dump = !ParametrosInput.dump;
          MuestraParametros();
          break;
        }
      case 'a': //Address MIID
        {
          ParametrosInput.MIID = Serial.parseInt();
          MuestraParametros();
          break;
        }
      case 't': //timers interroga
        {
          ParametrosInput.maxping = Serial.parseInt();
          MuestraParametros();
          break;
        }
      case 'i': //direccion ip
        {
          ParametrosInput.ip1 = Serial.parseInt();
          ParametrosInput.ip2 = Serial.parseInt();
          ParametrosInput.ip3 = Serial.parseInt();
          ParametrosInput.ip4 = Serial.parseInt();
          MuestraParametros();
          break;
        }
      case 'g': //direccion gateway (router)
        {
          ParametrosInput.gw1 = Serial.parseInt();
          ParametrosInput.gw2 = Serial.parseInt();
          ParametrosInput.gw3 = Serial.parseInt();
          ParametrosInput.gw4 = Serial.parseInt();
          MuestraParametros();
          break;
        }
      case 'm': //muestra parametros actuales
        {
          MuestraParametros();
          break;
        }
      case 'w': //GRABA EEPROM
        {
          if (EEPROM.updateBlock(address, ParametrosInput))
          {
            while (!EEPROM.isReady()) {
              delay(1);
            }
            EEPROM.readBlock(address, ParametrosInput);
            MuestraParametros();
          }
          else
          {
            Serial.println(F("ERROR AL ESCRIBIR EEPROM"));
          }
          break;
        }
      case 'e': //nro de esclavos
        {
          ParametrosInput.maxesclavo = Serial.parseInt();
          if (ParametrosInput.maxesclavo <= 0 || ParametrosInput.maxesclavo > 8) {
            ParametrosInput.maxesclavo = 1;
          }
          MuestraParametros();
          break;
        }
      //help
      case '?':
        {
          MuestraMenu();
          break;
        }
    }
  }
}

void MuestraParametros()
{
  //
  //  String salida = "MIID=" + (String)ParametrosInput.MIID +
  //                  " Maximo Esclavo=" + (String)ParametrosInput.maxesclavo +
  //                  " Retardo maximo de PING=" + (String)ParametrosInput.maxping +
  //                  " Vuelco=" + ParametrosInput.dump ? "SI" : "NO";
  //  Serial.println(salida);
  Serial.print("MIID=");
  Serial.print(ParametrosInput.MIID);
  Serial.print("\t ESCLAVOS=");
  Serial.print(ParametrosInput.maxesclavo);
  Serial.print("\t VUELCO="); Serial.print(ParametrosInput.dump ? "SI" : "NO");
  Serial.print("\t MAXPING="); Serial.println(ParametrosInput.maxping);
  Serial.print("IP=");
  Serial.print(ParametrosInput.ip1);
  Serial.print(".");  Serial.print(ParametrosInput.ip2);
  Serial.print(".");  Serial.print(ParametrosInput.ip3);
  Serial.print(".");  Serial.println(ParametrosInput.ip4);
  Serial.print("GW=");
  Serial.print(ParametrosInput.gw1);
  Serial.print(".");  Serial.print(ParametrosInput.gw2);
  Serial.print(".");  Serial.print(ParametrosInput.gw3);
  Serial.print(".");  Serial.println(ParametrosInput.gw4);
}

void MuestraMenu()
{
  Serial.print(F("\n\rm: Muestra parametros\n\rw: Guarda en EEPROM\n\r"));
  Serial.print(F("ann: MIID\n\rtnn: MAXPING\n\rd: DUMP\n\renn: MAXIMO ESCLAVO\n\r"));
  Serial.println(F("in.n.n.n: Direccion IP\n\rgn.n.n.n: Direccion GW\n\r"));
}

