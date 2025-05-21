#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

struct DoctorNode
{
    int doctor_id;
    std::string name;
    std::string specialization;
    DoctorNode *next;
};

// Doctor list operations
DoctorNode *createDoctor(int id, const std::string &name, const std::string &specialization);
bool doctorExists(DoctorNode *head, int id);
void displayDoctors(DoctorNode *head);
void deleteDoctorList(DoctorNode *head);

#endif