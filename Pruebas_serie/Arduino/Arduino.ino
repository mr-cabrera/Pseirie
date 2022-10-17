// Lectura de bytes de almacenamiento

#include <stdint.h>
#include"MotorPAP.h"

bool RL = 1;  //variable que pasamos a las funciones para definir el sentido
int movimiento = 1; //variable para elegir el tipo de funcionamiento
int aux = 1;

uint32_t T; //Variables usadas para la lectura y transformacion

struct Sensores {   //Definimos de la estructura para guardar los datos de los sensores
  uint16_t x;
  uint16_t y;

  uint16_t x_actual;
  uint16_t y_actual;
};

union UDato {  //Definimos una union para poder mandar los datos byte a byte
  Sensores datos;
  byte a[sizeof(Sensores)];
} Datos;

int espera = 200, time = 0; //Variables usadas en el antirebote y el delay

void Actual() {

  for (unsigned long long k = 0; k < sizeof(Sensores); k++) { //Pasamos los datos byte a byte
    Serial.write(Datos.a[k]);
  }
  Serial.println("enviado1");
}

void setup() {
  Datos.datos.x = 100;
  Datos.datos.y = 101;
  Datos.datos.x_actual = 102;
  Datos.datos.y_actual = 103;
  Serial.begin (9600);
}

void loop() {
  Motor_PAP a = Motor_PAP(7, 6, 5, 4);
  uint8_t Identificador[10]; //Variable que se usa para identificar el tipo de sensor elegido
  bool hola = 0;
  size_t n; //Utilizamos esta variable para verificar si se leyeron datos
  if (Serial.available()) {
    //hola != hola;
    Serial.readBytes (Identificador, 10);
    Serial.print(Identificador[0]);
    Serial.print(Identificador[1]);
    Serial.print(Identificador[2]);
    Serial.print(Identificador[3]);
    Serial.print(Identificador[4]);
    Serial.print(Identificador[5]);
    Serial.print(Identificador[6]);
    Serial.print(Identificador[7]);
    Serial.print(Identificador[8]);
    Serial.print(Identificador[9]);


    // a.Mov_uno(hola);

  }



  //Serial.println(Identificador[0]);




}
