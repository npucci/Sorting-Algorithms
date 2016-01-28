#ifndef shellSort_h
#define shellSort_h

#include <vector>

using Val = int;
using Container = std::vector<Val>;
using Iter = long;

int shellSort(Container& arr, Iter start, Iter end);

#endif /* shellSort_h */