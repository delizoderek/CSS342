/*
  Created By Derek DeLizo 5/14/2017
*/

/*
  Pre-Condition: obj must be an Object
  Post Condition: Once obj is found it will be swapped with its neighbor.
                  Will return -1 if obj isn't in list and 0 if obj is at top of list.
*/
template<class Object>
int TransposeList<Object>::find( const Object &obj ) {
  DListNode<Object> *found = DList<Object>::header->next;

  int i = 0;
  for ( ; found != NULL && found->item != obj;  found = found->next, ++i )
    ++DList<Object>::cost;

  if ( found == NULL )
    return -1; // not found

  if ( found == DList<Object>::header->next )
    return 0;  // no need to swap
  
  // remove found from the current position
  // insert found before previous
  DListNode<Object> *previous = found->prev;
  Object temp = previous->item;
  previous->item=found->item;
  found->item=temp;

  return i;
}