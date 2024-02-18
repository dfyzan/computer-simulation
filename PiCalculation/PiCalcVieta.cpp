#include<cmath>
#include<iostream>
#include<iomanip>

#include "TimeHandler.cpp"

using namespace std;

long double PiCalcVieta(int prec, time_t time = 8640000) {
    //extern run = true;
    long double pi = sqrt(2) / 2;
    long double buf = 0;
    long double cur = pi;

    timeHandler(time);

    while (run) {
        cur *= 2;
        cur += 2;
        cur = sqrt(cur);
        cur /= 2;

        buf = pi;
        pi *= cur;
        //cout<<setprecision(prec)<<pi<<" "<<setprecision(prec)<<cur<<" \n";
        if (pi - buf == 0) break;

        timeHandler();
    }
    pi /= 2;
    pi = powl(pi, -1);
    return pi;
}

