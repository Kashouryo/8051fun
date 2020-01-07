// Blink with Array - By Kashouryo  Jan 7, 2020
// You finally look like a legit 8051 learner!
// The fun has just begun...


#include "STC/STC15.h"
#include "intrins.h"


#define LEDs P3

unsigned char code coolBlinks[] = { //The pattern that we want to use.
0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe
};

int i = 0;
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
	for(i=0;i<7;i++){
		LEDs = coolBlinks[i];
		Delay500ms();
	}
}



// Main function - Do not modify!
void main(){
	setup();
	while(1){
		loop();
	}

}