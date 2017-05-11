/**
 * Main file for testing different movement things for motors
 *	Author: Robin Johnsson, Viktor Malmgren, Daniel M
 *
 */
#include <asf.h>
#include <inttypes.h>
#include <stdio_serial.h>
#include "consoleFunctions.h"
#include "conf_board.h"
#include "motorFunc.h"
#include "distanceSensor.h"
#include "pulseCounterHandler.h"
#include "buttonInterrupt.h"
#include "Hjulreglering.h"
#include "navigation.h"


int main (void)
{
	sysclk_init();
	board_init();
	configureConsole();
	
	
	//Makes pin 24 on the Due-board an output
	ioport_set_pin_dir(pin24,IOPORT_DIR_OUTPUT);
	
	
	ioport_set_pin_dir(trig,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(echo, IOPORT_DIR_INPUT);
	pulseCounter_configA(ID_PIOC, PIOC, PIO_PC28);
	pulseCounter_configB(ID_PIOC, PIOC, PIO_PC23);
	
	//Starts with a delay simply to reduce the chance of an error occuring when reseting the program.
	delay_ms(2000);

	
	//	Loop that runs the functions called upon from the "motorFunc.h" file
	//	It is recommended that the "stop()" function is called between different sets of commands ex:
	//	forwardDrive, then stop, then reverseDrive.
	//	DO NOT go: forwardDrive into reverseDrive	
	//	This is to ensure that the motors don't get damaged.
	
	double fool = distanceToPosition(0);
	int angleValue = angleToPos();
	printf("angleValue111: %d\n",angleValue);
	
	uint8_t foo = 0;
	int degreesToPos;
	double tempVariabel = 0;
	while(foo<4){
		
		valuesCalc(foo);
		degreesToPos = angleToPos();
		rotationChooser(degreesToPos);
		double testVer = distanceToPosition(foo);
		while (testVer>30.0){
			//printf("distance: %d\n", testVer);
			delay_ms(500);
			int ek = counterA-counterB;
			tempVariabel = counterA*1.355;
			reglerahjul3(ek);
			updatePos(tempVariabel);
			tempVariabel = 0;
			testVer = distanceToPosition(foo);
			
		}
		delay_ms(8);
		foo++;
		stop();
	} 
	
	return 0;
}