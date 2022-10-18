#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "rs232.h"

using namespace std;


typedef struct Motores {   //Definimos de la estructura para guardar los datos de los sensores
  uint16_t x;
  uint16_t y;

  uint16_t x_actual;
  uint16_t y_actual;
}Motores;

union UDato {  //Definimos una union para poder mandar los datos byte a byte
  Motores datos;
  unsigned char  a[sizeof(Motores)];
} Datos, Hola;


int cport_nr=24,       // ttyACM0
bdrate=9600;       //9600 baud   
char mode[]={'8', 'N', '1', 0};

void chequeo_port(){
	
	if(RS232_OpenComport(cport_nr, bdrate, mode, 0)) {
    	cout<<"Erro no se puede abrir el puerto\n";
	}
}

void enviar_letra(char letra){
	
	RS232_SendByte(cport_nr, letra);	
}

void Recibir_Struct(){
	int cantidadBytes= RS232_PollComport(cport_nr, Hola.a, sizeof(Motores));  //Leemos la cantidad de bytes recibidos
		
		cout<<"Los bytes recibidos fueron:"<<cantidadBytes<<endl;	// Imprimimos la cantidad de bytes recibidos para saber si es que se recibieron o no
		
		if (cantidadBytes>0){		//Si se reciben mas de 0 bytes entrara en este if
		
			cout<<"x_actual: "<<Hola.datos.x_actual<<endl;  //Imprimimos los datos recibidos desde el arduino
			cout<<"y_actual: "<<Hola.datos.y_actual<<endl;
			cout<<"X: "<<Hola.datos.x<<endl;
			cout<<"y: "<<Hola.datos.y<<endl;
		}
}

void Enviar_Struct(){
	int cantidadBytes= RS232_SendBuf(cport_nr, Datos.a, sizeof(Motores));  //Leemos la cantidad de bytes enviados
	cout<<"Los bytes enviados fueron:"<<cantidadBytes<<endl;	// Imprimimos la cantidad de bytes recibidos para saber si es que se recibieron o no

}

int main(){
	char letra;
	cout<<"\n\tSelecione el Sensor\n";  //Le pedimos al usuario que ingrese el tipo del sensor
	cout<<"Opcion : ";
	cin>>letra;
	Datos.datos.x = 100;
	Datos.datos.y = 101;
	Datos.datos.x_actual = 102;
	Datos.datos.y_actual = 103;
	
	chequeo_port();
	enviar_letra(letra);
	usleep(150000);
	Enviar_Struct();
	usleep(150000);
	Recibir_Struct();

	return(0);
}
