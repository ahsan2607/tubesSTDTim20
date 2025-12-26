#include <iostream>
#include "polyclinicFuncDLL.h"
#include "relationFuncDLL.h"
using namespace std;

void createPolyclinicList(polyclinicList &L){
    L.first = nullptr;
    L.last = nullptr;
}

adrPolyclinic createPolyclinicElm(string name, string code){
    adrPolyclinic p = new polyclinicElm;
    p->info.name = name;
    p->info.code = code;
    p->prev = nullptr;
    p->next = nullptr;
    return p;
}

void insertPolyclinicToList(polyclinicList &L, adrPolyclinic p) {
    if (searchPolyclinic(L, p->info.code) == nullptr){
        if (L.first == nullptr) {
            L.first = p;
            L.last = p;
        } else {
            p->next = L.first;
            L.first->prev = p;
            L.first = p;
        }
        cout << "Poliklinik berhasil ditambahkan!" << endl;
    } else {
        cout << "Kode Poliklinik tidak boleh sama, coba pakai masukan kode lain" << endl;
    }
}

adrPolyclinic searchPolyclinic(polyclinicList L, string code){
    adrPolyclinic p = L.first;
    while (p != nullptr && p->info.code != code) {
        p = p->next;
    }
    return p;
}

void deletePolyclinicFromList(polyclinicList &L, string code, relationList &RL){
    adrRelation p = RL.first;
    while (p != nullptr) {
        adrRelation next = p->next;
        if (p->parent->info.code == code) {
            removeDoctorFromPolyclinic(RL, code, p->child->info.nid);
        }
        p = next;
    }
    adrPolyclinic deleted;
    adrPolyclinic target = searchPolyclinic(L, code);
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
        cout << "Poliklinik dan semua relasinya berhasil dihapus!" << endl;
    } else {
        cout << "Poliklinik tidak ditemukan" << endl;
    }
}

void printFoundPolyclinic(adrPolyclinic poly){
    if (poly != nullptr) {
        cout << "Kode Poliklinik\t: " << poly->info.code << endl;
        cout << "Nama Poliklinik\t: " << poly->info.name << endl;
    } else {
        cout << "Poliklinik tidak ditemukan" << endl;
    }
    cout << endl;
}

void printAllPolyclinic(polyclinicList L){
    if (L.first != nullptr) {
        adrPolyclinic p = L.first;
        while (p != nullptr) {
            cout << "-> " << "Kode Poliklinik\t: " << p->info.code << endl;
            cout << "   " << "Nama Poliklinik\t: " << p->info.name << endl;
            p = p->next;
        }
    } else {
        cout << "Tidak ada dokter dalam daftar" << endl;
    }
    cout << endl;
}
