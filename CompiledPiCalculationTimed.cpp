#include <iostream>
#include <iomanip>

#include "PiCalculation/TimeHandler.cpp" // Do not remove. Following includes need it.

#include "PiCalculation/PiCalcVieta.cpp"  // PiCalcVieta
#include "PiCalculation/PiCalcVallis.cpp" // PiCalcVallisNumDenum, PiCalcVallisFloat
#include "PiCalculation/PiCalcLeibnits.cpp" // PiCalcLeibnitsv1


using namespace std;

char orpi[] = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989";

int verify(long double mypi) {
    if ((int) mypi != 3) {
        return -1;
    } else {
        mypi -= 3;
        int i = 0;
        int d;
        while (true) {
            mypi *= 10;
            d = (int) mypi;
            mypi -= d;
            if (d != ((int) orpi[i]) - 48) break;
            i++;
        }
        return i;
    }
}

void fancyOutput(long double pi, int prec) {
    cout << "\nValue of calculated pi to the " << prec << "th place = " << setprecision(prec + 1) << pi << "\n";
    int actualPrec = verify(pi);
    cout << "This method is accurate to " << actualPrec << "th place\n\n";
    cout << "Comparison of real value of pi and calculated to " << prec << "th place:\n";

    cout << "3.";
    for (int i = 0; i < prec; i++) cout << orpi[i];
    cout << "...\n";

    if (prec < actualPrec) {
        cout << "3.";
        for (int i = 0; i < prec; i++) cout << orpi[i];
    } else {
        cout << setprecision(actualPrec + 1) << pi << "|";
    }

    pi *= pow(10, actualPrec);
    pi -= (unsigned long long) pi;
    for (int i = 0; i < (prec - actualPrec); i++) {
        pi *= 10;
        cout << (unsigned long long) pi;
        pi -= (unsigned long long) pi;
    }
    cout << "...\n";
}

int main() {
    long double pi;
    int precision = 20;
    int time = 1; //Time is in seconds

    pi = PiCalcLeibnitsv1(precision, time); // For now, you should insert here PiCalc* function from PiCalculation folder

    fancyOutput(pi, precision);
}