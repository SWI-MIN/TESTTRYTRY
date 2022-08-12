//
// GPIO_7seg_keypad : 3x3 keypad inpt and display on 7-segment LEDs
//
#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "Seven_Segment.h"
#include "Scankey.h"
#include "LCD.h"

// display an integer on four 7-segment LEDs

int main(void)
{
		uint16_t i;
	
    SYS_Init();
		init_LCD();
		clear_LCD();

    OpenSevenSegment();
	  OpenKeyPad();
	
		PD14 = 0;

 	  while(1)
		{
			i = ScanKey();
			Display_7seg(i);
			print_Line(0, "Nu-LB-NUC140");
			print_Line(1, "1 3 5 7 9 ");
		}
}
