#include "health_service.h"
#include <iostream>
#include <limits>

HealthcareSystem::HealthcareSystem() : patientsHead(nullptr), doctorsHead(nullptr), appointmentsHead(nullptr) {}

HealthcareSystem::~HealthcareSystem()
{
    deleteAll(patientsHead);
    deleteDoctorList(doctorsHead);
    deleteAppointmentList(appointmentsHead);
}

void HealthcareSystem::registerPatient()
{
    int id;
    std::string name, dob, gender;

    std::cout << "Enter Patient ID: ";
    std::cin >> id;

    if (exists(patientsHead, id))
    {
        std::cout << "Error: Patient ID already exists!\n";
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Date of Birth (DOB): ";
    std::getline(std::cin, dob);

    std::cout << "Enter Gender: ";
    std::getline(std::cin, gender);

    Patient *newPatient = create(id, name, dob, gender);
    newPatient->next = patientsHead;
    patientsHead = newPatient;

    std::cout << "Patient registered successfully!\n";
}

void HealthcareSystem::registerDoctor()
{
    int id;
    std::string name, specialization;

    std::cout << "Enter Doctor ID: ";
    std::cin >> id;

    if (doctorExists(doctorsHead, id))
    {
        std::cout << "Error: Doctor ID already exists!\n";
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Specialization: ";
    std::getline(std::cin, specialization);

    DoctorNode *newDoctor = createDoctor(id, name, specialization);
    newDoctor->next = doctorsHead;
    doctorsHead = newDoctor;

    std::cout << "Doctor registered successfully!\n";
}

void HealthcareSystem::registerAppointment()
{
    int id, patientId, doctorId;
    std::string date;

    std::cout << "Enter Appointment ID: ";
    std::cin >> id;

    if (appointmentExists(appointmentsHead, id))
    {
        std::cout << "Error: Appointment ID already exists!\n";
        return;
    }

    std::cout << "Enter Patient ID: ";
    std::cin >> patientId;

    if (!exists(patientsHead, patientId))
    {
        std::cout << "Error: Patient ID does not exist!\n";
        return;
    }

    std::cout << "Enter Doctor ID: ";
    std::cin >> doctorId;

    if (!doctorExists(doctorsHead, doctorId))
    {
        std::cout << "Error: Doctor ID does not exist!\n";
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter Appointment Date: ";
    std::getline(std::cin, date);

    AppointmentNode *newAppointment = createAppointment(id, patientId, doctorId, date);
    newAppointment->next = appointmentsHead;
    appointmentsHead = newAppointment;

    std::cout << "Appointment registered successfully!\n";
}

void HealthcareSystem::displayPatients() const
{
    ::display(patientsHead);
}

void HealthcareSystem::displayDoctors() const
{
    ::displayDoctors(doctorsHead);
}

void HealthcareSystem::displayAppointments() const
{
    ::displayAppointments(appointmentsHead);
}

void HealthcareSystem::showMenu()
{
    int choice;
    do
    {
        std::cout << "\n=== RUHENGERI REFERAL HOSPITAL ===\n";
        std::cout << "1. Register Patient\n";
        std::cout << "2. Register Doctor\n";
        std::cout << "3. Register Appointment\n";
        std::cout << "4. Display Patients\n";
        std::cout << "5. Display Doctors\n";
        std::cout << "6. Display Appointments\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            registerPatient();
            break;
        case 2:
            registerDoctor();
            break;
        case 3:
            registerAppointment();
            break;
        case 4:
            displayPatients();
            break;
        case 5:
            displayDoctors();
            break;
        case 6:
            displayAppointments();
            break;
        case 7:
            std::cout << "Exiting system...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}