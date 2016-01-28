#ifndef insertionSort_h
#define insertionSort_h

#include <vector>

using Val = int;
using Container = std::vector<Val>;
using Iter = long;

int insertionSort(Container& arr, Iter start, Iter end);

#endif /* insertionSort_h */