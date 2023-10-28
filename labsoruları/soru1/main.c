#include <stdio.h>
#include <stdlib.h>

// bu aşamada düğüm tanımlarız
struct dugum {
    int veri;
    struct dugum* sonraki;
};

// bir düğüm oluşturup veriyi ekleme işini yapan fosnksiyon
struct dugum* dugumOlustur(int veri) {
    struct dugum* yeniDugum = (struct dugum*)malloc(sizeof(struct dugum));
    yeniDugum->veri = veri;
    yeniDugum->sonraki = NULL;
    return yeniDugum;
}

// yaptığımız listeye (başından) veri ekleyen fonskiyon
void listeBasinaEkle(struct dugum** bas, int veri) {
    struct dugum* yeniDugum = dugumOlustur(veri);
    yeniDugum->sonraki = *bas;
    *bas = yeniDugum;
}

// yaptığımız listenin (sonundan) veri ekleyen fonksiyon
void listeSonunaEkle(struct dugum** bas, int veri) {
    struct dugum* yeniDugum = dugumOlustur(veri);

    if (*bas == NULL) {
        *bas = yeniDugum;
        return;
    }

    struct dugum* temp = *bas;
    while (temp->sonraki != NULL) {
        temp = temp->sonraki;
    }
    temp->sonraki = yeniDugum;
}

// yazdırma işini yapan yani yaptığımız listeyi yazdıran fonskiyon
void listeYazdir(struct Dugum* bas) {
    struct dugum* temp = bas;
    while (temp != NULL) {
        printf("%d ", temp->veri);
        temp = temp->sonraki;
    }
    printf("\n");
}

int main() {
    struct dugum* tekler = NULL; // tek sayilar listesi
    struct dugum* ciftler = NULL; // çift sayilar listesi
    int sayi;

    printf("Sayilari girin :\n");

    while (1) {
        scanf("%d", &sayi);

        if (sayi == -1) {
            break;
        }

        if (sayi % 2 == 0) {
            listeSonunaEkle(&ciftler, sayi);
        } else {
            listeBasinaEkle(&tekler, sayi);
        }
    }

    printf("Tek Sayilar: ");
    listeYazdir(tekler);

    printf("Cift Sayilar: ");
    listeYazdir(ciftler);

    // temizleme
    while (tekler != NULL) {
        struct dugum* temp = tekler;
        tekler = tekler->sonraki;
        free(temp);
    }
    while (ciftler != NULL) {
        struct dugum* temp = ciftler;
        ciftler = ciftler->sonraki;
        free(temp);
    }

    return 0;
}
