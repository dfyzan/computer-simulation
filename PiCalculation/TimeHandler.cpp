#ifndef COMPUTER_SIMULATION_TIMEHANDLER_CPP
#define COMPUTER_SIMULATION_TIMEHANDLER_CPP

#include <chrono>

bool run = true;

void timeHandler(time_t seconds = 0) {
    time_t curTime = time(nullptr);
    static time_t endTime = curTime + seconds;
    if (curTime > endTime) run = false;
}

#endif //COMPUTER_SIMULATION_TIMEHANDLER_CPP
