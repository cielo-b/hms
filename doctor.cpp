#include "doctor.h"
#include <iostream>

DoctorNode *createDoctor(int id, const std::string &name, const std::string &specialization)
{
    DoctorNode *newDoctor = new DoctorNode;
    newDoctor->doctor_id = id;
    newDoctor->name = name;
    newDoctor->specialization = specialization;
    newDoctor->next = nullptr;
    return newDoctor;
}

bool doctorExists(DoctorNode *head, int id)
{
    DoctorNode *current = head;
    while (current != nullptr)
    {
        if (current->doctor_id == id)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void displayDoctors(DoctorNode *head)
{
    if (head == nullptr)
    {
        std::cout << "No doctors registered.\n";
        return;
    }

    std::cout << "\n=== DOCTORS LIST ===\n";
    DoctorNode *current = head;
    while (current != nullptr)
    {
        std::cout << "ID: " << current->doctor_id << "\n";
        std::cout << "Name: " << current->name << "\n";
        std::cout << "Specialization: " << current->specialization << "\n";
        std::cout << "-------------------\n";
        current = current->next;
    }
}

void deleteDoctorList(DoctorNode *head)
{
    DoctorNode *current = head;
    while (current != nullptr)
    {
        DoctorNode *next = current->next;
        delete current;
        current = next;
    }
}