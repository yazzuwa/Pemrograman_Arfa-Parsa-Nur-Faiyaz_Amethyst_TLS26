#include <iostream>
using namespace std;

int main() {
    char pesan[100];
    char hasil[100];

    cout << "====================================" << endl;
    cout << "        PROGRAM SANDI ALIEN" << endl;
    cout << "====================================" << endl;

    cout << "Masukkan pesan : ";

    // Membaca pesan satu karakter demi satu karakter
    int panjang = 0;
    char karakter;

    while (cin.get(karakter) && karakter != '\n') {
        pesan[panjang] = karakter;
        panjang++;
    }

    // Menambahkan tanda akhir array
    pesan[panjang] = '\0';

    // Menyimpan nilai huruf sebelumnya
    int nilaiSebelumnya = 0;

    for (int i = 0; i < panjang; i++) {

        // Jika karakter adalah spasi
        if (pesan[i] == ' ') {
            hasil[i] = ' ';
        }

        // Jika karakter adalah huruf
        else {
            int nilaiSekarang = pesan[i] - 'A' + 1;

            // Huruf pertama setelah spasi / awal pesan
            if (i == 0 || pesan[i - 1] == ' ') {
                hasil[i] = pesan[i];
                nilaiSebelumnya = nilaiSekarang;
            }

            // Huruf berikutnya
            else {
                int nilaiBaru = nilaiSekarang + nilaiSebelumnya;

                // Jika melewati Z
                while (nilaiBaru > 26) {
                    nilaiBaru = nilaiBaru - 26;
                }

                hasil[i] = 'A' + nilaiBaru - 1;

                // Nilai huruf asli menjadi nilai sebelumnya
                nilaiSebelumnya = nilaiSekarang;
            }
        }
    }

    hasil[panjang] = '\0';

    cout << endl;
    cout << "Pesan asli    : " << pesan << endl;
    cout << "Pesan tersandi : " << hasil << endl;

    return 0;
}