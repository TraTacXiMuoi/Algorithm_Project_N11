#include <iostream>
#include <fstream>
#include "header_file.h"
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL));
    ofstream writer("D:/second_year_HCMUS/DataStructureAndAlgorithm/Lab03/data.txt");
    for(int i = 1; i < 100000; i++){
        writer << rand() % 1000 + 1 << ", ";
    }
    writer.close();
}