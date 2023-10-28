#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ogrenci dügüm yapisi
struct Ogrenci {
    int ogrenciNo;
    char ad[50];
    struct Ogrenci* next;
};

// yeni kayıt ekleme uyapan fonksiyon
struct Ogrenci* ogrenciEkle(struct Ogrenci* head, int no, const char* ad) {
    struct Ogrenci* yeniOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    yeniOgrenci->ogrenciNo = no;
    strcpy(yeniOgrenci->ad, ad);
    yeniOgrenci->next = NULL;

    if (head == NULL) {
        return yeniOgrenci;
    }

    struct Ogrenci* gecici = head;
    while (gecici->next != NULL) {
        gecici = gecici->next;
    }
    gecici->next = yeniOgrenci;

    return head;
}

// ekrana yazdırma işlemi
void ogrenciListesiYazdir(struct Ogrenci* head) {
    struct Ogrenci* gecici = head;
    while (gecici != NULL) {
        printf("Ogrenci No: %d, Ad: %s\n", gecici->ogrenciNo, gecici->ad);
        gecici = gecici->next;
    }
}

// ogrenci silme fonksiyonu
struct Ogrenci* ogrenciSilSonraki(struct Ogrenci* head, const char* hedefisim) {
    if (head == NULL) {
        printf("Listede kayıt yok  Silme islemi yapilamaz.\n");
        return head;
    }

    struct Ogrenci* gecici = head;
    while (gecici->next != NULL) {
        if (strcmp(gecici->ad, hedefisim) == 0) {
            struct Ogrenci* silinecek = gecici->next;
            gecici->next = silinecek->next;
            free(silinecek);
            printf("%s adl� ogrencinin sonraki ogrencisi silindi.\n", hedefisim);
            return head;
        }
        gecici = gecici->next;
    }

    printf("%s adli ogrenci bulunamadi veya listenin sonunda bulunuyor.\n", hedefisim);
    return head;
}

int main() {
    struct Ogrenci* liste = NULL;

    // ��renci kay�tlar� ekleniyor
    liste = ogrenciEkle(liste, 1, "berk");
    liste = ogrenciEkle(liste, 2, "sevval");
    liste = ogrenciEkle(liste, 3, "burak");
    liste = ogrenciEkle(liste, 4, "şafak");
    liste = ogrenciEkle(liste, 5, "umut");
    liste = ogrenciEkle(liste, 6, "eren");

    // ��renci listesini ekrana yazd�r
    printf("Ogrenci Listesi:\n");
    ogrenciListesiYazdir(liste);

    // Kullan�c�dan silinecek ��rencinin ad�n� al
    char silinecekAd[50];
    printf("Hangi ogrenciden sonraki ogrenciyi silmek istersiniz? ��renci adini girin: ");
    scanf("%s", silinecekAd);

    // ��renci silme i�lemi
    liste = ogrenciSilSonraki(liste, silinecekAd);

    // G�ncellenmi� ��renci listesini ekrana yazd�r
    printf("Guncellenmis Ogrenci Listesi:\n");
    ogrenciListesiYazdir(liste);

    // Belle�i temizle (serbest b�rak)
    while (liste != NULL) {
        struct Ogrenci* temp = liste;
        liste = liste->next;
        free(temp);
    }

    return 0;
}

