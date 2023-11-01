#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <chrono>
#include <math.h>

using namespace std;

int main()
{
    chrono::system_clock::time_point start, end;

 

    //printf("MainB Hello CPU\n");
    const int nn = 32768;
    const int n = (int)pow(nn,2);

    //std::cout << "MainB Hello CPU n=" << n  << std::endl;

    auto indata = std::make_unique<int[]>(n);
    //auto outdata = std::make_unique<int[]>(n);
    auto answer = std::make_unique<int[]>(n);
    
    std::cout << "MainB Hello CPU n=" << n << "nn=" << nn << std::endl;

    for (int i = 0; i < n; i++) indata[i] = rand() % 100;


    std::cout << "MainB Hello CPU n=" << n << "nn=" << nn << std::endl;
    //for (int i = 0; i < n; i++) outdata[i] = indata[i] * 2;
    start = chrono::system_clock::now();

    for (int i = 0; i < n; i++) answer[i] = indata[i] * 2;

    //clock_t end = clock();

    end = chrono::system_clock::now();
    double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
    std::cout  <<"Elapsed Time " << time << "[ms]"<< std::endl;

    //for (int i = 0; i < nn; i++) {
    //    std::cout << i <<"," << indata[i] <<"," << answer[i] << std::endl;
    //}
    printf("OK\n");

    //outdata.reset();
    indata.reset();
    answer.reset();
    return 0;
}