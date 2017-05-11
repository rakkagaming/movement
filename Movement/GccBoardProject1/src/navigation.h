/*
 * navigation.h
 *
 * Created: 03/05/2017 09:00:19
 *  Author: Robin_2
 */ 


#ifndef NAVIGATION_H_
#define NAVIGATION_H_
#include <inttypes.h>
#include <math.h>
#include <stdio_serial.h>
#include "motorFunc.h"

#define sock_x 200
#define sock_y 0
#define glass_x 0
#define glass_y 400
#define cube_x 300
#define cube_y 400
#define dropOff_x 400
#define dropOff_y 300
#define PI 3.141592

extern uint16_t x1_pos;
extern uint16_t y1_pos;

void initNav(void);
void callForData(uint16_t,uint16_t);
void calcMidPos(void);
double distanceToPosition(uint8_t obj);
void updatePos(double hyp);
int angleToPos(void);
void valuesCalc(uint8_t obj);
void updateAngle(void);
void angleCheck(void);
void rotationChooser(int degreesToPos);


#endif /* NAVIGATION_H_ */