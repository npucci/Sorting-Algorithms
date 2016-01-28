#ifndef mergeSort_h
#define mergeSort_h

#include <vector>

using Val = int;
using Container = std::vector<Val>;
using Iter = long;

int mergeSort(Container& arr, Iter start, Iter end);

#endif /* mergeSort_h */