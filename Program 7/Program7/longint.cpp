/*
	Created by Derek DeLizo 5/28/2017
*/

#include "longint.h"

/*
	Pre-Condition: the line is a string
	Post Condition: creates a longint from an input stream
*/
istream & operator>>(istream & in, LongInt & rhs){
  string input;
  getline(in,input);
  rhs = LongInt(input);
}

/*
	Pre-Condition: rhs isn't NULL
	Post Condition: outputs longint rhs with correct sign and no leading zero's
*/
ostream & operator<<(ostream & out, const LongInt & rhs){
  Deque<char> temp = rhs.digits;
	char leading;
	if((rhs.digits.size() == 1) && (rhs.digits.getFront() == '0')){
		cout << '0';
	} else {
		if(rhs.negative == true){						//checks if the longint is negative
		  out << '-';
		}
		leading = temp.removeFront();				//removes leading zero's first
		while(leading == '0'){
			leading = temp.removeFront();
		}
		out << leading;
		while(!(temp.isEmpty())){						//removes from the temp array until it is empty
		  out << temp.removeFront();
		}
  }
  return out;
}

/*
	Pre-Condition: str is a string
	Post Condition: creates a longint from a string
*/
LongInt::LongInt(const string str){
	int i = 0;
	negative = false;
	digits.clear();
  if(str[i] == '-'){
    negative = true;
    i = 1;
  }
  for(;i < str.length(); i++){
      if((str[i] >= '0') && (str[i] <= '9'))
        digits.addBack(str[i]);
  }
}

/*
	Pre-Condition: rhs is a LongInt
	Post Condition: copies the value of rhs to this
*/
LongInt::LongInt(const LongInt & rhs){
	digits.clear();
	digits = rhs.digits;
	negative = rhs.negative;  
}

/*
	Default constructor
	Pre-Condition: int has been intialized
	Post Condition: creates a longint = to 0
*/
LongInt::LongInt(){
  digits.clear();
  digits.addFront('0');
  negative = 0;
}

/*
	Deconstructor
	Pre-Condition: this must exist
	Post Condition: properly delets a longint
*/
LongInt::~LongInt(){
  digits.~Deque();
}


/*
	Pre-Condition: rhs is a real longint
	Post Condition: returns the sum of this and rhs
*/
LongInt LongInt::operator+(const LongInt & rhs) const{
	int carry = 0;
	int result = 0;
  LongInt sum;
  LongInt cleft = *this;
  LongInt cright = rhs;
	Deque<char> left = digits;
	Deque<char> right = rhs.digits;
	sum.digits.clear();
	
	//when they are different lengths then *this will always be the longest
	if(left.size() < right.size()){
		sum = rhs + *this;
	} else if(negative && rhs.negative){ 						//check if both this and rhs are negative
		cleft.negative = false;
		cright.negative = false;
		sum = cleft + cright;
		sum.negative = true;
	} else if(negative){													//checks if this is negative
		cleft.negative = false;
		sum = rhs - cleft;
	} else if(rhs.negative){											//checks if rhs is negative
		cright.negative = false;
		sum = *this - cright;
	} else {																			//as long as neither values are negative begin summing
	
		//sums the values until the highest digit of right is reached
		while(!(right.isEmpty())){
			int l = left.removeBack() - 48;
			int r = right.removeBack() - 48;
			result = (l + r + carry) % 10;
			carry = (l + r + carry) / 10;
			sum.digits.addFront(result + 48);
		}
		
		//if there is still a value to be carried then it is added to left
		while((carry > 0) && !(left.isEmpty())){
			int l = left.removeBack() - 48;
			result = (l + carry) % 10;
			carry = (l + carry) / 10;
			sum.digits.addFront(result + 48);
		}
		
		//for the case when 2 single digits are added to make a double digit
		//example: 1 + 9 = 10
		if(carry > 0){
			sum.digits.addFront(carry + 48);
		}
		
		//adds the remaining values of left to sum
		while(!(left.isEmpty())){
			char l = left.removeFront();
			sum.digits.addFront(l);
		}
	}
	return sum;
}

/*
	Pre-Condition: 
	Post Condition: 
*/
LongInt LongInt::operator-(const LongInt & rhs) const{
	int borrow = 0;
	int result = 0;
  LongInt diff;
	LongInt cleft = *this;
  LongInt cright = rhs;
	Deque<char> left = digits;
	Deque<char> right = rhs.digits;
	diff.digits.clear();
	if(left.size() < right.size()){
		diff = rhs + *this;
	} else if (negative && rhs.negative){			//-lhs - (-rhs) = rhs - lhs
		cleft.negative = false;
		cright.negative = false;
		diff = cleft - cright;
	} else if (negative){											//-lhs - rhs = -(lhs + rhs)
		cleft.negative = false;
		diff = cleft + cright;
		diff.negative = true;
	} else if (rhs.negative){									//lhs - (-rhs) = lhs + rhs
		cright.negative = false;
		diff = cleft + cright;
	} else if (*this < rhs){
		diff = cright - cleft;
		diff.negative = true;
	} else {
		int top = 0;
		int bottom = 0;
		while(!(left.isEmpty())){
			top = left.removeBack() - 48;
			if(!(right.isEmpty())){
				bottom = right.removeBack() - 48;
			} else {
				bottom = 0;
			}
			
			if(borrow == 1){
				top--;
				borrow--;
			}
			
			if(top < bottom && !(left.isEmpty())){
				top += 10;
				borrow++;
			}
			if((top - bottom) < 0 && left.isEmpty()){
				result = (top - bottom) * -1;
				diff.negative = true;
			} else {
				result = top - bottom;
			}
			diff.digits.addFront(result + 48);
			
		}
	}
	return diff;
}

/*
	Pre-Condition: rhs must be a longint
	Post Condition: assigns the value of rhs and return *this
*/
const LongInt & LongInt::operator=(const LongInt & rhs){
	digits = rhs.digits;
  negative = rhs.negative;
  return *this;
}

/*
	Pre-Condition: rhs is a longint
	Post Condition: returns true if this is < rhs; returns false otherwise
*/
bool LongInt::operator<(const LongInt & rhs) const
{
	bool retVal = true;
	if(*this == rhs){
		retVal = false;
	} else if(negative && rhs.negative){ 									//checks if both are negative
		LongInt left = *this;
		LongInt right = rhs;
		left.negative = false;
		right.negative = false;
		retVal = (left > right);
	} else if(negative){ 																//checks if this is negative
		retVal = true;
	} else if(rhs.negative){ 														//checks if rhs is negative
		retVal = false;
	} else {
		if(digits.size() == rhs.digits.size()){ 					//if they are the same length
			Deque<char> left = digits;											//then each digit needs to be compared
			Deque<char> right = rhs.digits;
			while(!(left.isEmpty()) && retVal == true){	
				int l = left.removeFront() - '0';
				int r = right.removeFront() - '0';
				if(l > r){
					retVal = false;
				}
			}
		} else if(digits.size() < rhs.digits.size()){	
			retVal = true;
		} else {																				
			retVal = false;
		}
	}
	return retVal;
}

/*
	Pre-Condition: rhs is a longint
	Post Condition: returns true if this <= rhs; returns false otherwise
*/
bool LongInt::operator<=(const LongInt & rhs) const
{
	bool retVal = false;
	if((*this == rhs) || (*this < rhs)){
		retVal = true;
	} else {
		retVal = false;
	}
	return retVal;
}

/*
	Pre-Condition: rhs is a longint
	Post Condition: returns true if this > rhs; returns false otherwise
*/
bool LongInt::operator>(const LongInt & rhs) const
{
	bool retVal = true;
	if(*this == rhs){
		retVal = false;
	} else if(negative && rhs.negative){								//checks if both are negative
		LongInt left = *this;
		LongInt right = rhs;
		left.negative = false;
		right.negative = false;
		retVal = (left < right);
	} else if(negative){																//checks if this is negative
		retVal = false;
	} else if(rhs.negative){ 														//checks if rhs is negative
		retVal = true;
	} else {
		if(digits.size() == rhs.digits.size()){
			Deque<char> left = digits;
			Deque<char> right = rhs.digits;
			for(int i = 0; i < left.size();i++){
				int l = left.removeFront() - '0';
				int r = right.removeFront() - '0';
				if(l < r){
					retVal = false;
				}
			}
		} else if(digits.size() > rhs.digits.size()){
			retVal = true;
		} else {
			retVal = false;
		}
	}
	return retVal;
}

/*
	Pre-Condition: checks if this >= rhs
	Post Condition: returns true if this >= rhs; returns false otherwise
*/
bool LongInt::operator>=(const LongInt & rhs) const
{
	bool retVal = false;
	if((*this == rhs) || (*this > rhs)){
		retVal = true;
	} else {
		retVal = false;
	}

	return retVal;
}

/*
	Pre-Condition: rhs is a longint
	Post Condition: checks if this == rhs; else returns false
*/
bool LongInt::operator==(const LongInt & rhs) const
{
	bool retVal = true;
	Deque<char> left = digits;
	Deque<char> right = rhs.digits;
	if(left.size() == right.size()){
		if(negative != rhs.negative){
			retVal = false;
		} else {
			while(!(left.isEmpty()) && retVal == true){
				int l = left.removeFront() - '0';
				int r = right.removeFront() - '0';
				if(l != r){
					retVal = false;
				}
			}
		}
	} else {
		retVal = false;
	}
	
	return retVal;
}

/*
	Pre-Condition: rhs is a longint
	Post Condition: checks if this != rhs; else returns false
*/
bool LongInt::operator!=(const LongInt & rhs) const
{
	return !(*this == rhs);
}

