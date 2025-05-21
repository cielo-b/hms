#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

struct Patient
{
    int patient_id;
    string name;
    string dob;
    string gender;
    Patient *next;
};

// operations
Patient *create(int id, const string &name, const string &dob, const string &gender);
bool exists(Patient *head, int id);
void display(Patient *head);
void deleteAll(Patient *head);
bool deleteById(Patient *&head, int id);

#endif