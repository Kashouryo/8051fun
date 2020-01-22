// Sigment with shift register - By Kashouryo  Jan 21, 2020
// Let's display some numbers shall we?
// You are a 42 guy or a 69420 guy?



#include "STC/STC15.h"
#include "intrins.h"

unsigned char ct;
unsigned int lmao;

sbit HC595_SRCLK = P1^0;
sbit HC595_RCLK = P3^7;
sbit HC595_SER = P3^6;

void send595(unsigned char dat);
void delay20ms();

void delay20ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 1;
	j = 234;
	k = 113;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void send595(unsigned char dat){
	unsigned char i;
	for(i=0;i<8;i++){
		if(dat & 0x80){
			HC595_SER = 1;
		}else{
			HC595_SER = 0;
		}
		HC595_SRCLK = 1;
		HC595_SRCLK = 0;
		dat = dat << 1;
	}
}

void setup() {
  // put your setup code here, to run once:
	P1M1 = 0x00;
	P1M0 = 0x00;
	P3M0 = 0x00;
	P3M1 = 0x00;
	
}

void loop() {
	// put your main code here, to run repeatedly:
	for(lmao = 0; lmao<30;lmao++){ //6
		delay20ms();
		send595(0x7f);
		send595(0x7d);
		HC595_RCLK = 1;
		HC595_RCLK = 0;
	}for(lmao = 0; lmao<30;lmao++){ //9
		delay20ms();
		send595(0x7f);
		send595(0x6f);
		HC595_RCLK = 1;
		HC595_RCLK = 0;
	}for(lmao = 0; lmao<30;lmao++){ //4
		delay20ms();
		send595(0x7f);
		send595(0x66);
		HC595_RCLK = 1;
		HC595_RCLK = 0;
	}for(lmao = 0; lmao<30;lmao++){ //2
		delay20ms();
		send595(0x7f);
		send595(0x5b);
		HC595_RCLK = 1;
		HC595_RCLK = 0;
	}for(lmao = 0; lmao<30;lmao++){ //0
		delay20ms();
		send595(0x7f);
		send595(0x3f);
		HC595_RCLK = 1;
		HC595_RCLK = 0;
	}
	
}

// Main function - Do not modify!
void main(){
	setup();
	while(1){
		loop();
	}

}