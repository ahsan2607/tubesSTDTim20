#include <iostream>
#include "doctorFuncDLL.h"
#include "polyclinicFuncDLL.h"
#include "relationFuncDLL.h"
using namespace std;

void createRelationList(relationList &L){
    L.first = nullptr;
    L.last = nullptr;
}

adrRelation createRelationElm(adrPolyclinic poly, adrDoctor doct){
    adrRelation p = new relationElm;
    p->parent = poly;
    p->child = doct;
    p->prev = nullptr;
    p->next = nullptr;
    return p;
}

void addDoctorToPolyclinic(relationList &L, adrRelation p){
    if (isDoctorAlreadyAssigned(L, p->child->info.nid)) {
        delete p;
        cout << "Tidak bisa menambahkan karena dokter sudah berada di poliklinik lain!" << endl;
    } else {
        if (L.last == nullptr) {
            L.first = p;
            L.last = p;
        } else {
            p->prev = L.last;
            L.last->next = p;
            L.last = p;
        }
        cout << "Dokter berhasil ditambahkan ke poliklinik!" << endl;
    }
}

adrRelation findRelation(relationList &L, string codePoly, string nidDoctor){
    adrRelation p = L.first;
    while (p != nullptr && (p->child->info.nid != nidDoctor || p->parent->info.code != codePoly)) {
        p = p->next;
    }
    return p;
}

void removeDoctorFromPolyclinic(relationList &L, string codePoly, string nidDoctor){
    adrRelation deleted;
    adrRelation target = findRelation(L, codePoly, nidDoctor);
    if (target != nullptr) {
        deleted = target;
        if (target == L.first && target == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        } else if (target == L.first) {
            L.first = target->next;
            L.first->prev = nullptr;
        } else if (target == L.last) {
            L.last = target->prev;
            L.last->next = nullptr;
        } else {
            target->next->prev = target->prev;
            target->prev->next = target->next;
        }
        target->next = nullptr;
        target->prev = nullptr;
        delete deleted;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}

void printAllDoctorFromPolyclinic(polyclinicList PL, relationList RL, string code){
    adrPolyclinic target = searchPolyclinic(PL, code);
    adrRelation p = RL.first;
    while (p != nullptr) {
        if (p->parent == target) {
            cout << "-> " << "Kode dokter\t\t: "  << p->child->info.nid << endl;
            cout << "   " << "Nama dokter\t\t: "  << p->child->info.name << endl;
            cout << "   " << "Spesialisasi dokter\t: "  << p->child->info.specialization << endl;
            cout << "   " << "Jam Praktik\t\t: "  << p->child->info.practiceHours << endl;
            cout << "   " << "Pengalaman\t\t: "  << p->child->info.experienceYears << " tahun" << endl;
        }
        p = p->next;
    }
    cout << endl;
}

int countDoctorInPolyclinic(polyclinicList PL, relationList RL, string code){
    adrPolyclinic poly = searchPolyclinic(PL, code);
    adrRelation p = RL.first;
    int n = 0;
    while (p != nullptr) {
        if (p->parent == poly) {
            n = n + 1;
        }
        p = p->next;
    }
    return n;
}

void showPolyclinicWithMostDoctor(polyclinicList PL, relationList RL){
    adrPolyclinic p = PL.first;
    adrPolyclinic mostDoctor = nullptr;
    int maxDoct = 0;
    int tempMax = 0;
    while (p != nullptr) {
        tempMax = countDoctorInPolyclinic(PL, RL, p->info.code);
        if (maxDoct < tempMax) {
            maxDoct = tempMax;
            mostDoctor = p;
        }
        p = p->next;
    }
    if (mostDoctor != nullptr) {
        cout << "Kode Poliklinik\t: " << mostDoctor->info.code << endl;
        cout << "Nama Poliklinik\t: " << mostDoctor->info.name << endl;
        cout << "Jumlah dokter\t: " << maxDoct << endl;
    } else {
        cout << "Tidak ada poliklinik." << endl;
    }
}

void showAllPolyclinicAndDoctors(polyclinicList PL, relationList RL){
    adrPolyclinic p = PL.first;
    while (p != nullptr) {
        cout << "Kode Poliklinik\t: " << p->info.code << endl;
        cout << "Nama Poliklinik\t: " << p->info.name << endl;
        cout << "Daftar dokter:\t\t" << endl;
        adrRelation q = RL.first;
        while (q != nullptr) {
            if (q->parent == p) {
                cout << "-> " << "Kode dokter\t\t: "  << q->child->info.nid << endl;
                cout << "   " << "Nama dokter\t\t: "  << q->child->info.name << endl;
                cout << "   " << "Spesialisasi dokter\t: "  << q->child->info.specialization << endl;
                cout << "   " << "Jam Praktik\t\t: "  << q->child->info.practiceHours << endl;
                cout << "   " << "Pengalaman\t\t: "  << q->child->info.experienceYears << " tahun" << endl;
            }
            q = q->next;
        }
        cout << endl;
        p = p->next;
    }
    cout << endl;
}

bool isDoctorAlreadyAssigned(relationList L, string nid){
    adrRelation p = L.first;
    bool isAssigned = false;
    while (p != nullptr && isAssigned == false) {
        if (p->child->info.nid == nid) {
            isAssigned = true;
        }
        p = p->next;
    }
    return isAssigned;
}
