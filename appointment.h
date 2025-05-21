#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

struct AppointmentNode
{
    int appointment_id;
    int patient_id;
    int doctor_id;
    std::string appointment_date;
    AppointmentNode *next;
};

// Appointment list operations
AppointmentNode *createAppointment(int id, int patient_id, int doctor_id, const std::string &date);
bool appointmentExists(AppointmentNode *head, int id);
void displayAppointments(AppointmentNode *head);
void deleteAppointmentList(AppointmentNode *head);

#endif