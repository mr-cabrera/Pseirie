
/**************************************************

file: demo_tx.c
purpose: simple demo that transmits characters to
the serial port and print them on the screen,
exit the program by pressing Ctrl-C

compile with the command: gcc send_character.c rs232.c -Wall -Wextra -o2 -o test_tx

**************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rs232.h"



int main() {
  int cport_nr=24,       /* /dev/ttyUSB0 */
      bdrate=9600;       /* 9600 baud */

  char mode[]={'8', 'N', '1', 0};

  char a = 'a';

  if(RS232_OpenComport(cport_nr, bdrate, mode, 0)) {
    printf("Can not open comport\n");

    return(0);
  }

  while(1) {
    RS232_SendByte(cport_nr, a);
    usleep(100000);  /* sleep for 1 Second */
    
  }

  return(0);
}

