#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    struct node *next;
};

void longest_name(struct node *head) {
    int max_len = 0;
    char longest[50];
    struct node *current = head;
    while (current != NULL) {
        int len = strlen(current->name);
        if (len > max_len) {
            max_len = len;
            strcpy(longest, current->name);
        }
        current = current->next;
    }
    printf("En uzun isim: %s\n", longest);
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    struct node *fourth = malloc(sizeof(struct node));
    struct node *five = malloc(sizeof(struct node));

    strcpy(head->name, "Berk");
    head->next = second;

    strcpy(second->name, "Sevval");
    second->next = third;

    strcpy(third->name, "Saliha");
    third->next = NULL;

    strcpy(fourth->name, "Burak");
    third->next = NULL;

    strcpy(five->name, "Burak");
    third->next = NULL;


    longest_name(head);

    return 0;
}
