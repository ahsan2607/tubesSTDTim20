#ifndef DLL_RELATION_FUNC_H_INCLUDED
#define DLL_RELATION_FUNC_H_INCLUDED

#include "doctorTypeDLL.h"
#include "polyclinicTypeDLL.h"
#include "relationTypeDLL.h"

void createRelationList(relationList &L);
/*  I.S. -
    F.S. List relasi L terinisialisasi sebagai list kosong,
         dengan L.first dan L.last bernilai nullptr. */

adrRelation createRelationElm(adrPolyclinic poly, adrDoctor doct);
/*  I.S. Terdefinisi pointer adrPolyclinic poly dan pointer adrDoctor doct.
    F.S. Mengembalikan adrRelation (pointer ke relationElm baru)
         dengan parent bernilai poly, child bernilai doct,
         prev dan next bernilai nullptr. */

void addDoctorToPolyclinic(relationList &L, adrRelation p);
/*  I.S. Terdefinisi list relasi L sudah terinisialisasi (boleh kosong),
         adrRelation p sudah dialokasikan.
         Diasumsikan dokter dari p belum assigned ke suatu poliklinik.
    F.S. Jika dokter belum assigned, p disisipkan di akhir list L.
         Jika L kosong, L.first dan L.last jadi p.
         Jika sudah assigned, p dihapus dan pesan error.
         List L diubah jika sukses. */

adrRelation findRelation(relationList &L, string codePoly, string nidDoctor);
/*  I.S. Terdefinisi list relasi L sudah terinisialisasi (boleh kosong),
         codePoly(kode poliklinik) dan nidDoctor(kode dokter) adalah string untuk pencarian.
    F.S. Mengembalikan adrRelation jika ditemukan relasi dengan
         parent->info.code sama dengan codePoly dan child->info.nid sama dengan nidDoctor.
         Mengembalikan nullptr jika tidak ditemukan atau list kosong. */

void removeDoctorFromPolyclinic(relationList &L, string codePoly, string nidDoctor);
/*  I.S. Terdefinisi list relasi L sudah terinisialisasi (boleh kosong),
         codePoly(kode poliklinik) dan nidDoctor(kode dokter) berupa string.
    F.S. Jika relasi ditemukan, dihapus dari list L (handle first, last, middle, single).
         Memory relasi dibebaskan, pesan sukses.
         Jika tidak ditemukan, pesan error. List L diubah jika sukses. */

void printAllDoctorFromPolyclinic(polyclinicList PL, relationList RL, string code);
/*  I.S. Terdefinisi list poliklinik PL dan list relasi RL sudah terinisialisasi,
         code(kode poliklinik) berupa string untuk acuan poliklinik yang dokternya yang ditampilkan.
    F.S. Jika poliklinik ditemukan, tampilkan semua dokter terkait via relasi RL dalam format detail.
         Jika tidak ada dokter, pesan "Tidak ada dokter".
         Jika poliklinik tidak ditemukan, pesan error. */

int countDoctorInPolyclinic(polyclinicList PL, relationList RL, string code);
/*  I.S. Terdefinisi list poliklinik PL dan list relasi RL sudah terinisialisasi,
         code(kode poliklinik) berupa string untuk acuan poliklinik yang dokternya yang dihitung.
    F.S. Mengembalikan jumlah dokter terkait polyclinic dengan code via relasi RL.
         Jika poliklinik tidak ditemukan, kembalikan 0. */

void showPolyclinicWithMostDoctor(polyclinicList PL, relationList RL);
/*  I.S. Terdefinisi list poliklinik PL dan list relasi RL sudah terinisialisasi (boleh kosong),
    F.S. Cari poliklinik di PL dengan jumlah dokter terbanyak via RL, tampilkan detailnya.
         Jika ada yang jumlahnya sama, tampilkan salah satu.
         Jika kosong, pesan "Tidak ada poliklinik". */

void showAllPolyclinicAndDoctors(polyclinicList PL, relationList RL);
/*  I.S. Terdefinisi list poliklinik PL dan list relasi RL sudah terinisialisasi (boleh kosong).
    F.S. Tampilkan semua polyclinic di PL beserta dokter-dokter terkait via RL ke cout dalam format nested.
         Jika kosong, pesan "Tidak ada poliklinik". */

bool isDoctorAlreadyAssigned(relationList RL, string nid);
/*  I.S. Terdefinisi list poliklinik PL dan list relasi RL sudah terinisialisasi (boleh kosong).
         nid(kode dokter) berupa string.
    F.S. Mengembalikan true jika ada relasi dengan child.nid sama dengan nid, false jika tidak. */

#endif // DLL_RELATION_FUNC_H_INCLUDED
