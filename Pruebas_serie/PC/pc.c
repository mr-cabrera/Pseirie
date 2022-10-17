/*************************************************************
 * 
 * Para compilar debe utilizarse el siguiente comando
 *
 * gcc pc.c rs232.c -Wall -Wextra -o2 -o PC
 *
 *************************************************************/
#include <stdio.h>
#include <stdint.h>

#include "rs232.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


typedef struct Sensores{ //Definimos de la estructura para guardar los datos de los sensores
    uint32_t tiempo;
    uint16_t valor; 
    char tipo;
}Sens;

union Udato{  //Definimos la union para leer e imprimir los datos de los sensores
	Sens dato;
	byte a[sizeof(Sens)];
}medic;


int main(){

	int cport_nr=5,       /* /dev/ttyUSB0 */
		bdrate=9600;       /* 9600 baud */
	char mode[]=  {'8', 'N', '1', 0};
	
	char letra; //Es la letra usada para el scanf

	if(RS232_OpenComport(cport_nr, bdrate, mode, 0)){
    	
		printf("No se pudo abrir el puerto\n"); //En caso de que el no se pueda abrir el puerto manda un mensaje de error
  
  }

	while (1){

		printf("\n\tSelecione el Sensor\n");  //Le pedimos al usuario que ingrese el tipo del sensor
		printf("Opcion : ");scanf("%c",&letra);

		RS232_SendByte(cport_nr, letra);	

		Sleep(150);

		int cantidadBytes= RS232_PollComport(cport_nr, medic.a, sizeof(Sens));  //Leemos la cantidad de bytes recibidos

		printf ("Los bytes recibidos fueron: %d\n\n", cantidadBytes);	// Imprimimos la cantidad de bytes recibidos para saber si es que se recibieron o no

		if (cantidadBytes>0){		//Si se reciben mas de 0 bytes entrara en este if

			printf ("Identificador del sensor: %c\n", medic.dato.tipo);  //Imprimimos los datos recibidos desde el arduino
			printf ("Tiempo en milisegundos: %d\n", medic.dato.tiempo);
			printf ("Valor 'En crudo': %d\n", medic.dato.valor);
	
		}	
		return 0;
	}
}
