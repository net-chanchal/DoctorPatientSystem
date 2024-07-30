#ifndef BOOKING_H
#define BOOKING_H

#include "Doctor.h"
#include "Patient.h"
#include "Schedule.h"
#include "CSVHandler.h"

class Booking {
public:
    Booking(const Doctor& doctor, const Patient& patient, const Schedule& schedule);

    const Doctor& getDoctor() const;
    const Patient& getPatient() const;
    const Schedule& getSchedule() const;

    static std::vector<Booking> loadFromCSV(const std::string& filename, const std::vector<Doctor>& doctors, const std::vector<Patient>& patients);
    static void saveToCSV(const std::string& filename, const std::vector<Booking>& bookings);

private:
    Doctor doctor;
    Patient patient;
    Schedule schedule;
};

#endif // BOOKING_H