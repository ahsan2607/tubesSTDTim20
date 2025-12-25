#ifndef DLL_POLYCLINIC_FUNC_H_INCLUDED
#define DLL_POLYCLINIC_FUNC_H_INCLUDED

#include "polyclinicTypeDLL.h"
#include "relationTypeDLL.h"

void createPolyclinicList(polyclinicList &L);
adrPolyclinic createPolyclinicElm(string name, string code);
void insertPolyclinicToList(polyclinicList &L, adrPolyclinic p);
adrPolyclinic searchPolyclinic(polyclinicList L, string code);
void deletePolyclinicFromList(polyclinicList &L, string code, relationList &RL);
void printFoundPolyclinic(adrPolyclinic poly);
void printAllPolyclinic(polyclinicList L);

#endif // DLL_POLYCLINIC_FUNC_H_INCLUDED
