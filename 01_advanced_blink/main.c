// Advanced Blink - By Kashouryo  Jan 6, 2020
// Arduino won't teach you how to manipulate ports like this in its tutorial.
// Because it's way easier to this on an 8051 compared to an AVR!

#include "STC/STC15.h"
#include "intrins.h"


#define LEDs P3

void Delay500ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 23;
	j = 205;
	k = 120;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void setup() {
  // put your setup code here, to run once:
	P3M0 = 0x00;
	P3M1 = 0x00;
	
	LEDs = 0x00;
	
}

void loop() {
  // put your main code here, to run repeatedly:
	LEDs = 0x55; //01010101
	Delay500ms();
	LEDs = 0xAA; //10101010
	Delay500ms();
}



// Main function - Do not modify!
void main(){
	setup();
	while(1){
		loop();
	}

}