/*
	Created by Derek DeLizo 4/25/2017
*/
#include "dragon.h"

/*
	Pre Condition: Turtle.h is in the same folder; initX, initY, and initAngle are all floats
	Post Condition: intializes Dragon as a Turtle
*/
Dragon::Dragon( float initX, float initY, float initAngle ) 
  : Turtle( initX, initY, initAngle ) {
}

/*
	Pre Condition: level is an int, and d is a float
	Post Condition: Draws the left curve at any level using length d
*/
void Dragon::leftCurve( int level, float d ) {
  if ( level > 0 ) {
    level--;
	  leftCurve(level,d);
	  turn(90);
	  rightCurve(level, d);
	  turn(90);
  }
  else
    draw( d );
}

/*
	Pre Condition: level is an int, and d is a float
	Post Condition: Draws the right curve at any level using length d
*/
void Dragon::rightCurve( int level, float d ) {
  if ( level > 0 ) {
    level--;
    turn(-90);
	  leftCurve(level, d);
	  turn(-90);
	  rightCurve(level, d);
  }
  else
    draw( d );
}