/*	Algorithm:	Merge Sort
*	Author:		Niccolo Pucci
*	Date:		November 2, 2015
*	Purpose:	Sorts a vector using Merge Sort.
*/

#include "mergeSort.h"
#include <stdexcept>

/*----------------------------MERGE SORT----------------------------*/
//	Parameter:	Parameter arr holds the elements to be sorted, start and end defines the interval to sort: [start, end).
//	Postcondition:	Returns the number of comparison operations used as the basis of the Sorting Decision.
//	Sorting Decision:	Deciding which item to merge next from the two subsequences.
//	Worst Case Performance:	O(n log n) - n log n
Container mergeArr(Container& firstHalf, Container& secondHalf, int& count) {
	Container mergedArr;
	int x = 0;
	int y = 0;
	int fSize = firstHalf.size();
	int sSize = secondHalf.size();

	while ((x < fSize) && (y < sSize)) {
		if (firstHalf[x] <= secondHalf[y]) {
			mergedArr.push_back(firstHalf[x]);
			++x;
		}
		else {
			mergedArr.push_back(secondHalf[y]);
			++y;
		}
		++count;
	}
	while (x < fSize) {
		mergedArr.push_back(firstHalf[x]);
		++x;
	}
	while (y < sSize) {
		mergedArr.push_back(secondHalf[y]);
		++y;
	}
	return mergedArr;
}

Container divideArr(Container& arr, int& count) {
	int size = arr.size();
	if (size <= 1) {
		return arr;
	}
	Container firstHalf;
	Container secondHalf;
	for (int i = 0; i < size; ++i) {
		if (i < size / 2) {
			firstHalf.push_back(arr[i]);
		}
		else secondHalf.push_back(arr[i]);
	}

	firstHalf = divideArr(firstHalf, count);
	secondHalf = divideArr(secondHalf, count);

	Container mergedArr = mergeArr(firstHalf, secondHalf, count);
	return mergedArr;
}

Container divideArr(Container& arr, Iter start, Iter end, int& count) {
	int size = end - start;
	if (size <= 1) {
		Container sortedArr{ arr[start] };
		return arr;
	}
	Container firstHalf;
	Container secondHalf;
	int j = 0;
	for (int i = start; i < end; ++i) {
		if (j < (size / 2)) {
			firstHalf.push_back(arr[i]);
		}
		else secondHalf.push_back(arr[i]);
		++j;
	}

	firstHalf = divideArr(firstHalf, count);
	secondHalf = divideArr(secondHalf, count);

	Container mergedArr = mergeArr(firstHalf, secondHalf, count);
	return mergedArr;
}

int mergeSort(Container& arr, Iter start, Iter end) {
	int arrSize = arr.size();
	if (start > end || end > arrSize || start < 0) throw std::runtime_error("Error - Invalid start and end iterators.\n");

	int count = 0;
	int interval = end - start;

	// Base Cases:
	if (interval == 0 || interval == 1) {
		return count;
	}

	else { 
		Container sorted = divideArr(arr, start, end, count);
		for (int i = 0; i < arr.size(); ++i) {
			arr[i] = sorted[i];
		}
	}

	return count;
}