#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include "CSVHandler.h"

class Patient {
public:
    Patient(const std::string& name, int age, const std::string& ailment);

    const std::string& getName() const;
    int getAge() const;
    const std::string& getAilment() const;

    static std::vector<Patient> loadFromCSV(const std::string& filename);
    static void saveToCSV(const std::string& filename, const std::vector<Patient>& patients);

private:
    std::string name;
    int age;
    std::string ailment;
};

#endif // PATIENT_H