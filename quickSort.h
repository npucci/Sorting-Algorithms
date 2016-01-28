#ifndef quickSort_h
#define quickSort_h

#include <vector>

using Val = int;
using Container = std::vector<Val>;
using Iter = long;

int quickSort(Container& arr, Iter start, Iter end);

#endif /* quickSort_h */