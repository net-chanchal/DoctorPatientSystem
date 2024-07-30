#include "Schedule.h"

Schedule::Schedule(const std::string& date, const std::string& time)
    : date(date), time(time) {}

const std::string& Schedule::getDate() const {
    return date;
}

const std::string& Schedule::getTime() const {
    return time;
}