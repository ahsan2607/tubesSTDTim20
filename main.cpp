#include <iostream>
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
    cout << "MENU UTAMA:" << endl;
    cout << "1. Tambah Poliklinik" << endl;
    cout << "2. Tambah Dokter" << endl;
    cout << "3. Tambah Dokter ke Poliklinik" << endl;
    cout << "4. Tampilkan Semua Poliklinik & Dokter" << endl;
    cout << "5. Tampilkan Dokter di Poliklinik Tertentu" << endl;
    cout << "6. Hapus Poliklinik" << endl;
    cout << "7. Hapus Dokter dari Poliklinik" << endl;
    cout << "8. Hitung Jumlah Dokter di Poliklinik" << endl;
    cout << "9. Poliklinik dengan Dokter Terbanyak" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih: ";
}

void addDummyData(polyclinicList &PL, doctorList &DL, relationList &RL) {
    insertPolyclinicToList(PL, createPolyclinicElm("Poliklinik Jantung", "JANTUNG"));
    insertPolyclinicToList(PL, createPolyclinicElm("Poliklinik Saraf", "SARAF"));
    insertPolyclinicToList(PL, createPolyclinicElm("Poliklinik Anak", "ANAK"));
    insertPolyclinicToList(PL, createPolyclinicElm("Poliklinik Gigi", "GIGI"));

    adrDoctor d1 = createDoctorElm("dr. Ahmad Sp.JP", "D001", "Jantung", "", 0);
    adrDoctor d2 = createDoctorElm("dr. Budi Sp.JP", "D002", "Jantung", "", 0);
    adrDoctor d3 = createDoctorElm("dr. Citra Sp.S", "D003", "Saraf", "", 0);
    adrDoctor d4 = createDoctorElm("dr. Diana Sp.A", "D004", "Anak", "", 0);
    adrDoctor d5 = createDoctorElm("dr. Eko Sp.KG", "D005", "Gigi dan Mulut", "", 0);
    adrDoctor d6 = createDoctorElm("dr. Fajar Sp.JP", "D006", "Jantung", "", 0);

    insertDoctorToList(DL, d1);
    insertDoctorToList(DL, d2);
    insertDoctorToList(DL, d3);
    insertDoctorToList(DL, d4);
    insertDoctorToList(DL, d5);
    insertDoctorToList(DL, d6);

    addDoctorToPolyclinic(RL, createRelationElm(searchPolyclinic(PL, "JANTUNG"), d1, "Senin & Rabu, 08:00-12:00", 10));
    addDoctorToPolyclinic(RL, createRelationElm(searchPolyclinic(PL, "JANTUNG"), d2, "Selasa & Kamis, 13:00-17:00", 8));
    addDoctorToPolyclinic(RL, createRelationElm(searchPolyclinic(PL, "JANTUNG"), d6, "Jumat, 08:00-14:00", 15));
    addDoctorToPolyclinic(RL, createRelationElm(searchPolyclinic(PL, "SARAF"), d3, "Senin & Kamis, 09:00-13:00", 12));
    addDoctorToPolyclinic(RL, createRelationElm(searchPolyclinic(PL, "ANAK"), d4, "Setiap Hari, 08:00-15:00", 7));
    addDoctorToPolyclinic(RL, createRelationElm(searchPolyclinic(PL, "GIGI"), d5, "Senin-Sabtu, 17:00-21:00", 9));
    addDoctorToPolyclinic(RL, createRelationElm(searchPolyclinic(PL, "SARAF"), d1, "Rabu, 14:00-17:00", 10));
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
    string kode, nid, nama, jam;
    int pengalaman;

    do {
        system("cls");
        printHeader();
        printMenu();
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1: {
            cout << "\n--- Tambah Poliklinik ---\n";
            cout << "Nama Poliklinik: "; getline(cin, nama);
            cout << "Kode Poliklinik: "; getline(cin, kode);
            insertPolyclinicToList(PL, createPolyclinicElm(nama, kode));
            break;
        }
        case 2: {
            cout << "\n--- Tambah Dokter ---\n";
            cout << "Nama Dokter: "; getline(cin, nama);
            cout << "NID Dokter : "; getline(cin, nid);
            cout << "Spesialisasi: "; getline(cin, nama); // reuse var
            cout << "Jam Praktik    : "; getline(cin, jam);
            cout << "Pengalaman (tahun): "; cin >> pengalaman; cin.ignore();
            insertDoctorToList(DL, createDoctorElm(nama, nid, nama, jam, pengalaman));
            break;
        }
        case 3: {
            cout << "\n--- Tambah Dokter ke Poliklinik ---\n";
            cout << "Kode Poliklinik: "; getline(cin, kode);
            cout << "NID Dokter     : "; getline(cin, nid);

            adrPolyclinic poly = searchPolyclinic(PL, kode);
            adrDoctor doct = searchDoctor(DL, nid);
            if (poly && doct) {
                addDoctorToPolyclinic(RL, createRelationElm(poly, doct, jam, pengalaman));
                cout << "Dokter berhasil ditambahkan ke poliklinik!\n";
            } else {
                cout << "Poliklinik atau Dokter tidak ditemukan!\n";
            }
            break;
        }
        case 4:
            cout << "\n=== SEMUA POLIKLINIK & DOKTER ===\n";
            showAllPolyclinicAndDoctors(PL, RL);
            break;
        case 5: {
            cout << "\nKode Poliklinik: "; getline(cin, kode);
            cout << "\n";
            printAllDoctorFromPolyclinic(PL, RL, kode);
            break;
        }
        case 6: {
            cout << "\nKode Poliklinik yang dihapus: "; getline(cin, kode);
            deletePolyclinicFromList(PL, kode, RL);
            cout << "Poliklinik dan semua relasinya berhasil dihapus!\n";
            break;
        }
        case 7: {
            cout << "\nKode Poliklinik: "; getline(cin, kode);
            cout << "NID Dokter     : "; getline(cin, nid);
            removeDoctorFromPolyclinic(RL, kode, nid);
            break;
        }
        case 8: {
            cout << "\nKode Poliklinik: "; getline(cin, kode);
            int jumlah = countDoctorInPolyclinic(PL, RL, kode);
            if (searchPolyclinic(PL, kode))
                cout << "Jumlah dokter: " << jumlah << " orang\n";
            break;
        }
        case 9:
            cout << "\n=== POLIKLINIK DENGAN DOKTER TERBANYAK ===\n";
            showPolyclinicWithMostDoctor(PL, RL);
            break;
        case 0:
            cout << "\nTerima kasih! Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }

        if (pilihan != 0) {
            cout << "\nTekan Enter untuk lanjut...";
            cin.get();
        }
    } while (pilihan != 0);

    return 0;
}
