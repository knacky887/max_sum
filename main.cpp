// #include "FindMax_optimized.h"
// #include "FindMax.h"
#include "FindMax_two_pointers.h"
#include <iostream>
#include <chrono>


int main(int argc, char * argv[]){

    using std::chrono::high_resolution_clock;
    using std::chrono::duration;
    using std::chrono::milliseconds;


    time_t start, end;
    /* Test cases used :

    {4, 3, 2, 1} = -2
    {1, 2, 3, 4} = 2
    {0, 0, 0, 5, 4} = 5
    {1, 1, 1, 1, 1} = 0
    {2, 9, 10, 1, 30, 45} = 52 
    {1, 44, -2, -5, 1, 44} = 92
    {1, 44, 44, 1, 1, 44} = 86
    {2, 2, 2, 9, 1, 45, 1, 45} = 88
    {3,1, 0 ,3,1} = 1
    {1,30,1,1, 1,1,1,1} = 29
    {1,30,1,30, 1,1,1,1} = 58
    {1,30,1,30 ,32,1,1} = 60
    {200,1,3,1,2} = 3
    std::vector<int> arr2(100000, 1);

    */
    
    std::vector<int> arr = {2, 9, 10, 1, 30, 45};

    auto t1 = high_resolution_clock::now();
    std::cout << utils::find_max(arr) << std::endl;
    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";

}