#include <iostream>
#include <string>
#include "doctorFuncDLL.h"
#include "polyclinicFuncDLL.h"
#include "relationFuncDLL.h"

using namespace std;

void printHeader() {
    cout << "===================================================" << endl;
    cout << "          SISTEM ADMINISTRASI RUMAH SAKIT" << endl;
    cout << "             Poliklinik & Dokter (DLL)" << endl;
    cout << "===================================================" << endl;
}

void printMenu() {
    cout << "===================================================" << endl;
    cout << "                  MENU UTAMA" << endl;
    cout << "===================================================" << endl;

    cout << endl << "--- POLIKLINIK ---" << endl;
    cout << "1. Tambah Poliklinik" << endl;
    cout << "2. Hapus Poliklinik" << endl;
    cout << "3. Cari dan Tampilkan Poliklinik" << endl;
    cout << "4. Tampilkan Semua Poliklinik" << endl;

    cout << endl << "--- DOKTER ---" << endl;
    cout << "5. Tambah Dokter" << endl;
    cout << "6. Cari dan Tampilkan Dokter" << endl;
    cout << "7. Tampilkan Semua Dokter" << endl;
    cout << "8. Tampilkan Dokter dengan Spesialisasi Tertentu" << endl;
    cout << "9. Hapus Dokter" << endl;

    cout << endl << "--- PENUGASAN DOKTER KE POLIKLINIK ---" << endl;
    cout << "10. Tambah Dokter ke Poliklinik" << endl;
    cout << "11. Hapus Dokter dari Poliklinik" << endl;

    cout << endl << "--- LAPORAN & QUERY ---" << endl;
    cout << "12. Tampilkan Semua Poliklinik & Dokter" << endl;
    cout << "13. Tampilkan Dokter di Poliklinik Tertentu" << endl;
    cout << "14. Hitung Jumlah Dokter di Poliklinik" << endl;
    cout << "15. Poliklinik dengan Dokter Terbanyak" << endl;

    cout << endl << "0. Keluar" << endl;
    cout << "===================================================" << endl;
    cout << "Pilih: ";
}

void addDummyData(polyclinicList &PL, doctorList &DL, relationList &RL) {
    insertPolyclinicToList(PL, createPolyclinicElm("Poliklinik Jantung", "JANTUNG"));
    insertPolyclinicToList(PL, createPolyclinicElm("Poliklinik Saraf", "SARAF"));
    insertPolyclinicToList(PL, createPolyclinicElm("Poliklinik Anak", "ANAK"));
    insertPolyclinicToList(PL, createPolyclinicElm("Poliklinik Gigi", "GIGI"));

    adrDoctor d1 = createDoctorElm("dr. Ahmad Sp.JP", "D001", "Jantung", "08:00-16:00", 15);
    adrDoctor d2 = createDoctorElm("dr. Budi Sp.JP", "D002", "Jantung", "09:00-17:00", 10);
    adrDoctor d3 = createDoctorElm("dr. Citra Sp.S", "D003", "Saraf", "10:00-18:00", 12);
    adrDoctor d4 = createDoctorElm("dr. Diana Sp.A", "D004", "Anak", "07:00-15:00", 8);
    adrDoctor d5 = createDoctorElm("dr. Eko Sp.KG", "D005", "Gigi dan Mulut", "08:00-14:00", 20);
    adrDoctor d6 = createDoctorElm("dr. Fajar Sp.JP", "D006", "Jantung", "13:00-21:00", 5);

    insertDoctorToList(DL, d1);
    insertDoctorToList(DL, d2);
    insertDoctorToList(DL, d3);
    insertDoctorToList(DL, d4);
    insertDoctorToList(DL, d5);
    insertDoctorToList(DL, d6);

    addDoctorToPolyclinic(RL, createRelationElm(searchPolyclinic(PL, "JANTUNG"), d1));
    addDoctorToPolyclinic(RL, createRelationElm(searchPolyclinic(PL, "JANTUNG"), d2));
    addDoctorToPolyclinic(RL, createRelationElm(searchPolyclinic(PL, "JANTUNG"), d6));
    addDoctorToPolyclinic(RL, createRelationElm(searchPolyclinic(PL, "SARAF"), d3));
    addDoctorToPolyclinic(RL, createRelationElm(searchPolyclinic(PL, "ANAK"), d4));
    addDoctorToPolyclinic(RL, createRelationElm(searchPolyclinic(PL, "GIGI"), d5));
}

int main() {
    polyclinicList PL;
    doctorList DL;
    relationList RL;

    createPolyclinicList(PL);
    createDoctorList(DL);
    createRelationList(RL);

    addDummyData(PL, DL, RL);

    int pilihan;
    string kode, nid, nama, spec, jam;
    int pengalaman;

    do {
        cout << string(50, '\n');
        printHeader();
        printMenu();

        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1: { // Tambah Poliklinik
            cout << endl << "=== Tambah Poliklinik ===" << endl;
            cout << "Nama Poliklinik  : ";
            getline(cin, nama);
            cout << "Kode Poliklinik  : ";
            getline(cin, kode);
            insertPolyclinicToList(PL, createPolyclinicElm(nama, kode));
            break;
        }
        case 2: { // Hapus Poliklinik
            cout << endl << "Kode Poliklinik yang akan dihapus: ";
            getline(cin, kode);
            deletePolyclinicFromList(PL, kode, RL);
            break;
        }
        case 3: { // Cari Poliklinik
            cout << endl << "Kode Poliklinik  : ";
            getline(cin, kode);
            printFoundPolyclinic(searchPolyclinic(PL, kode));
            break;
        }
        case 4: { // Tampilkan Semua Poliklinik
            cout << endl << "=== Daftar Semua Poliklinik ===" << endl;
            printAllPolyclinic(PL);
            break;
        }
        case 5: { // Tambah Dokter
            cout << endl << "=== Tambah Dokter ===" << endl;
            cout << "Nama Dokter      : ";
            getline(cin, nama);
            cout << "NID Dokter       : ";
            getline(cin, nid);
            cout << "Spesialisasi     : ";
            getline(cin, spec);
            cout << "Jam Praktik      : ";
            getline(cin, jam);
            cout << "Pengalaman(tahun): ";
            cin >> pengalaman;
            cin.ignore();
            insertDoctorToList(DL, createDoctorElm(nama, nid, spec, jam, pengalaman));
            break;
        }
        case 6: { // Cari Dokter
            cout << endl << "NID Dokter       : ";
            getline(cin, nid);
            printFoundDoctor(searchDoctor(DL, nid));
            break;
        }
        case 7: { // Tampilkan Semua Dokter
            cout << endl << "=== Daftar Semua Dokter ===" << endl;
            printAllDoctor(DL);
            break;
        }
        case 8: { // Dokter berdasarkan Spesialisasi
            cout << endl << "Spesialisasi yang dicari: ";
            getline(cin, spec);
            printDoctorWithSpecialization(DL, spec);
            break;
        }
        case 9: { // Hapus Dokter
            cout << endl << "NID Dokter yang akan dihapus: ";
            getline(cin, nid);
            deleteDoctorFromList(DL, nid, RL);
            break;
        }
        case 10: { // Tambah Dokter ke Poliklinik
            cout << endl << "=== Tambah Dokter ke Poliklinik ===" << endl;
            cout << "Kode Poliklinik  : ";
            getline(cin, kode);
            cout << "NID Dokter       : ";
            getline(cin, nid);
            adrPolyclinic poly = searchPolyclinic(PL, kode);
            adrDoctor doct = searchDoctor(DL, nid);
            if (poly && doct) {
                addDoctorToPolyclinic(RL, createRelationElm(poly, doct));
            } else {
                cout << "Poliklinik atau Dokter tidak ditemukan!" << endl;
            }
            break;
        }
        case 11: { // Hapus Dokter dari Poliklinik
            cout << endl << "=== Hapus Dokter dari Poliklinik ===" << endl;
            cout << "Kode Poliklinik  : ";
            getline(cin, kode);
            cout << "NID Dokter       : ";
            getline(cin, nid);
            removeDoctorFromPolyclinic(RL, kode, nid);
            break;
        }
        case 12: { // Tampilkan Semua Poliklinik & Dokter
            cout << endl << "=== Daftar Semua Poliklinik dan Dokter ===" << endl;
            showAllPolyclinicAndDoctors(PL, RL);
            break;
        }
        case 13: { // Dokter di Poliklinik Tertentu
            cout << endl << "Kode Poliklinik  : ";
            getline(cin, kode);
            cout << endl;
            printAllDoctorFromPolyclinic(PL, RL, kode);
            break;
        }
        case 14: { // Hitung Jumlah Dokter
            cout << endl << "Kode Poliklinik  : ";
            getline(cin, kode);
            adrPolyclinic poly = searchPolyclinic(PL, kode);
            if (poly) {
                int jumlah = countDoctorInPolyclinic(PL, RL, kode);
                cout << "Jumlah dokter    : " << jumlah << " orang" << endl;
            } else {
                cout << "Poliklinik tidak ditemukan!" << endl;
            }
            break;
        }
        case 15: { // Poliklinik dengan Dokter Terbanyak
            cout << endl << "=== Poliklinik dengan Dokter Terbanyak ===" << endl;
            showPolyclinicWithMostDoctor(PL, RL);
            break;
        }
        case 0: {
            cout << endl << "Terima kasih! Program selesai." << endl;
            break;
        }
        default:
            cout << endl << "Pilihan tidak valid!" << endl;
        }

        if (pilihan != 0) {
            cout << endl << "Tekan Enter untuk kembali ke menu...";
            cin.get();
        }

    } while (pilihan != 0);

    return 0;
}
