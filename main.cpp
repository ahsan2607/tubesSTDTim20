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

int main() {
    polyclinicList PL;
    doctorList DL;
    relationList RL;

    createPolyclinicList(PL);
    createDoctorList(DL);
    createRelationList(RL);

    string pilihan;
    string kode, nid, nama, spec, jam;
    int pengalaman;

    do {
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "===================================================" << endl;
        cout << "          SISTEM ADMINISTRASI RUMAH SAKIT" << endl;
        cout << "             Poliklinik & Dokter (DLL)" << endl;
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

        getline(cin, pilihan);

        if (pilihan == "1") {
            cout << endl << "=== Tambah Poliklinik ===" << endl;
            cout << "Kode Poliklinik  : ";
            getline(cin, kode);
            cout << "Nama Poliklinik  : ";
            getline(cin, nama);
            if (kode != "" && nama != ""){
                insertPolyclinicToList(PL, createPolyclinicElm(nama, kode));
            } else {
                cout << "Tidak boleh ada input kosong" << endl;
            }
        }
        else if (pilihan == "2") {
            cout << endl << "=== Hapus Poliklinik ===" << endl;
            cout << "Kode Poliklinik yang akan dihapus: ";
            getline(cin, kode);
            deletePolyclinicFromList(PL, kode, RL);
        }
        else if (pilihan == "3") {
            cout << endl << "=== Cari Poliklinik ===" << endl;
            cout << "Kode Poliklinik  : ";
            getline(cin, kode);
            printFoundPolyclinic(searchPolyclinic(PL, kode));
        }
        else if (pilihan == "4") {
            cout << endl << "=== Daftar Semua Poliklinik ===" << endl;
            printAllPolyclinic(PL);
        }
        else if (pilihan == "5") {
            cout << endl << "=== Tambah Dokter ===" << endl;
            cout << "NID Dokter       : ";
            getline(cin, nid);
            cout << "Nama Dokter      : ";
            getline(cin, nama);
            cout << "Spesialisasi     : ";
            getline(cin, spec);
            cout << "Jam Praktik      : ";
            getline(cin, jam);
            cout << "Pengalaman(tahun): ";
            cin >> pengalaman;
            cin.ignore();
            if (nid != "" && nama != "" && spec != "" && jam != ""){
                insertDoctorToList(DL, createDoctorElm(nama, nid, spec, jam, pengalaman));
            } else {
                cout << "Tidak boleh ada input kosong" << endl;
            }
        }
        else if (pilihan == "6") {
            cout << endl << "=== Cari Dokter ===" << endl;
            cout << "NID Dokter       : ";
            getline(cin, nid);
            printFoundDoctor(searchDoctor(DL, nid));
        }
        else if (pilihan == "7") {
            cout << endl << "=== Daftar Semua Dokter ===" << endl;
            printAllDoctor(DL);
        }
        else if (pilihan == "8") {
            cout << endl << "=== Cari Dokter Spesialisasi Tertentu ===" << endl;
            cout << "Spesialisasi yang dicari: ";
            getline(cin, spec);
            printDoctorWithSpecialization(DL, spec);
        }
        else if (pilihan == "9") {
            cout << endl << "=== Hapus Dokter ===" << endl;
            cout << "NID Dokter yang akan dihapus: ";
            getline(cin, nid);
            deleteDoctorFromList(DL, nid, RL);
        }
        else if (pilihan == "10") {
            cout << endl << "=== Tambah Dokter ke Poliklinik ===" << endl;
            cout << "Kode Poliklinik  : ";
            getline(cin, kode);
            cout << "NID Dokter       : ";
            getline(cin, nid);
            adrPolyclinic poly = searchPolyclinic(PL, kode);
            adrDoctor doct = searchDoctor(DL, nid);
            if (poly != nullptr && doct != nullptr) {
                addDoctorToPolyclinic(RL, createRelationElm(poly, doct));
            } else {
                if (poly == nullptr) {
                    cout << "Poliklinik tidak ditemukan!" << endl;
                } else if (doct == nullptr) {
                    cout << "Dokter tidak ditemukan!" << endl;
                } else {
                    cout << "Poliklinik atau Dokter tidak ditemukan!" << endl;
                }
            }
        }
        else if (pilihan == "11") {
            cout << endl << "=== Hapus Dokter dari Poliklinik ===" << endl;
            cout << "Kode Poliklinik  : ";
            getline(cin, kode);
            cout << "NID Dokter       : ";
            getline(cin, nid);
            removeDoctorFromPolyclinic(RL, kode, nid);
        }
        else if (pilihan == "12") {
            cout << endl << "=== Daftar Semua Poliklinik dan Dokter ===" << endl;
            showAllPolyclinicAndDoctors(PL, RL);
        }
        else if (pilihan == "13") {
            cout << endl << "=== Dokter di Poliklinik ===" << endl;
            cout << "Kode Poliklinik  : ";
            getline(cin, kode);
            printAllDoctorFromPolyclinic(PL, RL, kode);
        }
        else if (pilihan == "14") {
            cout << endl << "=== Jumlah Dokter di Poliklinik ===" << endl;
            cout << "Kode Poliklinik  : ";
            getline(cin, kode);
            cout << "Jumlah dokter    : " << countDoctorInPolyclinic(PL, RL, kode) << " orang" << endl;
        }
        else if (pilihan == "15") {
            cout << endl << "=== Poliklinik dengan Dokter Terbanyak ===" << endl;
            showPolyclinicWithMostDoctor(PL, RL);
        }
        else if (pilihan == "0") {
            cout << endl << "Terima kasih! Program selesai." << endl;
        }
        else {
            cout << endl << "Pilihan tidak valid!" << endl;
        }

        if (pilihan != "0") {
            cout << endl << "Tekan Enter untuk kembali ke menu...";
            getline(cin, pilihan);
        }

    } while (pilihan != "0");

    return 0;
}

