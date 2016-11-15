http://arduino.esp8266.com/stable/package_esp8266com_index.json

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

### Cálculo estimado de la autonomia en baterias de gel y plomo ácido (Consumos de corriente superiores a 1 Amperio)

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

### [Cálculo estimado de la autonomia en baterias alcalinas](http://www.digikey.com/es/resources/conversion-calculators/conversion-calculator-battery-life)

### Cálculo estimado de la autonomía en baterias Li-Ion (Consumos promedio inferiores a 0,2 Amperios)

La aproximación se efectúa desde el punto de vista energético y se comienza estimando la energía disponible para alimentar un circuito electrónico desde una celda del tipo Li-Ion. Por ejemplo las características de la celda pueden ser:

Capacidad: 1.500 mAh

Voltaje:   3,7V

H: 7hs

k: 1,05

Los circuitos electrónicos se alimentan con tensiones nominales de 3,3 Voltios o 5 Voltios, por lo tanto una adecuación a estos valores debe hacerse por medio de un regulador que oficie de fuente adecuada. La eficiencia promedio de estos reguladores se estima en:

85% o sea, una eficiencia de 0,85

Usando un circuito de controlador con sensores que en total consumen 40 miliAmperios con alimentación de 5Voltios, la corriente total requerida afectada por la eficiencia del conversor será:

Itotal_constante = 40 miliAmperios / 0,85 = 47 mA.

Si se mantiene siempre funcionando, aplicamos la ecuación de duración lo que arrojaría:

### 7/((47 x 7)/1.500)**1,05) = 34,43 Hs, o sea 1 día con 10 Hs

Usando estrategias de reducción de potencia, se define el ciclo de consumo de corriente en un circuito como sigue:

Icorriente promedio = (tEncendido X Iencendido + tApagado x Iapagado)/TiempoTotal

Por ejemplo, al mantener los mismos elementos encendidos durante 4 Segundos con un consumo total del orden de 40 miliAmperios y apagar todos los componentes durante 30 Segundos con un consumo total del orden de 1 miliAmperio, entonces el consumo promedio sería:

(4 segundos x 40 mA + 30 segundos x 1 mA)/34 segundos = 5,59 mA.

Ahora la ecuación daría:

### 7/((5,59 x 7)/1.500)**1,05) = 322,002 Hs, o sea 13 días con 10 Hs.

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
