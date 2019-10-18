#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct item {
    char email[MAX];
} Item;

void insertEmail(Item *emails, int *n, char email[]);
char *getEmail(char email[]);
void printList(Item *items, int n);

int main () {
    Item *emails = (Item *) malloc(sizeof(Item));
    char *contacts[MAX] = (char*) malloc(sizeof(char));
    char email[MAX];
    int n;
    scanf("%d", &n);
    int count = 0;
    for(int i=0; i<n; i++) {
        scanf(" %s", email);
        insertEmail(emails, &count, email);
        printList(emails, count);
    }
    printf("%d\n", count);

    return 0;
}

void insertEmail(Item *emails, int *n, char email[]) {
    char newEmail[MAX];
    strcpy(newEmail, getEmail(email));
    int shouldInsert = 1;
    for (int i=0; i<(*n); i++) {
        /*puts(emails[i].email);
        puts(newEmail);
        printf("%d\n", strcmp(emails[i].email, newEmail)); */
        if(strcmp(emails[i].email, newEmail) == 0) {
            return;
        }
    }
    (*n)++;
    emails = (Item *) realloc(emails, (*n)*sizeof(Item));
    strcpy(emails[(*n)-1].email, newEmail);
    printf("%d\n*****%s******\n", (*n), emails[(*n)-1],email);
}

char *getEmail(char email[]) {
    int xPosition = 0, yPosition = 0, isDomain = 0;
    char *newEmail = (char *) malloc(sizeof(char));
    while(email[xPosition] != '\0') {
        if(email[xPosition] == '.' && isDomain == 0) {
            xPosition++;
            continue;
        }
        if(email[xPosition] == '+' && isDomain == 0) {
            while(email[xPosition] != '@') {
                xPosition++;
            }
        }

        if(email[xPosition] == '@') {
            isDomain = 1;
        }

        newEmail[yPosition] = email[xPosition];
        xPosition++;
        yPosition++;
        newEmail = (char *) realloc(newEmail, (yPosition+1)*sizeof(char));
    }
    newEmail = (char *) realloc(newEmail, (yPosition+2)*sizeof(char));
    newEmail[yPosition+1] = '\0';
    return newEmail;
}

void printList(Item *items, int n) {
    for(int i=0; i<n; i++) {
        puts(items[i].email);
    }
}