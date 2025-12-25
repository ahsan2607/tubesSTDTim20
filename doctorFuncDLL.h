#ifndef DLL_DOCTOR_FUNC_H_INCLUDED
#define DLL_DOCTOR_FUNC_H_INCLUDED

#include "doctorTypeDLL.h"
#include "relationTypeDLL.h"

void createDoctorList(doctorList &L);
adrDoctor createDoctorElm(string name, string nid, string specialization, string practiceHours, int experienceYears);
void insertDoctorToList(doctorList &L, adrDoctor p);
adrDoctor searchDoctor(doctorList L, string nid);
void deleteDoctorFromList(doctorList &L, string nid, relationList &RL);
void printDoctorWithSpecialization(doctorList L, string specialization);
void printFoundDoctor(adrDoctor doct);
void printAllDoctor(doctorList L);

#endif // DLL_DOCTOR_FUNC_H_INCLUDED
