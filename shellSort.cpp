/*	Algorithm:	Shell Sort
*	Author:		Niccolo Pucci
*	Date:		November 2, 2015
*	Purpose:	Sorts a vector using Shell Sort.
*/

#include "shellSort.h"
#include <stdexcept>

/*----------------------------SHELL SORT----------------------------*/
//	Parameter:	Parameter arr holds the elements to be sorted, start and end defines the interval to sort: [start, end).
//	Postcondition:	Returns the number of comparison operations used as the basis of the Sorting Decision.
//	Sorting Decision: 
//	Worst Case Performance:	O(n^2) - Quadratic
void arrSwap(Val& x, Val& y) {
	Val temp = x;
	x = y;
	y = temp;
}

void gapInsertionSort(Container& arr, Iter start, int position, int gap, int size, int& count) {
	for (int j = position; (j - gap) >= start && arr[j] < arr[j - gap]; j -= gap) {
		arrSwap(arr[j], arr[j - gap]);
		++count;
	}
}

void shellSort(Container& arr, Iter start, Iter end, int gap, int size, int& count) {
	if (gap <= 0) return;

	for (int i = start; i < (end - gap); ++i) {
		if (arr[i] > arr[i + gap]) {
			arrSwap(arr[i], arr[i + gap]);
			gapInsertionSort(arr, start, i, gap, size, count);
		}
		++count;
	}

	gap = gap / 2;
	shellSort(arr, start, end, gap, size, count);
}

int shellSort(Container& arr, Iter start, Iter end) {
	int size = arr.size();
	if (start > end || end > size || start < 0) throw std::runtime_error("Error - Invalid start and end iterators.\n");

	int count = 0;
	int interval = end - start;

	// Base Cases:
	if (interval == 0 || interval == 1) {
		return count;
	}

	else {

		int gap = size / 2;

		for (int i = start; i < (end - gap); ++i) {
			if (arr[i] > arr[i + gap]) {
				arrSwap(arr[i], arr[i + gap]);
				gapInsertionSort(arr, start, i, gap, size, count);
			}
			++count;
		}

		gap = gap / 2;
		shellSort(arr, start, end, gap, size, count);
	}

	return count;
}