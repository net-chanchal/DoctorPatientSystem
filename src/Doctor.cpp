#include "Doctor.h"

Doctor::Doctor(const std::string& name, const std::string& specialization)
    : name(name), specialization(specialization) {}

void Doctor::addSchedule(const Schedule& schedule) {
    schedules.push_back(schedule);
}

const std::string& Doctor::getName() const {
    return name;
}

const std::string& Doctor::getSpecialization() const {
    return specialization;
}

const std::vector<Schedule>& Doctor::getSchedules() const {
    return schedules;
}

std::vector<Doctor> Doctor::loadFromCSV(const std::string& filename) {
    std::vector<Doctor> doctors;
    auto data = CSVHandler::readCSV(filename);

    for (const auto& row : data) {
        if (row.size() >= 2) {
            doctors.emplace_back(row[0], row[1]);
        }
    }
    return doctors;
}

void Doctor::saveToCSV(const std::string& filename, const std::vector<Doctor>& doctors) {
    std::vector<std::vector<std::string>> data;

    for (const auto& doctor : doctors) {
        data.push_back({doctor.name, doctor.specialization});
    }
    CSVHandler::writeCSV(filename, data);
}