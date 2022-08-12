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

void TMR1_IRQHandler(void)
{	
	PC14 = ~PC14;
	TIMER_ClearIntFlag(TIMER1); // Clear Timer1 time-out interrupt flag
}

void Init_Timer1(void)
{
  TIMER_Open(TIMER1, TMR1_OPERATING_MODE, 5);
  TIMER_EnableInt(TIMER1);
  NVIC_EnableIRQ(TMR1_IRQn);
  TIMER_Start(TIMER1);
}

int main(void)
{
  SYS_Init();
	init_LCD();
  clear_LCD();

	PD14 = 0;
	print_Line(0, "timer");
  Init_Timer1();

  while(1)
	{

	}
}