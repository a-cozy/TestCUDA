#pragma once 
#include "CudaVecDouble.h"
#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include<iostream>
#include <chrono>
#include <math.h>

using namespace std;

int main()
{
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();

    //printf("MainA HelloGPU \n");
    const int nn = 32768;
    const int n = (int)pow(nn, 2);

    //a indata = std::make_unique<int[]>(n);
    //auto outdata = std::make_unique<int[]>(n);
    //auto answer = std::make_unique<int[]>(n);

    ////const int n = 100;
    int* in = new int[n];
    int* out = new int[n];
    //int *answer = new int[n];
    for (int i = 0; i < n; i++) in[i] = rand() % 100;

    start = chrono::system_clock::now();

    std::cout << "MainA Hello GPU n=" << n << "nn=" <<nn<< std::endl;

    //for (int i = 0; i < n; i++) in[i] = rand() % 100;
    //for (int i = 0; i < n; i++) answer[i] = in[i] * 2;

    vecDouble(in, out, n);

    end = chrono::system_clock::now();

    //clock_t end = clock();
    //const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    double time = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
    std::cout << "Elapsed time " << time << "[ms]" << std::endl;

    //for (int i = 0; i < n; i++) {
    //    std::cout << i%nn <<"," << in[i % nn] <<","<<out[i % nn]<< std::endl;
    //}
    printf("OK\n");

    delete[] in;
    delete[] out;
    //delete[] answer;

    return 0;
}