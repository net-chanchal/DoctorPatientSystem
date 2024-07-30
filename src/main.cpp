#include <iostream>
#include <vector>
#include "Doctor.h"
#include "Patient.h"
#include "Booking.h"
#include "Schedule.h"

void createDoctor(std::vector<Doctor>& doctors) {
    std::string name, specialization;
    std::cout << "Enter doctor's name: ";
    std::cin >> name;
    std::cout << "Enter doctor's specialization: ";
    std::cin >> specialization;

    doctors.emplace_back(name, specialization);
    Doctor::saveToCSV("data/doctors.csv", doctors);
}

void createPatient(std::vector<Patient>& patients) {
    std::string name, ailment;
    int age;
    std::cout << "Enter patient's name: ";
    std::cin >> name;
    std::cout << "Enter patient's age: ";
    std::cin >> age;
    std::cout << "Enter patient's ailment: ";
    std::cin >> ailment;

    patients.emplace_back(name, age, ailment);
    Patient::saveToCSV("data/patients.csv", patients);
}

void createBooking(const std::vector<Doctor>& doctors, const std::vector<Patient>& patients, std::vector<Booking>& bookings) {
    std::string doctorName, patientName, date, time;
    std::cout << "Enter doctor's name for booking: ";
    std::cin >> doctorName;
    std::cout << "Enter patient's name for booking: ";
    std::cin >> patientName;
    std::cout << "Enter date (YYYY-MM-DD): ";
    std::cin >> date;
    std::cout << "Enter time (HH:MM): ";
    std::cin >> time;

    auto doctorIt = std::find_if(doctors.begin(), doctors.end(), [&doctorName](const Doctor& doc) {
        return doc.getName() == doctorName;
    });

    auto patientIt = std::find_if(patients.begin(), patients.end(), [&patientName](const Patient& pat) {
        return pat.getName() == patientName;
    });

    if (doctorIt != doctors.end() && patientIt != patients.end()) {
        bookings.emplace_back(*doctorIt, *patientIt, Schedule(date, time));
        Booking::saveToCSV("data/bookings.csv", bookings);
    } else {
        std::cout << "Doctor or Patient not found." << std::endl;
    }
}

void findAllDoctors(const std::vector<Doctor>& doctors) {
    for (const auto& doctor : doctors) {
        std::cout << "Doctor: " << doctor.getName() << ", Specialization: " << doctor.getSpecialization() << std::endl;
    }
}

void findAllPatients(const std::vector<Patient>& patients) {
    for (const auto& patient : patients) {
        std::cout << "Patient: " << patient.getName() << ", Age: " << patient.getAge() << ", Ailment: " << patient.getAilment() << std::endl;
    }
}

void findAllBookings(const std::vector<Booking>& bookings) {
    for (const auto& booking : bookings) {
        std::cout << "Booking - Doctor: " << booking.getDoctor().getName()
                  << ", Patient: " << booking.getPatient().getName()
                  << ", Date: " << booking.getSchedule().getDate()
                  << ", Time: " << booking.getSchedule().getTime() << std::endl;
    }
}

int main() {
    std::vector<Doctor> doctors = Doctor::loadFromCSV("data/doctors.csv");
    std::vector<Patient> patients = Patient::loadFromCSV("data/patients.csv");
    std::vector<Booking> bookings = Booking::loadFromCSV("data/bookings.csv", doctors, patients);

    while (true) {
        std::cout << "\n1. Create Doctor\n2. Create Patient\n3. Create Booking\n4. Find All Doctors\n5. Find All Patients\n6. Find All Bookings\n7. Exit\n\n";
        std::cout << "Choose Option: ";
        
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                createDoctor(doctors);
                break;
            case 2:
                createPatient(patients);
                break;
            case 3:
                createBooking(doctors, patients, bookings);
                break;
            case 4:
                findAllDoctors(doctors);
                break;
            case 5:
                findAllPatients(patients);
                break;
            case 6:
                findAllBookings(bookings);
                break;
            case 7:
                return 0;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
        }
    }

    return 0;
}