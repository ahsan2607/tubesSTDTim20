#ifndef DLL_KLINIK_H_INCLUDED
#define DLL_KLINIK_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct polyclinicElm *adrPolyclinic;

typedef struct polyclinic {
    string name;
    string code;
} infotypePoly;

struct polyclinicElm {
    adrPolyclinic prev;
    infotypePoly info;
    adrPolyclinic next;
};

struct polyclinicList {
    adrPolyclinic first;
    adrPolyclinic last;
};

#endif // DLL_KLINIK_H_INCLUDED
