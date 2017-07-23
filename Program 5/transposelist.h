/*
  Created By Derek DeLizo
*/

#ifndef TRANSPOSELIST_H
#define TRANSPOSELIST_H
#include <iostream>
#include "dlist.h"

using namespace std;

template<class Object>
class TransposeList : public DList<Object> {
 public:
  int find( const Object &obj ); //finds obj in the list and swaps it with previous
};

#include "transposelist.cpp.h"
#endif
