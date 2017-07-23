#include<iostream>

using namespace std;

template<class Object>
int MtfList<Object>::find( const Object &obj ) {
  DListNode<Object> *top = DList<Object>::header->next;
  DListNode<Object> *found = top;

  for ( ; found != NULL && found->item != obj;  found = found->next )
    ++DList<Object>::cost;

  if ( found == NULL )
    return -1; // not found

  if ( found == top )
    return 0;  // no need to move to front

  DListNode<Object> *p = found->prev;
  p->next = found->next;
  top->prev = found;
  DList<Object>::header->next = found;
  found->prev = DList<Object>::header;
  found->next = top;

  return 0;
    
}