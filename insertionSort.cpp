/*	Algorithm:	Insertion Sort
*	Author:		Niccolo Pucci
*	Date:		November 2, 2015
*	Purpose:	Sorts a vector using Insertion Sort. 
*/

#include "insertionSort.h"
#include <stdexcept>

/*----------------------------INSERTION SORT----------------------------*/
//	Parameter:	Parameter arr holds the elements to be sorted, start and end defines the interval to sort: [start, end).
//	Postcondition:	Returns the number of comparison operations used as the basis of the Sorting Decision.
//	Sorting Decision:	Deciding whether to move the current item down.
//	Worst Case Performance:	O(n^2) - Quadratic
int insertionSort(Container& arr, Iter start, Iter end) {
	int size = arr.size();
	if (start > end || end > size || start < 0) throw std::runtime_error("Error - Invalid start and end iterators.\n");

	int interval = end - start;
	int count = 0;

	// Base Cases:
	if (interval == 0 || interval == 1) {
		return count;
	}

	else {
		for (int i = start; i < end; ++i) {
			Val current = arr[i];
			int j = i - 1;
			bool flag = false;
			while (j >= 0 && arr[j] > current) {
				arr[j + 1] = arr[j];
				j -= 1;
				arr[j + 1] = current;
				if (flag == true) {
					++count;
				}
				else flag = true;
			}

			++count;
		}
	}
	return count;
}