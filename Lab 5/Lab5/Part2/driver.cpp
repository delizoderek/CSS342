#include <iostream>
#include <string>
#include "transposelist.h"

using namespace std;

int main( ) {
  TransposeList<string> facultyList;
  
  facultyList.insert( "berger", 0 );
  facultyList.insert( "cioch", 0 );
  facultyList.insert( "fukuda", 0 );
  facultyList.insert( "stiber", 0 );

  cerr << "#faculty members: " << facultyList.size( ) << endl;
  for ( int i = 0; i < facultyList.size( ); i++ )
    cerr << facultyList.retrieve( i ) << endl;

  cerr << endl;
  facultyList.remove( "cioch" );

  cerr << "#faculty members: " << facultyList.size( ) << endl;
  for ( int i = 0; i < facultyList.size( ); i++ )
    cerr << facultyList.retrieve( i ) << endl;

  cerr << endl;
  facultyList.find( "berger" );

  cerr << "#faculty members: " << facultyList.size( ) << endl;
  for ( int i = 0; i < facultyList.size( ); i++ )
    cerr << facultyList.retrieve( i ) << endl;
}
