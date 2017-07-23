/*
  Created By Derek DeLizo
*/

/*
  Pre Condition: Constructor is called
  Post Condition: creates an empty SList
*/
template<class Object>
SList<Object>::SList( ) {
  init( );
}

/*
  Pre Condition: rhs is not null; is type SList
  Post Condition: create a new List from rhs
*/
template<class Object>
SList<Object>::SList( const SList &rhs ) {
  init( );
  *this = rhs;                                   // then assign rhs to this.
}

/*
  Pre Condition: SList constructor is called
  Post Condition: SList is given a generic outline
*/
template<class Object> 
void SList<Object>::init( ) {
  for ( int i = 0; i < LEVEL; i++ ) {  // for each level
    // create the left most dummy nodes;
    header[i] = new SListNode<Object>;
    header[i]->prev = NULL;
    header[i]->down = ( i > 0 ) ? header[i - 1] : NULL;
    header[i]->up = NULL;
    if ( i > 0 ) header[i - 1]->up = header[i];

    // create the right most dummy nodes;
    header[i]->next = new SListNode<Object>;
    header[i]->next->next = NULL;
    header[i]->next->prev = header[i];
    header[i]->next->down = ( i > 0 ) ? header[i - 1]->next : NULL;
    header[i]->next->up = NULL;
    if ( i > 0 ) header[i - 1]->next->up = header[i]->next;
  }

  // reset cost.
  cost = 0;
}

/*
  Pre Condition: SList is not NULL
  Post Condition: SList is deleted
*/
template<class Object>
SList<Object>::~SList( ) {
  clear( );                                      // delete items starting 1st
  for ( int i = 0; i < LEVEL; i++ ) {
    delete header[i]->next;                      // delete the right most dummy
    delete header[i];                            // delete the left most dummy
  }
}

/*
  Pre Condition: SList is not NULL
  Post Condition: 
*/
template<class Object>
bool SList<Object>::isEmpty( ) const {
  return ( header[0]->next->next == NULL );
}

/*
  Pre Condition:  SList is not NULL
  Post Condition: 
*/
template<class Object>
int SList<Object>::size( ) const {
  SListNode<Object> *p = header[0]->next; // at least the right most dummy
  int size = 0;

  for ( ; p->next != NULL; p = p->next, ++size );   
  return size;
}

/*
  Pre Condition:  SList is not NULL
  Post Condition: 
*/
template<class Object>
void SList<Object>::clear( ) {
  for ( int i = 0; i < LEVEL; i++ ) {        // for each level
    SListNode<Object> *p = header[i]->next;  // get the 1st item 
    while ( p->next != NULL ) {              // if this is not the left most
      SListNode<Object> *del = p;          
      p = p->next;                           // get the next item
      delete del;                            // delete the current item
    }

    header[i]->next = p;                     // p now points to the left most 
  }                                          // let the right most point to it
}

/*
  Pre Condition:  obj is of type Object
  Post Condition: Inserts obj in the correct position of the list.
                  If nextLevel = 1 it will be inserted in the levels above.
*/
template<class Object>
void SList<Object>::insert( const Object &obj ) {
  // right points to the level-0 item before which a new object is inserted.
  SListNode<Object> *right = searchPointer( obj );
  SListNode<Object> *left = right->prev;
  SListNode<Object> *up = NULL;
  int levelOn = 0;

  if ( right->next != NULL && right->item == obj )  
    // there is an identical object
    return;
    
  // Implement the rest by yourself
  SListNode<Object> *curr = new SListNode<Object>();          //Inserts obj in level 0 of the list
  curr->item = obj;
  curr->next = right;
  curr->prev = left;
  left->next = curr;
  right->prev = curr;
  double nextLevel = rand( ) % 2;
  
  while((nextLevel == 1) && (++levelOn < LEVEL)){            //While next level is one and the current level is lower than the max
    SListNode<Object> *nextUp = new SListNode<Object>();     //Insert obj in the same position on the next level
    while((left->prev != NULL) && (left->up == NULL)){
      left = left->prev;
    }
    left = left->up;
    right = left->next;
    nextUp->item = obj;
    
    nextUp->down = curr;
    curr->up = nextUp;
    
    nextUp->next = right;
    nextUp->prev = left;
    left->next = nextUp;
    right->prev = nextUp;
    
    curr = nextUp;
    nextLevel = rand( ) % 2;
  }  
}

/*
  Pre Condition: obj is of type Object
  Post Condition: returns true if obj is in the list and false if obj is not
*/
template<class Object> 
bool SList<Object>::find( const Object &obj ) {
  // p oints to the level-0 item close to a given object
  SListNode<Object> *p = searchPointer( obj );

  return ( p->next != NULL && p->item == obj );     // true if obj was found
}

/*
  Pre Condition: obj is of type Object
  Post Condition: returns the Node containing obj or the Node to the right of obj
*/
template<class Object>
SListNode<Object> *SList<Object>::searchPointer( const Object &obj ) {
  SListNode<Object> *p = header[LEVEL - 1];     // start from the top left
  while ( p->down != NULL ) {                   // toward level 0
    p = p->down;                                // shift down once
    cost++;

    if ( p->prev == NULL ) {                    // at the left most item
      if ( p->next->next == NULL )              // no intermediate items
        continue;
      else {                                    // some intermadiate items
        if ( p->next->item <= obj )             // if 1st item <= obj
          p = p->next;                          // shift right to item 1
        cost++;
      }
    }

    while ( p->next->next != NULL && p->next->item <= obj ) {
      // shift right through intermediate items as far as the item value <= obj
      p = p->next;
      cost++;
    }
  }

  // now reached the bottom. shift right once if the current item < obj
  if ( p->prev == NULL || p->item < obj ) {
    p = p->next;
    cost++;
  }
  return p; // return the pointer to an item >= a given object.
}

/*
  Pre Condition: obj is Object type
  Post Condition: removes the Node containing obj from the list
*/
template<class Object>
void SList<Object>::remove( const Object &obj ) {
  // p points to the level-0 item to delete
  SListNode<Object> *p = searchPointer( obj );
  int level = 0;
  // validate if p is not the left most or right most and exactly contains the
  // item to delete
  if ( p->prev == NULL || p->next == NULL || p->item != obj )
    return;

  // Implement the rest by yourself
  while(p->up != NULL){                 //Deletes the Node starting from the bottom until only p is left
    SListNode<Object> *temp = p;
    p = p->up;
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    temp->next = nullptr;
    temp->prev = nullptr;
    temp->up = nullptr;
    delete temp;
    
    
  }
  if(p->up == NULL){                  //Deletes p
    p->prev->next = p->next;
    p->next->prev = p->prev;
    p->up= nullptr;
    p->down= nullptr;
    p->next= nullptr;
    p->prev= nullptr;
    delete p;
  }
}

/*
  Pre Condition: 
  Post Condition: 
*/
template<class Object>
const SList<Object> &SList<Object>::operator=( const SList &rhs ) {
  if ( this != &rhs ) { // avoid self-assignment
    clear( );           // deallocate old items
    
    int index;
    SListNode<Object> *rnode;
    for ( index = 0, rnode = rhs.header[0]->next; rnode->next != NULL;
	  rnode = rnode->next, ++index )
      insert( rnode->item );

    cost = rhs.cost;
  }
  return *this;
}

/*
  Pre Condition: SList must not be NULL
  Post Condition: returns the value of cost
*/
template<class Object>
int SList<Object>::getCost( ) const {
  return cost;
}

/*
  Pre Condition: SList must not be NULL
  Post Condition: displays the skip list in the console
*/
template<class Object>
void SList<Object>::show( ) const {
  cout << "contents:" << endl;
  for ( SListNode<Object> *col = header[0]; col != NULL; col = col->next ) {
    SListNode<Object> *row = col;
    for ( int level = 0; row != NULL && level < LEVEL; level++ ) {
      if ( row->prev == NULL )
	cout << "-inf\t";
      else if ( row->next == NULL )
	cout << "+inf\t";
      else
	cout << row->item << "\t";
      row = row->up;
    }
    cout << endl;
  }
}

