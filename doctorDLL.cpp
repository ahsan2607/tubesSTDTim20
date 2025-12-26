#include <iostream>
#include "doctorFuncDLL.h"
#include "relationFuncDLL.h"
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
        cout << "Kode NID tidak boleh sama, coba pakai masukan NID lain" << endl;
    }
}

adrDoctor searchDoctor(doctorList L, string nid){
    adrDoctor p = L.first;
    while (p != nullptr && p->info.nid != nid) {
        p = p->next;
    }
    return p;
}

void deleteDoctorFromList(doctorList &L, string nid, relationList &RL){
    adrRelation p = RL.first;
    while (p != nullptr) {
        adrRelation next = p->next;
        if (p->child->info.nid == nid) {
            removeDoctorFromPolyclinic(RL, p->parent->info.code, nid);
        }
        p = next;
    }
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
        cout << "Dokter berhasil dihapus!" << endl;
    } else {
        cout << "Dokter tidak ditemukan" << endl;
    }
}

void printDoctorWithSpecialization(doctorList L, string specialization){
    if (L.first != nullptr) {
        adrDoctor p = L.first;
        while (p != nullptr) {
            if (p->info.specialization == specialization) {
                cout << "-> " << "Kode dokter\t\t: "  << p->info.nid << endl;
                cout << "   " << "Nama dokter\t\t: "  << p->info.name << endl;
                cout << "   " << "Spesialisasi dokter\t: "  << p->info.specialization << endl;
                cout << "   " << "Jam Praktik\t\t: "  << p->info.practiceHours << endl;
                cout << "   " << "Pengalaman\t\t: "  << p->info.experienceYears << " tahun" << endl;
            }
            p = p->next;
        }
    } else {
        cout << "Tidak ada dokter dalam daftar" << endl;
    }
    cout << endl;
}

void printFoundDoctor(adrDoctor doct){
    if (doct != nullptr) {
        cout << "Kode dokter\t\t: "  << doct->info.nid << endl;
        cout << "Nama dokter\t\t: "  << doct->info.name << endl;
        cout << "Spesialisasi dokter\t: "  << doct->info.specialization << endl;
        cout << "Jam Praktik\t\t: "  << doct->info.practiceHours << endl;
        cout << "Pengalaman\t\t: "  << doct->info.experienceYears << " tahun" << endl;
    } else {
        cout << "Dokter tidak ditemukan" << endl;
    }
}

void printAllDoctor(doctorList L){
    if (L.first != nullptr) {
        adrDoctor p = L.first;
        while (p != nullptr) {
            cout << "Kode dokter\t\t: "  << p->info.nid << endl;
            cout << "Nama dokter\t\t: "  << p->info.name << endl;
            cout << "Spesialisasi dokter\t: "  << p->info.specialization << endl;
            cout << "Jam Praktik\t\t: "  << p->info.practiceHours << endl;
            cout << "Pengalaman\t\t: "  << p->info.experienceYears << " tahun" << endl;
            p = p->next;
        }
    } else {
        cout << "Tidak ada dokter dalam daftar" << endl;
    }
    cout << endl;
}
