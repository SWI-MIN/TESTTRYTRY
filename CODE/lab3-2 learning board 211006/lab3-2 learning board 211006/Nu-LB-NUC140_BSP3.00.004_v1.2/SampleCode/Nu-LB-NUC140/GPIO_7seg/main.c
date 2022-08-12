//
// GPIO_7seg : counting from 0 to 9999 and display on 7-segment LEDs
//
#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "Seven_Segment.h"

int main(void)
{
		uint8_t i = 0;
		uint8_t j = 5;

		SYS_Init();
		OpenSevenSegment();
	
		CloseSevenSegment();
		ShowSevenSegment(i,j);
		CLK_SysTickDelay(1000000);
		CloseSevenSegment();
		ShowSevenSegment(1,6);
		CLK_SysTickDelay(1000000);
		CloseSevenSegment();
		ShowSevenSegment(2,6);
		CLK_SysTickDelay(1000000);
		CloseSevenSegment();
}