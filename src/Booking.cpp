#include "Booking.h"

Booking::Booking(const Doctor& doctor, const Patient& patient, const Schedule& schedule)
    : doctor(doctor), patient(patient), schedule(schedule) {}

const Doctor& Booking::getDoctor() const {
    return doctor;
}

const Patient& Booking::getPatient() const {
    return patient;
}

const Schedule& Booking::getSchedule() const {
    return schedule;
}

std::vector<Booking> Booking::loadFromCSV(const std::string& filename, const std::vector<Doctor>& doctors, const std::vector<Patient>& patients) {
    std::vector<Booking> bookings;
    auto data = CSVHandler::readCSV(filename);

    for (const auto& row : data) {
        if (row.size() >= 4) {
            auto doctorIt = std::find_if(doctors.begin(), doctors.end(), [&row](const Doctor& doc) {
                return doc.getName() == row[0];
            });

            auto patientIt = std::find_if(patients.begin(), patients.end(), [&row](const Patient& pat) {
                return pat.getName() == row[1];
            });

            if (doctorIt != doctors.end() && patientIt != patients.end()) {
                bookings.emplace_back(*doctorIt, *patientIt, Schedule(row[2], row[3]));
            }
        }
    }
    return bookings;
}

void Booking::saveToCSV(const std::string& filename, const std::vector<Booking>& bookings) {
    std::vector<std::vector<std::string>> data;

    for (const auto& booking : bookings) {
        data.push_back({booking.getDoctor().getName(), booking.getPatient().getName(), booking.getSchedule().getDate(), booking.getSchedule().getTime()});
    }
    CSVHandler::writeCSV(filename, data);
}