#ifndef DLL_DOKTER_H_INCLUDED
#define DLL_DOKTER_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct doctorElm *adrDoctor;

typedef struct doctor {
    string name;
    string nid;
    string specialization;
    string practiceHours;
    int experienceYears;
} infotypeDoct;

struct doctorElm {
    adrDoctor prev;
    infotypeDoct info;
    adrDoctor next;
};

struct doctorList {
    adrDoctor first;
    adrDoctor last;
};

#endif // DLL_DOKTER_H_INCLUDED
