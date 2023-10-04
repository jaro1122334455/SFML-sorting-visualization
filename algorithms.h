#pragma once
#include "line.h"
#include "setup.h"
#include <chrono>
#include<unistd.h>
#include <chrono>
#include <thread>


// int iter = 0;
// int limit = 800;

namespace algorithms
{
    bool ascendingCompare(float a, float b);
    bool descendingCompare(float a, float b);
    void bubbleSort(std::vector<Line>& lines, bool(*compareFuncPtr)(float, float));
    void bubbleSort_2(std::vector<Line>& lines);

}