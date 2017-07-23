/*
	Created by Derek DeLizo 5/2/2017
*/
#include <vector>
#include <math.h>
using namespace std;

/*
	Pre Condition: size of a is bigger than 0
	Post Condition: Elements in an array are sorted in ascending order
*/
template <class Comparable>
void mergesortImproved(vector<Comparable> &a) {
	int size = a.size();
	vector<Comparable> b(size);		// this is only one temporary array.
	int spot = 0;					// Current index for next Element
	int aMin = 0;					// Lower Limit of 1st in-place array
	int aMax = 0;					// Upper Limit of 1st in-place array
	int bMin = 0;					// Lower Limit of 2nd in-place array
	int bMax = 0;					// Upper Limit of 2nd in-place array

	/*
		Changes the bounds of the array as the segments get sorted
	*/
	for (int i = 1; i < size; i = 2 * i) {
		for (int j = 0; j < size - i; j += 2 * i) {
			aMin = j;
			aMax = j + i - 1;
			bMin = aMax + 1;
			bMax = min(j + 2 * i - 1, size - 1);		//limits the max from passing the size of the array
			spot = j;

			while (aMin <= aMax && bMin <= bMax) {		//steps through both in-place arrays checking which element is smaller
				if (a[aMin] < a[bMin]) {
					b[spot] = a[aMin];
					spot++;
					aMin++;
				}
				else {
					b[spot] = a[bMin];
					spot++;
					bMin++;
				}
			}

			while (aMin <= aMax) {						//adds remaining elements to b if aMin still isn't aMax
				b[spot] = a[aMin];
				aMin++;
				spot++;
			}

			while (bMin <= bMax) {						//adds remaining elements to b if bMin still isn't bMax
				b[spot] = a[bMin];
				bMin++;
				spot++;
			}

			for (spot = j; spot <= bMax; spot++) {		//Copies elements in b to a
				a[spot] = b[spot];
			}

		}
	}
}
