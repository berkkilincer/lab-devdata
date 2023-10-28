#include <stdio.h>
#include <stdlib.h>

// dugum yapisi
struct Node {
    int numara;
    char isim[50];
    int yas;
    struct Node* next;
};

// öğrenci bilgilerini sayan ve ekrana yazdiran fonk
void ogrenci_bilgileri(struct Node* head) {
    int sayac = 0;
    struct Node* current = head;
    while (current != NULL) {
        printf("ogrenci numarasi: %d\n", current->numara);
        printf("ogrenci İsmi: %s\n", current->isim);
        printf("ogrenci yasi: %d\n", current->yas);
        sayac++;
        current = current->next;
    }
    printf("Toplam ogrenci Sayısı: %d\n", sayac);
}

int main() {
    // bilgi içeren bağlı liste oluşturma
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

    // Öğrenci bilgilerini ekrana yazdırma ve sayma
    ogrenci_bilgileri(head);

    // Belleği serbest bırakma
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
