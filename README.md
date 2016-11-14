# LIBRERIAS

## PÁGINA DE REFERENCIA

[LIBRERÍAS ARDUINO](http://playground.arduino.cc/Main/LibraryList)

## TIMER

[TIMERS](https://github.com/alextaujenis/RBD_Timer)

## BOTONES

[BOTONES](https://github.com/alextaujenis/RBD_Button)

## RTOS

[CUASI-TAREAS](http://playground.arduino.cc/Code/SimpleTimer)

## GESTIÓN DE ENERGÍA

[ALIMENTACIÓN](https://github.com/Yveaux/Arduino_Vcc)

[LOWPOWER](https://github.com/rocketscream/Low-Power)

###Cálculo de la autonomia en baterias de gel y plomo ácido

Aplicación de la fórmula y exponente de Peukert

(copyright) Por Roberto Villaverde

La autonomia, mejor dicho, capacidad, de las baterias recargables, fundamentalmente en las de plomo-ácido (por ejemplo la de los vehículos) y selladas de gel como las que usamos en modelos, se reduce drásticamente a medida que aumentamos el consumo, esto es, la corriente que solicitamos de las mismas.

Es común, por ejemplo, suponer que si tenemos una bateria de 4AH (4 amperes-hora), podríamos tentarnos de afirmar que “si consumo 1 A, me durará 4 horas, si consumo 2A, 2 horas, si le pido 4A, 1 hora, etc. En la práctica esto no es así.

En el siglo XIX, un alemán, W. Peukert (pronúnciese póikert), estableció, en 1897 una fórmula que es la que se ha estado utilizando hasta el dia de hoy, y permite calcular con mucha aproximación la capacidad real, o bien, el tiempo de autonomia de una bateria de plomo-ácido o de gel sellada, en función de la autonomia nominal y el consumo al que la sometemos.

La fórmula es la siguiente:

#### t=H/((I x H/C)**k)

Que nos da el tiempo en horas de autonomia en función de cómo varia la capacidad según el consumo. Los parámetros son:  

t: tiempo en horas de autonomia que nos da la fórmula.  

C: es la capacidad de la bateria en AH (amperes-hora) indicada por el fabricante, durante un tiempo de consumo determinado, que es el siguiente parámetro:  

H: En general, si no está impreso en la bateria, podemos suponer que el valor normalmente es de 20 horas.  

I: es la intensidad de corriente que solicitaremos de la bateria, en A (amperes), el cual debemos conocerlo estableciendo el consumo promedio en el tiempo.  

k: es el exponente de Peukert y es un valor inherente al tipo de bateria y en general debe ser indicado por el fabricante, aunque generalmente esto no es así. No obstante, en general se puede afirmar que este valor está comprendido entre 1.1 (para baterias de gel de buena calidad) y 1.3 (para las de plomo-ácido). Si existiera una bateria ideal, el exponente seria 1. Cuanto menor sea, mejor rendimiento tendremos de la bateria.

Veamos un ejemplo:  

Supongamos que tenemos una bateria de 6V 4AH, y nuestro modelo consume 2A (supongamos un consumo constante promediándolo), supongamos también que la bateria entrega 4AH equivalente en 20H (salvo se especifique lo contrario); tomemos también 1.1 como exponente de Peukert para las baterias de gel, entonces tenemos:

#### 20/((2 x 20)/4)**1.1) = 1,59hs = 1h 35'

## COMUNICACIONES

[SOFTWARESERIAL](https://www.arduino.cc/en/Reference/SoftwareSerial)

[RADIOHEAD](http://www.airspayce.com/mikem/arduino/RadioHead/)

[MANCHESTER](https://github.com/mchr3k/arduino-libs-manchester/)

## TELEMETRÍA

[DISTANCIA](http://playground.arduino.cc/Code/NewPing)

## LUZ

El uso de esta librería requiere de operaciones manuales ya que no se encuentra en los formatos de descarga/actualización automática (Programa/Incluir librería/Incluir Librerías) ni en el formato de incorporación comprimida (Programa/Incluir librería/Añadir Librería .ZIP...). Los pasos son:

*Descargar la librería (.zip).

*Descomprimir en directorio /arduino_sketch_folder/libraries/BH1750.

NOTA1: El directorio /arduino_sketch_folder/ debería estar en Documentos/Arduino.
NOTA2: Si no existe todavía el subdirectorio /libraries/ , crearlo manualmente.

*Reiniciar IDE.

[SENSOR DIGITAL BH1750 BASICO](https://github.com/claws/BH1750)

[SENSOR DIGITAL BH1750 AVANZADO](https://github.com/tuxcell/bh1750xtra)

## MEMORIA

[EEPROM](https://github.com/thijse/Arduino-EEPROMEx)

## CSharp

[C#](https://github.com/christophediericx/ArduinoDriver)
