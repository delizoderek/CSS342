template <class NumericType>
bool Tokenizer<NumericType>::getChar( char &ch ) {
  char tmp;

  // skip blanks
  while ( in.get( tmp ) && tmp == ' ' );

  // read a char 
  if ( in.good( ) && tmp != '\n'&& tmp != '\0' ) {
    ch = tmp;
    return true; // if it is not a delimiter
  }
  else
    return false; // if it's a delimitter
}

template <class NumericType>
Token<NumericType> Tokenizer<NumericType>::getToken( ) {

  char ch;
  char second;
  NumericType theValue;

  if ( getChar( ch ) == true ) {
    switch( ch ) {
    case '^': return EXP;
    case '/': return DIV;
    case '*': return MULT;
    case '(': return OPAREN;
    case ')': return CPAREN;
    case '~': return BIT_COMP;
    case '+': 
      if(prevToken == OPAREN){       //if the prevToken was ( then its a unary plus
        prevToken = UN_PLUS;
        return UN_PLUS;
      }else
        return PLUS;
    case '-':
      if(prevToken == OPAREN){       //if the prevToken was ( then its a unary minus
        prevToken = UN_MINUS;
        return UN_MINUS;
      }else 
        return MINUS;
    case '%': return MODULUS;
    case '!':                        //Peek ahead to see the next value
      second = in.peek();
      if(second == '='){
        getChar(second);
        return NOTEQUAL;
      } else {
        return NOT;
      }
    case '|' :
      second = in.peek();
      if(second == '|'){             //check to see if its || or bitwise |
        getChar(second);
        return LOG_OR;
      } else 
        return BIT_OR;
	  case '<' :
      second = in.peek(); 
      if(second == '<'){
        getChar(second);
        return SHIFT_R;
      }else if (second == '='){
        getChar(second);
        return LE;
      }else
        return LT;
	  case '>' :
       second = in.peek();
       if(second == '>'){
        getChar(second);
        return SHIFT_L;
      } else if (second == '='){
        getChar(second);
        return GE;
      } else
        return GT;
    case '=' :
        second = in.peek();
        if(second == '='){
          getChar(second);
          return EQUAL;
        } else {
          return ASSIGN;
        }
          
    case '&' :
      second = in.peek();
      if(second == '&'){             //check to see if its && or bitwise &
        getChar(second);
        return LOG_AND;
      } else
        return BIT_AND;

		case 'a':
      prevToken = VAR_A;
      return Token<NumericType>( VAR_A, 0 ); 

		case 'b':
      prevToken = VAR_B;
      return Token<NumericType>( VAR_B, 0 ); 

		case 'c':
      prevToken = VAR_C;
      return Token<NumericType>( VAR_C, 0 ); 

    default:
      in.putback( ch );
      if ( !( in >> theValue ) ) {
	      cerr << "Parse error" << endl;
	      return EOL;
      }
      return Token<NumericType>( VALUE, theValue );
    }
  }

  return EOL;
}
