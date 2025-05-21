#ifndef HEALTHCARE_SYSTEM_H
#define HEALTHCARE_SYSTEM_H

#include "patient.h"
#include "doctor.h"
#include "appointment.h"

class HealthcareSystem
{
private:
    Patient *patientsHead;
    DoctorNode *doctorsHead;
    AppointmentNode *appointmentsHead;

public:
    HealthcareSystem();
    ~HealthcareSystem();

    void registerPatient();
    void registerDoctor();
    void registerAppointment();
    void displayPatients() const;
    void displayDoctors() const;
    void displayAppointments() const;
    void showMenu();
};

#endif