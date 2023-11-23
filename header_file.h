#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

int partition(int [], int , int, long long& );
void quickSort(int [], int , int , long long& );

void insertionSort(int [], int , long long& );

int shellSort(int [], int , long long& );

pair<int, int> runInsertionSort(int [], int);
pair<int, int> runShellSort(int [], int);
pair<int, int> runQuickSort(int [], int);