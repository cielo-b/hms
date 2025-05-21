#include "appointment.h"
#include <iostream>

AppointmentNode *createAppointment(int id, int patient_id, int doctor_id, const std::string &date)
{
    AppointmentNode *newAppointment = new AppointmentNode;
    newAppointment->appointment_id = id;
    newAppointment->patient_id = patient_id;
    newAppointment->doctor_id = doctor_id;
    newAppointment->appointment_date = date;
    newAppointment->next = nullptr;
    return newAppointment;
}

bool appointmentExists(AppointmentNode *head, int id)
{
    AppointmentNode *current = head;
    while (current != nullptr)
    {
        if (current->appointment_id == id)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void displayAppointments(AppointmentNode *head)
{
    if (head == nullptr)
    {
        std::cout << "No appointments scheduled.\n";
        return;
    }

    std::cout << "\n=== APPOINTMENTS LIST ===\n";
    AppointmentNode *current = head;
    while (current != nullptr)
    {
        std::cout << "Appointment ID: " << current->appointment_id << "\n";
        std::cout << "Patient ID: " << current->patient_id << "\n";
        std::cout << "Doctor ID: " << current->doctor_id << "\n";
        std::cout << "Date: " << current->appointment_date << "\n";
        std::cout << "-------------------\n";
        current = current->next;
    }
}

void deleteAppointmentList(AppointmentNode *head)
{
    AppointmentNode *current = head;
    while (current != nullptr)
    {
        AppointmentNode *next = current->next;
        delete current;
        current = next;
    }
}