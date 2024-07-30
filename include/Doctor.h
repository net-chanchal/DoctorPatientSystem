#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <vector>
#include "Schedule.h"
#include "CSVHandler.h"

class Doctor {
public:
    Doctor(const std::string& name, const std::string& specialization);

    void addSchedule(const Schedule& schedule);
    const std::string& getName() const;
    const std::string& getSpecialization() const;
    const std::vector<Schedule>& getSchedules() const;

    static std::vector<Doctor> loadFromCSV(const std::string& filename);
    static void saveToCSV(const std::string& filename, const std::vector<Doctor>& doctors);

private:
    std::string name;
    std::string specialization;
    std::vector<Schedule> schedules;
};

#endif // DOCTOR_H