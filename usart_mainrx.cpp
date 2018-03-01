/********************************************************************************************/
/* Name:    mbed USART6 Rx program with mbed driven LCD.			 															*/
/* Purpose: This example shows a simple mbed USART Rx program.										  				*/
/*          It handles the reception continuously and shows the data on the LCD					 	  */
/* Author:    khalik.kasimov@student.manchester.ac.uk	  				  													*/
/********************************************************************************************/


#include  "mbed.h"
#include "C12832.h"

// Using Arduino pin notation
C12832 lcd (D11, D13, D12, D7, D10);
Serial usart (PA_11, PA_12); // tx, rx
DigitalOut redLED(PB_4);
AnalogIn sensor1 (A0);
AnalogIn sensor2 (A1);
AnalogIn sensor3 (A2);
AnalogIn sensor4 (A3);
AnalogIn sensor5 (A4);





int main()
{ int digit_value1, digit_value2;
	float voltage1, voltage2; 
	while(1) {
		digit_value1 = sensor1.read_u16(); // read the input voltage in the unsigned short
		voltage1 = sensor1.read();		// read the input voltage
		digit_value2 = sensor2.read_u16();
		voltage2 = sensor2.read();
		if(digit_value1 >2048)
			redLED = 0; 
		else 
			redLED = 1;
		lcd.printf("%.2fV    ", voltage1); // print the voltage in the lcd
		lcd.printf("%d\n ",digit_value1); // print the digital value in the lcd
		lcd.printf("%.2fV    ", voltage2);
		lcd.printf("%d\n ",digit_value2);
		wait(5);
		lcd.cls(); // clear the screen
		wait(1);
		
	}
}

	
	