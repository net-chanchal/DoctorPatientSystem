#include "Patient.h"

Patient::Patient(const std::string& name, int age, const std::string& ailment)
    : name(name), age(age), ailment(ailment) {}

const std::string& Patient::getName() const {
    return name;
}

int Patient::getAge() const {
    return age;
}

const std::string& Patient::getAilment() const {
    return ailment;
}

std::vector<Patient> Patient::loadFromCSV(const std::string& filename) {
    std::vector<Patient> patients;
    auto data = CSVHandler::readCSV(filename);

    for (const auto& row : data) {
        if (row.size() >= 3) {
            patients.emplace_back(row[0], std::stoi(row[1]), row[2]);
        }
    }
    return patients;
}

void Patient::saveToCSV(const std::string& filename, const std::vector<Patient>& patients) {
    std::vector<std::vector<std::string>> data;

    for (const auto& patient : patients) {
        data.push_back({patient.name, std::to_string(patient.age), patient.ailment});
    }
    CSVHandler::writeCSV(filename, data);
}