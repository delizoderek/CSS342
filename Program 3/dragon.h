/*
	Created By Derek DeLizo 4/25/2017
*/
#ifndef DRAGON_H
#define DRAGON_H

#include "Turtle.h"
#include <iostream>
#include <math.h>
using namespace std;

class Dragon : Turtle {
public:
  Dragon( float initX=0.0, float initY=0.0, float initAngle=0.0 );				//Default Constructor initX = initY = initAngle = 0.0
  void leftCurve( int l, float d );  											//Draws a level-l left curve with dist d
  void rightCurve( int l, float d ); 											//Draws a level-l left curve with dist d
};
#endif