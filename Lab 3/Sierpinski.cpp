// Sierpinski member function definitions
#include "Sierpinski.h"

//------------------------- Sierpinski Arrowhead ----------------------------
Sierpinski::Sierpinski( float initX, float initY, float initAngle ) 
  : Turtle( initX, initY, initAngle ) {
}

//------------------------------ leftCurve ----------------------------------
// draw a level-l left curve with dist d
void Sierpinski::leftCurve( int level, float d ) {
  if ( level > 0 ) {
    level--;
	  rightCurve(level, d);
	  turn(60);
	  leftCurve(level, d);
	  turn(60);
	  rightCurve(level, d);
  }
  else
    draw( d );
}

//------------------------------ rightCurve ---------------------------------
// draw a level-l right curve with dist d
void Sierpinski::rightCurve( int level, float d ) {
  if ( level > 0 ) {
    level--;
	  leftCurve(level, d);
	  turn(-60);
	  rightCurve(level, d);
	  turn(-60);
	  leftCurve(level, d);
  }
  else
    draw( d );
}