template <class Object>
Deque<Object>::Deque( ) {                          // the constructor
  front = back = NULL;
}

template <class Object>
Deque<Object>::Deque( const Deque &rhs ) {         // the copy constructor
  front = back = NULL;
  *this = rhs;
}

template <class Object>
Deque<Object>::~Deque( ) {                         // the destructor
  clear( );
}

template <class Object>
bool Deque<Object>::isEmpty( ) const {             // check if a deque is empty
  return front == NULL;
}

template <class Object>
int Deque<Object>::size( ) const {                 // retrieves # deque nodes
  int i = 0;
  for ( DequeNode *ptr = front; ptr != NULL; ptr = ptr->next ) // traverse que
    ++i;

  return i;
}

template <class Object>
const Object &Deque<Object>::getFront( ) const {   // retrieve the front node
  if ( isEmpty( ) )
    throw "empty queue";
  return front->item;
}

template <class Object>
const Object &Deque<Object>::getBack( ) const {    // retrieve the tail node
  if ( isEmpty( ) )
    throw "empty queue";
  return back->item;
}

template <class Object>
void Deque<Object>::clear( ) {          // clean up all entries.
  while ( !isEmpty( ) )                 // dequeue till the queue gets empty.
    removeFront( );
}

template <class Object>
void Deque<Object>::addFront( const Object &obj ) {// add a new node to  front
  // Implement the function body.
  DequeNode *newPtr = new DequeNode();
  newPtr->item = obj;
  newPtr->prev = NULL;
  newPtr->next = front;
  if (isEmpty())
    back = newPtr;
  else{
    front->prev = newPtr;
  }
  
  front = newPtr;
}

template <class Object>
void Deque<Object>::addBack( const Object &obj ) { // add a new node to tail
  // Implement the function body.
  DequeNode *newBack = new DequeNode();
  newBack->item = obj;
  newBack->next = NULL;
  newBack->prev = back;
  if (isEmpty())
    front = newBack;
  else{
    back->next = newBack;
  }
  back = newBack;
}

template <class Object>
Object Deque<Object>::removeFront( ) {  // remove the front node
  // Implement the function body. 
  Object retVal = getFront();
  DequeNode *delPtr = front;
  front = front->next;
  delPtr->prev = NULL;
  delPtr->next = NULL;
  
  //If front is NULL then back also needs to be NULL
  if(front != NULL)
    front->prev = NULL;
  else
    back = NULL;
  delete delPtr;
  
  return retVal;
}

template <class Object>
Object Deque<Object>::removeBack( ) {   // remove the tail node
  // Implement the function body.
  Object retVal = getBack();
  DequeNode *delPtr = back;
  
  if(back->prev != NULL){
    back->prev->next = NULL;
    back = back->prev;
  } else {
    back = front = NULL;
  }
  
  delete delPtr;
  
  return retVal;
}

template <class Object>
const Deque<Object> &Deque<Object>::operator=( const Deque &rhs ) { // assign
  if ( this != &rhs ) { // avoid self assignment
    clear( );
    for ( DequeNode *rptr = rhs.front; rptr != NULL; rptr = rptr->next )
      addBack( rptr->item );
  }
  return *this;
}


