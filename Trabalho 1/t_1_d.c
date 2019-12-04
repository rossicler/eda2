#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define MAXLEN 101

void insertEmail(char contacts[MAX][MAXLEN], int *n, char email[]);
char *getEmail(char email[]);

int main () {
    char contacts[MAX][MAXLEN];
    char email[MAXLEN];
    int n;
    scanf("%d", &n);
    int count = 0;
    for(int i=0; i<n; i++) {
        scanf(" %s", email);
        insertEmail(contacts, &count, email);
    }
    printf("%d\n", count);

    return 0;
}

void insertEmail(char contacts[MAX][MAXLEN], int *n, char email[]) {
    char newEmail[MAXLEN];
    strcpy(newEmail, getEmail(email));
    int shouldInsert = 1;
    for (int i=0; i<(*n); i++) {
        if(strcmp(contacts[i], newEmail) == 0) {
            return;
        }
    }
    (*n)++;
    strcpy(contacts[(*n)-1], newEmail);
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
            break;
        }

        newEmail[yPosition] = email[xPosition];
        xPosition++;
        yPosition++;
        newEmail = (char *) realloc(newEmail, (yPosition+1)*sizeof(char));
    }
    int emailLen = strlen(email);
    newEmail = (char *) realloc(newEmail, (yPosition + 1 + emailLen - xPosition)*sizeof(char));
    for(int i=0; i<emailLen-xPosition; i++) {
        newEmail[yPosition+i] = email[xPosition+i];
    }
    newEmail[yPosition+emailLen-xPosition] = '\0';
    return newEmail;
}