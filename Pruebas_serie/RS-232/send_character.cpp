#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "rs232.h"

using namespace std;

int main() {
  int cport_nr=24,       // ttyACM0
      bdrate=9600;       //9600 baud
       
  char mode[]={'8', 'N', '1', 0}; 

  if(RS232_OpenComport(cport_nr, bdrate, mode, 0)) {
    cout<<"Erro no se puede abrir el puerto\n";
    return(0);
  }

  while(1) {
    RS232_SendByte(cport_nr, 'a');
    usleep(1000000);  // 1 s 
  }
  return(0);
}

