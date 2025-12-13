#ifndef DLL_RELATION_H_INCLUDED
#define DLL_RELATION_H_INCLUDED

#include <iostream>
#include "doctorTypeDLL.h"
#include "polyclinicTypeDLL.h"
using namespace std;

typedef struct relationElm *adrRelation;

struct relationElm {
    adrRelation prev;
    adrPolyclinic parent;
    adrDoctor child;
    adrRelation next;
};

struct relationList {
    adrRelation first;
    adrRelation last;
};

#endif // DLL_RELATION_H_INCLUDED
