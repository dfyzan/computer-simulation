#include<cmath>
#include<iostream>
#include<iomanip>

#include "TimeHandler.cpp"

using namespace std;

int BinaryEuclGCD(unsigned long long a, unsigned long long b) {
    if (a * b == 0) return a + b;
    if (a == b) return a;
    if ((a == 1) || (b == 1)) return 1;
    if (a % 2 == 0) {
        if (b % 2 == 0) {
            return (2 * BinaryEuclGCD(a / 2, b / 2));
        } else {
            return BinaryEuclGCD(a / 2, b);
        }
    } else {
        if (b % 2 == 0) {
            return (BinaryEuclGCD(a, b / 2));
        } else {
            if (b > a) {
                return BinaryEuclGCD(a, (b - a) / 2);
            } else {
                return BinaryEuclGCD((a - b) / 2, b);
            }
        }
    }
}

long double PiCalcVallisNumDenum(int prec, time_t time = 8640000) {
    unsigned long long num = 4;
    unsigned long long denum = 1;
    long double prevpi;
    int id = 1;

    int gcd = 1;

    while (true) {
        if (id % 2 == 0) {
            num *= (id + 2);
            denum *= (id + 1);
        } else {
            num *= (id + 1);
            denum *= (id + 2);
        }
        gcd = BinaryEuclGCD(num, denum);

        num /= gcd;
        denum /= gcd;

        // cout<<num<<" "<<denum<<" "<<(long double)(num)/denum<<" "<<id<<"\n";
        if (id == 30) prevpi = (long double) (num) / denum;
        if (id == 31) break; // 32 iteration is overflowing num and denum variables
        id++;
    }

    long double nextpi = (long double) (num) / denum;
    long double pi = (prevpi + nextpi) / 2;

    return pi;
}

long double PiCalcVallisFloat(int prec, time_t time = 8640000) {
    timeHandler(time);
    long double highpi;
    long double lowpi;
    long double prevpi;
    long double nextpi;
    int id = 1;

    long double pi = 4;

    while (run) {
        if (id % 2 == 0) {
            pi *= (id + 2);
            pi /= (id + 1);
            highpi = pi;
        } else {
            pi *= (id + 1);
            pi /= (id + 2);
            lowpi = pi;
        }

        prevpi = nextpi;
        nextpi = (lowpi + highpi) / 2;
        if (abs(prevpi - nextpi) == 0) break;
        id++;
        //cout<<setprecision(prec+1)<<nextpi<<" "<<id<<"\n";
        if (id % 100 == 0) timeHandler();
    }

//350k+ id to get 10th place

    return nextpi;
}