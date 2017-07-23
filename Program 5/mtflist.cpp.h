/*
  Created By Derek DeLizo
*/

/*
  Pre Condition: SList is not NULL; obj is type Object
  Post Condition: finds obj then inserts the node between top and header
*/
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
    
  // remove found from the current position
  // insert found between header and top
  if(found->prev !=NULL){
    found->prev->next = found->next;
  }
  if(found->next != NULL){
    found->next->prev = found->prev;
  }
  found->next = top;
  found->prev = DList<Object>::header;
  DList<Object>::header->next = found;
  top->prev = found;
  return 0;
    
}