/*
  Created By Derek DeLizo 4/27/2017
  Student ID = 1420889
  Q = 1420889 % 3 = 2
  Q = 2
*/

#include <vector>

using namespace std;

template <class Comparable>
bool rightSorted(vector<Comparable> &a){
  int medianIndex = (a.size() + 1) / 2;
  bool sorted = false;
  for(int i = 0; i < medianIndex;i++){
    if(a[i] > a[i+1]){
      sorted = true;
    }
  }
  for(int j = medianIndex + 1; j < a.size(); j++){
    if(a[medianIndex] > a[j]){
      sorted = true;
    }
  }
  return sorted;
}

template <class Comparable>
void objectSwap( Comparable &lhs, Comparable &rhs ) {
  Comparable tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

template <class Comparable>
void choosePivot( vector<Comparable> &a, int first, int last ) {
  int middle = ( first + last ) / 2;
  objectSwap( a[first], a[middle] );
}

template <class Comparable>
void partition( vector<Comparable> &a, int first, int last, int &pivotIndex ){
  // place the pivot in a[first]
  choosePivot( a, first, last );
  Comparable pivot = a[first];
  int lastS1 = first;
  int firstUnknown = first + 1;
  
  for ( ; firstUnknown <= last; ++firstUnknown ) {
    if ( a[firstUnknown] < pivot ) {
      ++lastS1;
      objectSwap( a[firstUnknown], a[lastS1] );
    }
    // else item from unknown belongs in S2
  }
  // decide a new pivot
  objectSwap( a[first], a[lastS1] );
  pivotIndex = lastS1;
}

template <class Comparable>
void quicksort( vector<Comparable> &a, int first, int last ) {
  int pivotIndex;
  bool sorted = rightSorted(a);
  if ( first < last && sorted) {
    partition( a, first, last, pivotIndex);
    quicksort( a, first, pivotIndex - 1);
    quicksort( a, pivotIndex + 1, last);
  }
}



template <class Comparable>
void quicksort( vector<Comparable> &a ) {
  quicksort( a, 0, a.size( ) - 1 );
}

template <class Comparable>
void partialsort(vector<Comparable> &items){
  quicksort(items,0,items.size());
}


