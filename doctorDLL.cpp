#include <iostream>
#include "doctorFuncDLL.h"
using namespace std;

void createDoctorList(doctorList &L){
    L.first = nullptr;
    L.last = nullptr;
}

adrDoctor createDoctorElm(string name, string nid, string specialization, string practiceHours, int experienceYears){
    adrDoctor p = new doctorElm;
    p->info.name = name;
    p->info.nid = nid;
    p->info.specialization = specialization;
    p->info.practiceHours = practiceHours;
    p->info.experienceYears = experienceYears;
    p->prev = nullptr;
    p->next = nullptr;
    return p;
}

void insertDoctorToList(doctorList &L, adrDoctor p){
    if (searchDoctor(L, p->info.nid) == nullptr){
        if (L.first == nullptr) {
            L.first = p;
            L.last = p;
        } else {
            p->next = L.first;
            L.first->prev = p;
            L.first = p;
        }
        cout << "Dokter berhasil ditambahkan!" << endl;
    } else {
        cout << "Kode NID tidak boleh sama, coba pakai masukkan NID lain" << endl;
    }
}

adrDoctor searchDoctor(doctorList L, string nid){
    adrDoctor p = L.first;
    while (p != nullptr && p->info.nid != nid) {
        p = p->next;
    }
    return p;
}

void deleteDoctorFromList(doctorList &L, string nid){
    adrDoctor deleted;
    adrDoctor target = searchDoctor(L, nid);
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
