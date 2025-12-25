#ifndef DLL_RELATION_FUNC_H_INCLUDED
#define DLL_RELATION_FUNC_H_INCLUDED

#include "doctorTypeDLL.h"
#include "polyclinicTypeDLL.h"
#include "relationTypeDLL.h"

void createRelationList(relationList &L);
adrRelation createRelationElm(adrPolyclinic poly, adrDoctor doct);
void addDoctorToPolyclinic(relationList &L, adrRelation p);
adrRelation findRelation(relationList &L, string codePoly, string nidDoctor);
void removeDoctorFromPolyclinic(relationList &L, string codePoly, string nidDoctor);
void printAllDoctorFromPolyclinic(polyclinicList PL, relationList RL, string code);
int countDoctorInPolyclinic(polyclinicList PL, relationList RL, string code);
void showPolyclinicWithMostDoctor(polyclinicList PL, relationList RL);
void showAllPolyclinicAndDoctors(polyclinicList PL, relationList RL);
bool isDoctorAlreadyAssigned(relationList RL, string nid);

#endif // DLL_RELATION_FUNC_H_INCLUDED
