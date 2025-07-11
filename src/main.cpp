#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <cctype>

#include "aktivitas.h"
#include "buku.h"
#include "graph.h"

using namespace std;

string lower(string s)
{
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c)
              { return tolower(c); });
    return s;
}

void muatAkun(unordered_map<string, string> &akun)
{
    ifstream f("data/akun.txt");
    string line;
    while (getline(f, line))
    {
        istringstream ss(line);
        string nim, pass;
        if (getline(ss, nim, ',') && getline(ss, pass))
            akun[nim] = pass;
    }
}

void muatDaftarBuku(vector<string> &buku)
{
    ifstream f("data/buku.txt");
    string line;
    while (getline(f, line))
        buku.push_back(line);
}

void muatGraf(KampusGraph &k)
{
    ifstream f("data/rute.txt");
    string line;
    while (getline(f, line))
    {
        istringstream ss(line);
        string d, kp, j;
        if (getline(ss, d, ',') && getline(ss, kp, ',') && getline(ss, j))
            k.tambahEdge(d, kp, stoi(j));
    }
}

vector<string> daftarBuku;
void sortBuku() { sort(daftarBuku.begin(), daftarBuku.end()); }
bool searchBuku(const string &j) { return binary_search(daftarBuku.begin(), daftarBuku.end(), j); }

int main()
{
    string nim, pass;
    cout << "\033[1;32m=== SMARTSTUDENT LOGIN ===\033[0m\n";
    cout << "NIM      : ";
    cout.flush();
    getline(cin, nim);
    cout << "Password : ";
    cout.flush();
    getline(cin, pass);

    unordered_map<string, string> akunMahasiswa;
    muatAkun(akunMahasiswa);

    if (akunMahasiswa[nim] != pass)
    {
        cout << "Login gagal!\n";
        return 0;
    }
    cout << "\n\033[1;32mLogin berhasil!\033[0m\n";

    RiwayatAktivitas aktivitas;
    aktivitas.tambahAktivitas("Login Berhasil");

    muatDaftarBuku(daftarBuku);
    BSTBuku perpustakaan;
    for (const auto &b : daftarBuku)
        perpustakaan.tambahBuku(b);

    KampusGraph kampus;
    muatGraf(kampus);

    queue<string> antrean;
    stack<string> pinjam;

    int pil;
    do
    {
        cout << "\n\033[1;36m===== MENU SMARTSTUDENT =====\033[0m\n"
             << "1. Antrean Konsultasi Dosen Akademik\n"
             << "2. Pinjam Buku dari Perpustakaan\n"
             << "3. Tampilkan Koleksi Buku Perpustakaan\n"
             << "4. Cari Judul Buku\n"
             << "5. Lihat Rute Lokasi Kampus\n"
             << "6. Tampilkan Log Aktivitas Mahasiswa\n"
             << "7. Lihat Histori Peminjaman Buku\n"
             << "0. Keluar dari Aplikasi\n"
             << "Pilih menu: ";

        cout.flush();
        if (!(cin >> pil))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore();
        switch (pil)
        {
        case 1:
        {
            antrean.push(nim);
            cout << "Anda masuk antrean konsultasi (posisi "
                 << antrean.size() << ").\n";
            aktivitas.tambahAktivitas("Masuk antrean konsultasi");
            break;
        }

        case 2:
        {
            string jud;
            cout << "Judul buku: ";
            getline(cin, jud);

            if (perpustakaan.cariBuku(jud))
            {
                pinjam.push(jud);
                cout << "Buku '" << jud << "' berhasil dipinjam.\n";
                aktivitas.tambahAktivitas("Pinjam buku: " + jud);
            }
            else
            {
                cout << "Maaf, buku '" << jud
                     << "' tidak tersedia di perpustakaan.\n";
            }
            break;
        }

        case 3:
        {
            cout << "\n\033[1;35mKoleksi Buku Perpustakaan:\033[0m\n";
            perpustakaan.tampilkanBuku();
            break;
        }

        case 4:
        {
            string kunci;
            cout << "Masukkan kata kunci judul: ";
            getline(cin, kunci);

            string kunciL = lower(kunci);
            bool ada = false;

            cout << "\nHasil pencarian:\n";
            for (const auto &judul : daftarBuku)
            {
                if (lower(judul).find(kunciL) != string::npos)
                {
                    cout << "  • " << judul << '\n';
                    ada = true;
                }
            }
            if (!ada)
                cout << "Tidak ada judul yang cocok.\n";

            break;
        }

        case 5:
        {
            string loc;
            cout << "Lokasi awal: ";
            getline(cin, loc);
            kampus.tampilkanRute(loc);
            break;
        }

        case 6:
        {
            aktivitas.tampilkan();
            break;
        }

        case 7:
        {
            if (pinjam.empty())
            {
                cout << "Belum ada buku yang dipinjam.\n";
            }
            else
            {
                cout << "\n\033[1;34mHistori Peminjaman Buku:\033[0m\n";
                stack<string> temp = pinjam;
                int i = 1;
                while (!temp.empty())
                {
                    cout << i++ << ". " << temp.top() << '\n';
                    temp.pop();
                }
            }
            break;
        }

        case 0:
            cout << "Terima kasih telah menggunakan SmartStudent!\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }

    } while (pil != 0);
    return 0;
}
