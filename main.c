/*******************************************************************
 *	C Program to control conveyor belt 
 *******************************************************************/

#include "htc.h"	// htc.h points to the appropriate technology header file
					// (in this case 8052.h) which assigns labels to commonly used
					// registers such as P1, P2, P3 and specific bits such as P02, P03 

int halt(void)  {
	while(1);
}

void main()
{

	P1 = 0x00;		// Clear control out for conveyor
	P2 = 0x00;		// Clear control in for conveyor
	P3 = 0x0FF;		// Default for ext ports is already high
					// Need to ensure that ~Enable remains high 

	P1 = 0x08;		// Start box moving forward

	// Poll until the box hits sensor 2
	while (!P02)	{
	}

	P1 = 0x03;		// Stop the box
	P3 = 0x00;		// Enable dropping mechanism
	P3 = 0x01;		// Disable dropping mechanism
	P1 = 0x08;		// Start the box moving forward

	// Poll until the box hits sensor 3
	while (!P03)	{
	}

	P1 = 0x02;		// Stop the box

	halt();

	return;
}
