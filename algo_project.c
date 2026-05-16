/*
LAB Project Team
COMP6112036 - AYCA - LAB
Group-4:
1. 2902814942 - Alfira Putri Nurlita
2. 2902804014 - Christian Hotasi Viccare Hutagaol
3. 2902816336 - Christoffer Yoel Evandri Viebrian
4. 2902813126 - Irfan Siswara
5. 2902827232 - Muh Faisal Bimantara
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char kode[10];
    char nama[100];
    char jenis[100];
    double harga;
} Book;

typedef struct
{
    char kodeBuku[10];
    int jumlahTerjual;
    double totalHarga;
} History;

Book books[100];
History histories[100];

int totalBook = 0;
int totalHistory = 0;

void loadBook() {
    FILE *fp = fopen("databuku.txt", "r");

    if (fp == NULL) {
        return;
    }

    while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%lf\n",
        books[totalBook].kode,
        books[totalBook].nama,
        books[totalBook].jenis,
        &books[totalBook].harga) != EOF
    ) {
        totalBook++;
    }

    fclose(fp);
}

void generateBookCode(char code[]) {
    sprintf(code, "BK%03d", totalBook + 1);
}

// Function untuk menambahkan data buku baru
void inputBook() {
    generateBookCode(books[totalBook].kode);

    printf("\nInput Data Buku\n");

    printf("Kode Buku : %s\n", books[totalBook].kode);

    printf("Nama Buku : ");
    scanf(" %[^\n]", books[totalBook].nama);

    printf("Jenis Buku : ");
    scanf(" %[^\n]", books[totalBook].jenis);

    printf("Harga Buku : ");
    scanf("%lf", &books[totalBook].harga);

    totalBook++;

    printf("\nData buku berhasil ditambahkan!\n");
}

void viewHistory() {
}

// Function untuk menampilkan seluruh data buku
void viewBook() {
    if (totalBook == 0) {
        printf("\nTidak ada data buku!\n");
        return;
    }

    for (int i = 0; i < totalBook; i++) {

        printf("%d. %s | %s | %s | %.2lf\n",
            i + 1,
            books[i].kode,
            books[i].nama,
            books[i].jenis,
            books[i].harga);
    }
}

void deleteHistory() {
}

void deleteBook() {
}

void saveBookAndHistory() {
}

void inputTransaction() {
}

int main(void)
{
    int select_menu;
    int menu_validation;

    //get book and history data
    loadBook();

    while (1)
    {
        // clear terminal
        system("cls");

        puts("Toko Buku Literasi Nusantara Jaya");
        puts("1. Input Data Buku Baru");
        puts("2. View History Transaksi Penjualan");
        puts("3. View Buku");
        puts("4. Delete History");
        puts("5. Delete Buku");
        puts("6. Exit");
        puts("7. Input Transaksi Penjualan");
        puts("8. Sort Buku (berdasarkan nama dan harga)");

        do
        {
            printf("\nPilih Menu [1-8]: ");
            menu_validation = scanf("%d", &select_menu);
            while (getchar() != '\n');

            if (menu_validation != 1) {
                printf("Input harus angka!\n");
                while (getchar() != '\n');
                select_menu = 0;
            }else if (select_menu < 1 || select_menu > 8) {
                printf("Menu tidak tersedia!\n");
            }
        }while(select_menu < 1 || select_menu > 8);

        switch (select_menu) {
            case 1:
                inputBook();
                break;
            case 2:
                viewHistory();
                break;
            case 3:
                viewBook();
                break;
            case 4:
                deleteHistory();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                saveBookAndHistory();
                return 0;
            case 7:
                inputTransaction();
                break;
            case 8: break;
        }

        printf("\nTekan Enter untuk kembali ke menu awal");
        getchar();
        printf("\n");
    }

    return 0;
}