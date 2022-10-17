#include"MotorPAP.h" // Primero lo que hacemos es incluir la libreria que creamos con la clase y despues la libreria de arduino 
#include "Arduino.h"  // esto lo hacemos para que nos detecte las funciones de arduino

int tiempo = 5; //definimos la variable que usamos en los delay


Motor_PAP::Motor_PAP(int b1, int b2, int b3, int b4) {
  bob1 = b1;  //declaramos los pines de las bobinas en las variables que se encuentran en la parte privada de la clase
  bob2 = b2;
  bob3 = b3;
  bob4 = b4;
  pinMode(bob1, OUTPUT);  //las declaramos como salidas
  pinMode(bob2, OUTPUT);
  pinMode(bob3, OUTPUT);
  pinMode(bob4, OUTPUT);
}
void Motor_PAP::Mov_medio(bool Sentido) { //en este caso el movimiento es de medio paso
  digitalWrite(bob1, 0); //iniciamos todas las salidas en 0, esto lo hacemos por si alguna quedo encendida de cuando se hizo el cambio de tipo de funcionamiento
  digitalWrite(bob2, 0);
  digitalWrite(bob3, 0);
  digitalWrite(bob4, 0);

  if (Sentido == 0) {   //la variable sentido es una de tipo booleana y asi definimos el sentido de giro

    digitalWrite (bob1, 1);
    delay (tiempo);
    digitalWrite (bob4, 0);
    delay (tiempo);
    digitalWrite (bob2, 1);
    delay (tiempo);
    digitalWrite (bob1, 0);
    delay (tiempo);
    digitalWrite (bob3, 1);
    delay (tiempo);
    digitalWrite (bob2, 0);
    delay (tiempo);
    digitalWrite (bob4, 1);
    delay (tiempo);
    digitalWrite (bob3, 0);
    delay (tiempo);

  }

  else if (Sentido == 1) {    //aca seguimos en el movimiento de medio paso pero en el sentido inverso

    digitalWrite (bob1, 1);
    delay (tiempo);
    digitalWrite (bob2, 0);
    delay (tiempo);
    digitalWrite (bob4, 1);
    delay (tiempo);
    digitalWrite (bob1, 0);
    delay (tiempo);
    digitalWrite (bob3, 1);
    delay (tiempo);
    digitalWrite (bob4, 0);
    delay (tiempo);
    digitalWrite (bob2, 1);
    delay (tiempo);
    digitalWrite (bob3, 0);
    delay (tiempo);

  }
}

void Motor_PAP::Mov_uno(bool Sentido) {   //el movimiento es de un paso encendiendo una bobina a la vez
  digitalWrite(bob1, 0);    //volvemos a iniciar todas las bobinas en cero
  digitalWrite(bob2, 0);
  digitalWrite(bob3, 0);
  digitalWrite(bob4, 0);

  if (Sentido == 0) {   //aca sentido tiene el mismo proposito que en la anterior y que en la siguiente funcion

    digitalWrite(bob4, 0);
    digitalWrite(bob1, 1);
    delay(tiempo);
    digitalWrite(bob1, 0);
    digitalWrite(bob2, 1);
    delay(tiempo);
    digitalWrite(bob2, 0);
    digitalWrite(bob3, 1);
    delay(tiempo);
    digitalWrite(bob3, 0);
    digitalWrite(bob4, 1);
    delay(tiempo);
  }
  else if (Sentido == 1) {  //movimiento de un paso pero en sentido contrario

    digitalWrite(bob1, 0);
    digitalWrite(bob2, 0);
    digitalWrite(bob3, 0);
    digitalWrite(bob4, 0);

    digitalWrite(bob1, 1);
    delay(tiempo);
    digitalWrite(bob1, 0);
    digitalWrite(bob4, 1);
    delay(tiempo);
    digitalWrite(bob4, 0);
    digitalWrite(bob3, 1);
    delay(tiempo);
    digitalWrite(bob3, 0);
    digitalWrite(bob2, 1);
    delay(tiempo);
    digitalWrite(bob2, 0);
  }

}


void Motor_PAP::Mov_dos(bool Sentido) {   //esta es la funcion para el movimiento con dos bobinas a la vez
  digitalWrite(bob1, 0);  //otra vez iniciamos las bobinas en cero
  digitalWrite(bob2, 0);
  digitalWrite(bob3, 0);
  digitalWrite(bob4, 0);

  if (Sentido == 0) {   //movimiento en un sentido con dos bobinas a la vez
    digitalWrite(bob1, 1);
    digitalWrite(bob2, 1);
    digitalWrite(bob3, 0);
    digitalWrite(bob4, 0);
    delay(tiempo);
    digitalWrite(bob1, 0);
    digitalWrite(bob2, 1);
    digitalWrite(bob3, 1);
    digitalWrite(bob4, 0);
    delay(tiempo);
    digitalWrite(bob1, 0);
    digitalWrite(bob2, 0);
    digitalWrite(bob3, 1);
    digitalWrite(bob4, 1);
    delay(tiempo);
    digitalWrite(bob1, 1);
    digitalWrite(bob2, 0);
    digitalWrite(bob3, 0);
    digitalWrite(bob4, 1);
    delay(tiempo);

  }
  else if (Sentido == 1) {  //movimiento en el sentido contrario
    digitalWrite(bob1, 1);
    digitalWrite(bob2, 0);
    digitalWrite(bob3, 0);
    digitalWrite(bob4, 1);
    delay(tiempo);
    digitalWrite(bob1, 0);
    digitalWrite(bob2, 0);
    digitalWrite(bob3, 1);
    digitalWrite(bob4, 1);
    delay(tiempo);
    digitalWrite(bob1, 0);
    digitalWrite(bob2, 1);
    digitalWrite(bob3, 1);
    digitalWrite(bob4, 0);
    delay(tiempo);
    digitalWrite(bob1, 1);
    digitalWrite(bob2, 1);
    digitalWrite(bob3, 0);
    digitalWrite(bob4, 0);
    delay(tiempo);
  }

}

void Motor_PAP::Mov_uno_plus(bool Sentido, int pasos , int times) {   //el movimiento es de un paso encendiendo una bobina a la vez
  digitalWrite(bob1, 0);    //volvemos a iniciar todas las bobinas en cero
  digitalWrite(bob2, 0);
  digitalWrite(bob3, 0);
  digitalWrite(bob4, 0);
  int tiempo;
  tiempo = 2;//times / pasos;
  int bobs[4] = {bob1, bob2, bob3, bob4};
  if (Sentido == 1) {
  // con estos for realizo el mivimeto de una bobuna de forma automática, cada ciclo del for es un paso  
    for (int i = 2; i < (pasos+2); i++) {//movimiento en un sentido 
      digitalWrite(bobs[i % 4], 1);
      delay(tiempo);
      digitalWrite(bobs[3], 0);
      digitalWrite(bobs[2], 0);
      digitalWrite(bobs[1], 0);
      digitalWrite(bobs[0], 0);
      
    }
  } else if (Sentido == 0) {//movimiento en el sentido cotrario

    for (int i = pasos; i > 0; i--) {
      digitalWrite(bobs[i % 4], 0);
      delay(tiempo);
      digitalWrite(bobs[3], 0);
      digitalWrite(bobs[2], 0);
      digitalWrite(bobs[1], 0);
      digitalWrite(bobs[0], 0);
    }
  }
}
