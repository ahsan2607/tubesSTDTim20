#ifndef DLL_DOCTOR_FUNC_H_INCLUDED
#define DLL_DOCTOR_FUNC_H_INCLUDED

#include "doctorTypeDLL.h"
#include "relationTypeDLL.h"

void createDoctorList(doctorList &L);
/*  I.S. -
    F.S. doctorList L terinisialisasi sebagai list kosong,
         dengan L.first dan L.last bernilai nullptr. */

adrDoctor createDoctorElm(string name, string nid, string specialization, string practiceHours, int experienceYears);
/*  I.S. Terdefinisi name, nid, specialization, practiceHours adalah string,
         experienceYears adalah integer.
    F.S. Mengembalikan adrDoctor (pointer ke doctorElm baru)
         dengan info.nid bernilai nid, info.name bernilai name,
         info.specialization bernilai specialization, info.practiceHours bernilai practiceHours,
         info.experienceYears bernilai experienceYears jika nilainya lebih atau sama dengan nol.
         prev dan next bernilai nullptr. */

void insertDoctorToList(doctorList &L, adrDoctor p);
/*  I.S. Terdefinisi list dokter L sudah terinisialisasi (boleh kosong),
         adrDoctor p sudah dialokasikan dan bukan nullptr, nid dari p unik.
    F.S. Jika nid unik, p disisipkan di depan list L.
         Jika L kosong, L.first dan L.last jadi p.
         Jika nid duplikat, p tidak disisipkan dan pesan error ditampilkan. */

adrDoctor searchDoctor(doctorList L, string nid);
/*  I.S. Terdefinisi list dokter L sudah terinisialisasi (boleh kosong),
         nid adalah string valid untuk dicari.
    F.S. Mengembalikan adrDoctor jika ditemukan elemen dengan info.nid sama dengan nid,
         atau nullptr jika tidak ditemukan atau list kosong. */

void deleteDoctorFromList(doctorList &L, string nid, relationList &RL);
/*  I.S. Terdefinisi list dokter L dan list relasi RL sudah terinisialisasi, nid adalah string.
         Diasumsikan RL mungkin punya relasi ke dokter dengan nid ini.
    F.S. Semua relasi di RL yang melibatkan dokter dengan nid dihapus dulu (pakai removeDoctorFromPolyclinic).
         Kemudian, jika dokter ditemukan di L, dihapus dari list L (handle kasus first, last, middle, single).
         Memory dokter dibebaskan. Jika tidak ditemukan, pesan error. */

void printDoctorWithSpecialization(doctorList L, string specialization);
/*  I.S. Terdefinisi list dokter L sudah terinisialisasi (boleh kosong),
         specialization adalah string untuk dicari.
    F.S. Semua dokter di L dengan info.specialization sama dengan specialization ditampilkan dalam format detail.
         Jika tidak ada, pesan "Tidak ada dokter dengan spesialisasi...".
         Jika list kosong, pesan "Tidak ada dokter dalam daftar". */

void printFoundDoctor(adrDoctor doct);
/*  I.S. Terdefinisi adrDoctor doct boleh nullptr atau pointer ke doctorElm.
    F.S. Jika doct tidak sama dengan nullptr, tampilkan detail dokter.
         Jika doct sama dengan nullptr, tampilkan "Dokter tidak ditemukan". */

void printAllDoctor(doctorList L);
/*  I.S. Terdefinisi list dokter L sudah terinisialisasi (boleh kosong).
    F.S. Semua dokter di L ditampilkan dalam format detail (dari first ke last).
         Jika kosong, tampilkan "Tidak ada dokter dalam daftar". */

#endif // DLL_DOCTOR_FUNC_H_INCLUDED
