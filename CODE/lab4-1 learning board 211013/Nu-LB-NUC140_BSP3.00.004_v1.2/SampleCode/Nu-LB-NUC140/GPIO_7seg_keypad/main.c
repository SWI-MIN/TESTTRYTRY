//
// GPIO_7seg_keypad : 3x3 keypad inpt and display on 7-segment LEDs
//
#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "Seven_Segment.h"
#include "Scankey.h"

// display an integer on four 7-segment LEDs
void Show(uint16_t value)
{
	
}

int main(void)
{
		uint16_t i;
	
    SYS_Init();

    OpenSevenSegment();
	  OpenKeyPad();

 	  while(1)
		{
			i = ScanKey();
			Show(i);
	  }
}