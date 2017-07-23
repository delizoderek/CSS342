/*
	Created by Derek DeLizo 04/19/2017
*/
#include <iostream>
#include <sys/time.h>
using namespace std;

int gettimeofday( struct timeval *tv, struct timezone *tz );

/*
	Pre-Condition: a and b are integers
	Post Condition: returns the greatest common denominator between a and b
	Base Case: when a equals 0 return b
	Recursive Case: Using euclids GCD algorithm call gcd with a = b % a and b = a
*/
int gcd(int a,int b) {
	if (a == 0) {
		return b;
	}
	else{
		gcd(b % a,a);
	}
}

/*
	Pre-Condition: a and b are integers
	Post Condition: returns the number of modulous operations to find the GCD
*/
int findCost(int a, int b){
  int cost = 0;
	while(a != 0){
		int r = a;
		a = b % a;
		cost++;
		b = r;
	}
	return cost;
}

/*
	Pre-Condition: i is an integer
	Post Condition: returns the a value the uses the most modulous operations
*/
int findA(int i){
	int aVal = 0;
	int costBig = 0;
	for(int w = 1; w <= i; w++){		//loops from 1 to i and finds the gcd(w,i) that uses the most modulous operations
		if(findCost(w,i) > costBig){
			costBig = findCost(w,i);
			aVal = w;
		}
	}
	return aVal;
}

/*
	Pre-Condition: No input
	Post Condition: returns 0 when program finishes; prints out the gcd, number of modulous operations and the time it takes
*/
int main() {
	int n = 0;									//The number of inputs
	int bigCost = 0;							//The largest number of modulous operations
	int a = 0;									//The current a value for the most modulous operations
	int b = 0;									//The current b value for the most modulous operations
	int useconds;
	struct timeval begin;
	struct timeval end;
	cin >> n;
	for(int i = 8; i <= n; i+= 200){			//loops from 8 to n and increments by 200
		gettimeofday(&begin,NULL);				//Gets initial time stamp
			int tempA = findA(i);
			if(findCost(tempA,i) > bigCost){
				bigCost = findCost(tempA,i);
				a = tempA;
				b = i;
			}
		gettimeofday(&end,NULL);				//Gets end time stamp
		useconds = (end.tv_usec - begin.tv_usec);
		
		cout << "At i = " << i << " gcd(" << a << "," << b << ") = ";
		cout << gcd(a,b);
		cout << " took " << bigCost << " modulous operations in " << useconds << " us" << endl;
		cerr << n << "," << bigCost << "," << useconds << endl;
	}
	return 0;
}
