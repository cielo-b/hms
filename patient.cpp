#include "patient.h"
#include <iostream>
using namespace std;

Patient *create(int id, const string &name, const string &dob, const string &gender)
{
    Patient *patient = new Patient;
    patient->patient_id = id;
    patient->name = name;
    patient->dob = dob;
    patient->gender = gender;
    patient->next = nullptr;
    return patient;
}

bool exists(Patient *head, int id)
{
    Patient *current = head;
    while (current != nullptr)
    {
        if (current->patient_id == id)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void display(Patient *head)
{
    if (head == nullptr)
    {
        std::cout << "No patients registered." << std::endl;
        return;
    }

    std::cout << "\n=== PATIENTS LIST ===\n";
    Patient *current = head;
    while (current != nullptr)
    {
        std::cout << "ID: " << current->patient_id << "\n";
        std::cout << "Name: " << current->name << "\n";
        std::cout << "DOB: " << current->dob << "\n";
        std::cout << "Gender: " << current->gender << "\n";
        std::cout << "-------------------\n";
        current = current->next;
    }
}

void deleteAll(Patient *head)
{
    Patient *current = head;
    while (current != nullptr)
    {
        Patient *next = current->next;
        delete current;
        current = next;
    }
}

bool deleteById(Patient *&head, int id)
{
    // Handle empty list
    if (head == nullptr)
    {
        return false;
    }

    // Special case: deleting the head node
    if (head->patient_id == id)
    {
        Patient *temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    // Search for the node to delete
    Patient *current = head;
    while (current->next != nullptr && current->next->patient_id != id)
    {
        current = current->next;
    }

    // If node found, delete it
    if (current->next != nullptr && current->next->patient_id == id)
    {
        Patient *temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }

    // Node not found
    return false;
}