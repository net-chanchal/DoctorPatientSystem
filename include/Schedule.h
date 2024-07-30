#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>

class Schedule {
public:
    Schedule(const std::string& date, const std::string& time);

    const std::string& getDate() const;
    const std::string& getTime() const;

private:
    std::string date;
    std::string time;
};

#endif // SCHEDULE_H