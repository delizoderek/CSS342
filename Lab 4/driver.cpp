/*
  Created By Derek DeLizo 4/27/2017
  Student ID = 1420889
  Q = 1420889 % 3 = 2
  Q = 2
*/
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "partialsort.cpp"
using namespace std;

// initialize a given array with random numbers.
void initArray( vector<int> &array, int randMax ) {
  int size = array.size( );

  for ( int i = 0; i < size; ) {
    int tmp = ( randMax == -1 ) ? rand( ) : rand( ) % randMax;
    bool hit = false;
    for ( int j = 0; j < i; j++ ) {
      if ( array[j] == tmp ) {
        hit = true;
        break;
      }
    }
    if ( hit )
      continue;
    array[i] = tmp;
    i++;
  }
}

int main( int argc, char* argv[] ) {
  // verify arguments. if you find the median, no need of topK where argc == 2
  if ( argc != 3 ) {
    cerr << "usage: ./a.out size topK" << endl;
    return -1;
  }

  // verify an array size
  int size = atoi( argv[1] );
  if ( size <= 0 ) {
    cerr << "array size must be positive" << endl;
    return -1;
  }

  // verify top/bottom k. if you find the median, no need of the next 4 lines
  int topK = atoi( argv[2] );
  if ( topK <= 0 ) {
    cerr << "topX must be positive" << endl;
    return -1;
  }

  // array generation
  srand( 1 );
  vector<int> items( size );
  initArray( items, size );


  // partial quicksort. if you find the median, no need of the 2nd argument.
  partialsort(items);

  // print out the results here
  for(int i = 0; i < items.size();i++){
    cout << items[i] << " ";
  }
  cout << endl;

  return 0;
}