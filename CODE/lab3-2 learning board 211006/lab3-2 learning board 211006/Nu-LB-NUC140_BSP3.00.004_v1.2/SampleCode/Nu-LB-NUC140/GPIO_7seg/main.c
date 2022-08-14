//
// GPIO_7seg : counting from 0 to 9999 and display on 7-segment LEDs
//
#include <stdio.h>
#include <stdlib.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "Seven_Segment.h"

void LED_binary(int num){
	PC12 = 1;
	PC13 = 1;
	PC14 = 1;
	PC15 = 1;
	//CLK_SysTickDelay(5000);
	if(num>=8) { num-=8; PC12 = 0; }
	if(num>=4) { num-=4; PC13 = 0; }
	if(num>=2) { num-=2; PC14 = 0; }
	if(num>=1) { num-=1; PC15 = 0; }
}
void SevenSegment_0to9999(int num){
	while(num<10000){
		ShowSevenSegment(0,num%10);
		CLK_SysTickDelay(5000);
		CloseSevenSegment();
		ShowSevenSegment(1,num/10%10);
		CLK_SysTickDelay(5000);
		CloseSevenSegment();
		ShowSevenSegment(2,num/100%10);
		CLK_SysTickDelay(5000);
		CloseSevenSegment();
		ShowSevenSegment(3,num/1000);
		CLK_SysTickDelay(5000);
		CloseSevenSegment();
		
		num++;
		if(num == 10000){
			num = 0;
			CloseSevenSegment();
		}
	}
}

int main(void){
	SYS_Init();
	OpenSevenSegment();
	CloseSevenSegment();
	
	//uint8_t a = 0;// just leave it
	int i = 0;
	int j = 0;
	int question = 0;

	if(question == 1){
		i = 0;
		j = 0;
		while(1){
			// delay us, 1000000us == 1s
			LED_binary(j);
			ShowSevenSegment(i,j);
			CLK_SysTickDelay(1000000);
			if(j == 9){ j = 0; }
			else{ j++; }
		}
	}
	else if(question == 2){
		j = 0;
		SevenSegment_0to9999(j);
	}
}
