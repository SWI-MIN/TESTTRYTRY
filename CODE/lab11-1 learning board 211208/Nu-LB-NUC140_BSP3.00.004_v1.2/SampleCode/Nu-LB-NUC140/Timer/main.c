//
// TMR_LED : change LED on/off by Timer1 interrupt
//
#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include <math.h>
#include <string.h>
#include "LCD.h"

uint8_t ledState = 0;
uint32_t keyin = 0;
uint32_t i = 5;
uint32_t j = 0;
uint32_t x, y, z;

char Text[16];
uint32_t u32ADCvalue;

void Init_ADC(void)
{

}

void TMR1_IRQHandler(void)
{	

}

void Init_Timer1(void)
{

}

int main(void)
{
  SYS_Init();
	init_LCD();
  clear_LCD();

	PD14 = 0;
  Init_Timer1();
	Init_ADC();

  while(1)
	{
		if(keyin == 1)
		{

		}
		else if(keyin == 2)
		{

		}
		else if(keyin == 3)
		{

		}
	}
}