// Blink - By Kashouryo  Jan 5, 2020
// Always a good start for a new MCU huh?
// Just like Hello World but on a microcontroller

#include "STC/STC15.H"
#include "intrins.h"

sbit LED_0 = P1^0;
sbit LED_1 = P3^7;
sbit LED_2 = P3^6;
sbit LED_3 = P3^5;

void Delay500ms();

void main() {
    P1M1 = 0x00;
    P1M0 = 0x00;
    P3M1 = 0x00;
    P3M0 = 0x00;

    LED_0 = 0;
    LED_1 = 1;
    LED_2 = 0;
    LED_3 = 1;

    while (1)
    {
        LED_0 = 1;
        LED_1 = 0;
        LED_2 = 1;
        LED_3 = 0;
        Delay500ms();
        LED_0 = 0;
        LED_1 = 1;
        LED_2 = 0;
        LED_3 = 1;
        Delay500ms();
    }
    
}
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
