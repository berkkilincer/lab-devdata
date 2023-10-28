#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Düðüm yapýsý (node structure) oluþturuyoruz
struct Node {
    int numara;
    char isim[50];
    int yas;
    struct Node* next;
};

// Baðlý listeyi dolaþarak öðrenci bilgilerini ekrana yazdýran ve sayan fonksiyon
void ogrenci_bilgileri(struct Node* head, char aranan_isim[]) {
    int sayac = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (strcmp(current->isim, aranan_isim) == 0) {
            printf("Öðrenci Numarasý: %d\n", current->numara);
            printf("Öðrenci Ýsmi: %s\n", current->isim);
            printf("Öðrenci Yaþý: %d\n", current->yas);
            sayac++;
        }
        current = current->next;
    }
    if (sayac == 0) {
        printf("Aradýðýnýz öðrenci bulunamadý.\n");
    } else {
        printf("Toplam Öðrenci Sayýsý: %d\n", sayac);
    }
}

int main() {
    // Öðrenci bilgileri içeren baðlý listeyi oluþturma
    struct Node* head = NULL;
    struct Node* current = NULL;
    int numara, yas;
    char isim[50];
    int devam = 1;

    while (devam) {
        printf("ogrenci numarasi: ");
        scanf("%d", &numara);
        printf("ogrenci ismi: ");
        scanf("%s", isim);
        printf("ogrenci yasi: ");
        scanf("%d", &yas);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->numara = numara;
        strcpy(newNode->isim, isim);
        newNode->yas = yas;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }

        printf("Devam etmek istiyor musunuz? (1: Evet, 0: Hayir) ");
        scanf("%d", &devam);
    }

    // arama iþlemi yapan fonksiyon
    char aranan_isim[50];
    printf("Aranan ogrenci Ýsmi: ");
    scanf("%s", aranan_isim);
    ogrenci_bilgileri(head, aranan_isim);

    // temizleme
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
