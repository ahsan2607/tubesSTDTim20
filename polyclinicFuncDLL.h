#ifndef DLL_POLYCLINIC_FUNC_H_INCLUDED
#define DLL_POLYCLINIC_FUNC_H_INCLUDED

#include "polyclinicTypeDLL.h"
#include "relationTypeDLL.h"

void createPolyclinicList(polyclinicList &L);
/*  I.S. -
    F.S. polyclinicList L terinisialisasi sebagai list kosong,
         dengan L.first dan L.last bernilai nullptr. */

adrPolyclinic createPolyclinicElm(string name, string code);
/*  I.S. Terdefinisi name dan code adalah string.
    F.S. Mengembalikan adrPolyclinic (pointer ke polyclinicElm baru)
         dengan info->name bernilai name, info->code bernilai code,
         prev dan next bernilai nullptr. */

void insertPolyclinicToList(polyclinicList &L, adrPolyclinic p);
/*  I.S. Terdefinisi list poliklinik L sudah terinisialisasi (boleh kosong),
         adrPolyclinic p sudah dialokasikan, code dari p unik.
    F.S. Jika code unik, p disisipkan di depan list L.
         Jika L kosong, L.first dan L.last jadi p. Jika code duplikat,
         p tidak disisipkan dan pesan error ditampilkan. */

adrPolyclinic searchPolyclinic(polyclinicList L, string code);
/*  I.S. Terdefinisi list poliklinik L sudah terinisialisasi (boleh kosong),
         code adalah string untuk dicari.
    F.S. Mengembalikan adrPolyclinic jika ditemukan elemen dengan info.code sama dengan code,
         atau nullptr jika tidak ditemukan atau list kosong. */

void deletePolyclinicFromList(polyclinicList &L, string code, relationList &RL);
/*  I.S. Terdefinisi list poliklinik L dan list relasi RL sudah terinisialisasi, code adalah string.
         Diasumsikan RL mungkin punya relasi ke poliklinik dengan kode ini.
    F.S. Semua relasi di RL yang melibatkan poliklinik dengan code dihapus dulu (pakai removeDoctorFromPolyclinic).
         Kemudian, jika poliklinik ditemukan di L, dihapus dari list L (handle kasus first, last, middle, single).
         Memory poliklinik dibebaskan. Jika tidak ditemukan, pesan error. */

void printFoundPolyclinic(adrPolyclinic poly);
/*  I.S. Terdefinisi adrPolyclinic poly boleh nullptr atau pointer valid ke polyclinicElm.
    F.S. Jika poly tidak sama dengan nullptr, tampilkan detail poliklinik (code, nama).
         Jika nullptr, tampilkan "Poliklinik tidak ditemukan". */

void printAllPolyclinic(polyclinicList L);
/*  I.S. Terdefinisi list poliklinik L sudah terinisialisasi (boleh kosong).
    F.S. Semua poliklinik di L ditampilkan dalam format detail (dari first ke last).
         Jika kosong, tampilkan "Tidak ada poliklinik dalam daftar". */

#endif // DLL_POLYCLINIC_FUNC_H_INCLUDED
