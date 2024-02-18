#include "TimeHandler.cpp"
#include<iostream>

using namespace std;

long double PiCalcLeibnitsv1(int prec, time_t time = 8640000) {
    timeHandler(time); // Time handler initialization

    long double pi = 0;
    long double prevpi;
    long long id = 1;

    while (run) {
        prevpi = pi;
        pi += 4.0l / id;
        pi -= 4.0l / (id + 2);
        id += 4;


        if (prevpi - pi == 0) break;

        timeHandler();
    }
    return pi;
}
// For now, to include your function in Compiled wrapper, you should include your file and then change function call on line 59 in CompiledPiCalculationTimed.cpp