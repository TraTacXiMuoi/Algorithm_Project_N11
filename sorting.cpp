#include "header_file.h"

//quick sort
int partition(int arr[], int first, int last, long long& cmpCnt){
    int left = first - 1;
    int right = last + 1;
    int pivot = arr[(first + last) / 2];
    while(true){
        do{
            left++;
        }while(++cmpCnt && arr[left] < pivot);

        do{
            right--;
        }while(++cmpCnt && arr[right] > pivot);
        
        if(++cmpCnt && left < right) swap(arr[left], arr[right]);
        else return right;
    }
}
void quickSort(int arr[], int start, int end, long long& cmpCnt){
    if(++cmpCnt && start >= end) return;
    int pos = partition(arr, start, end, cmpCnt);
    quickSort(arr, start, pos, cmpCnt);
    quickSort(arr, pos + 1, end, cmpCnt);
}
//insertion sort
void insertionSort(int arr[], int n, long long& cmpCnt)
{
    int i, key, j;
    for (i = 1; ++cmpCnt && i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        while ((++cmpCnt && j >= 0) && (++cmpCnt && arr[j] > key)) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
//shell sort
int shellSort(int arr[], int n, long long& cmpCnt) 
{ 
    for (int gap = n/2; ++cmpCnt && gap > 0; gap /= 2) 
    {  
        for (int i = gap; ++cmpCnt && i < n; i++) 
        { 
            int key = arr[i];
            int j;
            for (j = i; (++cmpCnt && j >= gap) && (++cmpCnt && arr[j - gap] > key); j -= gap)
                arr[j] = arr[j - gap]; 
            arr[j] = key; 
        } 
    } 
    return 0; 
}


//run for counting running-time and comparisons
// cac ham duoi se tra ve mot pair{running time, comparisons}
pair<int, int> runQuickSort(int arr[], int n){
    int* b = new int [n];
    for(int i = 0 ; i < n; i++) b[i] = arr[i];
    long long comparisons = 0;
    //measure running time and comparisons
    auto startTime = high_resolution_clock::now();
    quickSort(b, 0, n - 1, comparisons);
    auto endTime = high_resolution_clock::now();
    
    auto exe_time = duration_cast<milliseconds>(endTime - startTime);
    
    return {exe_time.count(), comparisons};
}
pair<int, int> runShellSort(int arr[], int n){
    int* b = new int [n];
    for(int i = 0 ; i < n; i++) b[i] = arr[i];
    long long comparisons = 0;
    //measure running time and comparisons
    auto startTime = high_resolution_clock::now();
    shellSort(b, n, comparisons);
    auto endTime = high_resolution_clock::now();
    
    auto exe_time = duration_cast<milliseconds>(endTime - startTime);
    
    return {exe_time.count(), comparisons};
}
pair<int, int> runInsertionSort(int arr[], int n){
    int* b = new int [n];
    for(int i = 0 ; i < n; i++) b[i] = arr[i];
    long long comparisons = 0;
    //measure running time and comparisons
    auto startTime = high_resolution_clock::now();
    insertionSort(b, n, comparisons);
    auto endTime = high_resolution_clock::now();
    
    auto exe_time = duration_cast<milliseconds>(endTime - startTime);
    
    return {exe_time.count(), comparisons};
}