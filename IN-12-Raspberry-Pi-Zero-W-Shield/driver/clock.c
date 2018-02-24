#include <unistd.h>
#include <wiringPi.h>
#include <sr595.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

// 74HC595 pinout
// pin 14: SER/DS
// pin 12: RCLK/STCP
// pin 11: SRCLK/SHCP

#define SRCLK 0 // GPIO 17
#define RCLK 2 // GPIO 27
#define SER 3 // GPIO 22

#define BASE_PIN 100
#define NUM_PINS 24
#define NUM_DIGITS 6
#define K155ID1_INPUTS 4 

unsigned char DIGIT[10][K155ID1_INPUTS] = {
{0,0,0,0},
{1,0,0,0},
{0,1,0,0},
{1,1,0,0},
{0,0,1,0},
{1,0,1,0},
{0,1,1,0},
{1,1,1,0},
{0,0,0,1},
{1,0,0,1}
};

unsigned char BUFFER[NUM_DIGITS*K155ID1_INPUTS] = {
0,0,0,0,
0,0,0,0,
0,0,0,0,
0,0,0,0,
0,0,0,0,
0,0,0,0,
};


void testDigit(int pos, int value)
{
	digitalWrite(pos++, DIGIT[value][0]);
	digitalWrite(pos++, DIGIT[value][1]);
	digitalWrite(pos++, DIGIT[value][2]);
	digitalWrite(pos++, DIGIT[value][3]);
}


void mapTimeToBuffer(int rmdr)
{
	int dvsr;
	int quot;
    	dvsr = 100000;
    
	int index = 0;	
	while(dvsr)
	{                     
        	quot = rmdr / dvsr;
         	BUFFER[index] = DIGIT[quot][0];
         	BUFFER[index+1] = DIGIT[quot][1];
         	BUFFER[index+2] = DIGIT[quot][2];
         	BUFFER[index+3] = DIGIT[quot][3];
		index += 4;		
		rmdr %= dvsr;
        	dvsr /= 10;
    	}
}

int main(void)
{
	wiringPiSetup();
 	sr595Setup (BASE_PIN, NUM_PINS, SER, SRCLK, RCLK);
	int base = BASE_PIN;

	for (int number=0; number < 999999; number++)
	{	
		struct timeval tv;
 		struct tm* ptm;
 		gettimeofday (&tv, NULL);
 		ptm = localtime (&tv.tv_sec);

		mapTimeToBuffer((ptm->tm_hour+1)*10000+ptm->tm_min*100+ptm->tm_sec);
		for (int i=0; i<NUM_DIGITS*K155ID1_INPUTS; i++)
		{
			digitalWrite(base+i, BUFFER[i]);
		
			delay(2);
		}
	}	
	return 0;
}
