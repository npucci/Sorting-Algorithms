/*	Algorithm:	Quick Sort
*	Author:		Niccolo Pucci
*	Date:		November 2, 2015
*	Purpose:	Sorts a vector using Quick Sort.
*/

#include "quickSort.h"
#include <stdexcept>

/*----------------------------QUICK SORT----------------------------*/
//	Parameter:	Parameter arr holds the elements to be sorted, start and end defines the interval to sort: [start, end).
//	Postcondition:	Returns the number of comparison operations used as the basis of the Sorting Decision.
//	Sorting Decision:	Deciding which partition in which to place an item (based on its comparison to the pivot value).
//	Worst Case Performance:	O(n^2) - Quadratic
Container quickSort(Container& arr, Iter start, Iter end, int& count) {
	int size = arr.size();
	if (size <= 1) {
		return arr;
	}
	Container lower;
	Container equal;
	Container upper;
	Val pivot = arr[end - 1];

	for (int i = start; i < end; ++i) {
		if (arr[i] < pivot) {
			lower.push_back(arr[i]);
		}
		else if (arr[i] > pivot) {
			upper.push_back(arr[i]);
		}
		else {
			equal.push_back(arr[i]);
		}
		++count;
	}

	Container sortedLower;
	Container sortedUpper;
	sortedLower = quickSort(lower, 0, lower.size(), count);
	sortedUpper = quickSort(upper, 0, upper.size(), count);
	int lSize = sortedLower.size();
	int eSize = equal.size();
	int uSize = sortedUpper.size();

	Container sorted;
	for (int i = 0; i < lSize; ++i) {
		sorted.push_back(sortedLower[i]);
	}
	for (int i = 0; i < eSize; ++i) {
		sorted.push_back(equal[i]);
	}
	for (int i = 0; i < uSize; ++i) {
		sorted.push_back(sortedUpper[i]);
	}

	return sorted;
}

int quickSort(Container& arr, Iter start, Iter end) {
	int arrSize = arr.size();
	if (start > end || end > arrSize || start < 0) throw std::runtime_error("Error - Invalid start and end iterators.\n");

	int count = 0;
	int interval = end - start;
	Container sorted;

	// Base Cases:
	if (interval == 0 || interval == 1) {
		return count;
	}

	else {
		Container lower;
		Container equal;
		Container upper;
		Val pivot = arr[end - 1];

		for (int i = start; i < end; ++i) {
			if (arr[i] < pivot) {
				lower.push_back(arr[i]);
			}
			else if (arr[i] > pivot) {
				upper.push_back(arr[i]);
			}
			else {
				equal.push_back(arr[i]);
			}
			++count;
		}

		Container sortedLower;
		Container sortedUpper;
		sortedLower = quickSort(lower, 0, lower.size(), count);
		sortedUpper = quickSort(upper, 0, upper.size(), count);
		int lSize = sortedLower.size();
		int eSize = equal.size();
		int uSize = sortedUpper.size();

		for (int i = 0; i < lSize; ++i) {
			sorted.push_back(sortedLower[i]);
		}
		for (int i = 0; i < eSize; ++i) {
			sorted.push_back(equal[i]);
		}
		for (int i = 0; i < uSize; ++i) {
			sorted.push_back(sortedUpper[i]);
		}
	}

	for (int i = 0; i < arr.size(); ++i) {
		arr[i] = sorted[i];
	}
	return count;
}