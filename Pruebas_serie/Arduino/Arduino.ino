// Lectura de bytes de almacenamiento

#include <stdint.h>
#include"MotorPAP.h"

bool RL = 1;  //variable que pasamos a las funciones para definir el sentido
int movimiento = 1; //variable para elegir el tipo de funcionamiento
int aux = 1;

uint32_t T; //Variables usadas para la lectura y transformacion

struct Motores {   //Definimos de la estructura para guardar los datos de los sensores
  uint16_t x;
  uint16_t y;

  uint16_t x_actual;
  uint16_t y_actual;
};

union UDato {  //Definimos una union para poder mandar los datos byte a byte
  Motores datos;
  byte a[sizeof(Motores)];
} Datos;

int espera = 200, time = 0; //Variables usadas en el antirebote y el delay

void Actual() {

  for (unsigned long long k = 0; k < sizeof(Motores); k++) { //Pasamos los datos byte a byte
    Serial.write(Datos.a[k]);
  }
  Serial.println("enviado1");
}
void Recibir_Struct() {
    Serial.readBytes(Datos.a, sizeof(Motores));
}

void setup() {

  Serial.begin (9600);
}

void loop() {
  Motor_PAP a = Motor_PAP(7, 6, 5, 4);
  uint8_t Identificador[1]; //Variable que se usa para identificar el tipo de sensor elegido
  bool hola = 0;
  size_t n; //Utilizamos esta variable para verificar si se leyeron datos
  
  if (Serial.available()){
    
  n= Serial.readBytes(Identificador, 1);
    if (n==1){
          Recibir_Struct();
          Actual();
    }  }

}

