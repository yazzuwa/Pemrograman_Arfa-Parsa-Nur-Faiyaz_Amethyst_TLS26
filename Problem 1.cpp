#include <iostream>
using namespace std;

int main() {
    int N, K;

    cout << "Masukkan jumlah astronot : ";
    cin >> N;

    cout << "Masukkan nilai K : ";
    cin >> K;

    // Membuat array dinamis
    int* astronot = new int[N];

    // Mengisi nomor astronot 1 sampai N
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }

    int jumlah = N;
    int posisi = 0;

    cout << "\nUrutan eliminasi:\n";

    while (jumlah > 1) {

        // Mencari posisi astronot yang akan dieliminasi
        posisi = (posisi + K - 1) % jumlah;

        // Menyimpan nomor astronot yang dieliminasi
        int tereliminasi = astronot[posisi];

        cout << tereliminasi;

        // Mengubah nilai K
        if (tereliminasi % 2 == 0) {
            K = K + 2;
        } 
        else {
            K = K - 1;
        }

        // K tidak boleh kurang dari 2
        if (K < 2) {
            K = 2;
        }

        // Menghapus astronot dengan menggeser array
        for (int i = posisi; i < jumlah - 1; i++) {
            astronot[i] = astronot[i + 1];
        }

        jumlah--;

        // Setelah penghapusan, posisi tersebut
        // sekarang berisi astronot berikutnya.
        // Jika posisi berada di luar array, kembali ke 0.
        if (posisi == jumlah) {
            posisi = 0;
        }

        if (jumlah > 1) {
            cout << " => ";
        }
    }

    cout << "\n\nAstronot terakhir yang bertahan: "
         << astronot[0] << endl;

    // Membebaskan memori
    delete[] astronot;

    return 0;
}