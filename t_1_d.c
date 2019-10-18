#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct item {
    char email[MAX];
} Item;

void insertEmail(Item *emails, int *n, char email[]);
int sameEmail(char emailX[], char emailY[]);

int main () {
    Item *emails = (Item *) malloc(sizeof(Item));
    char email[MAX];
    int n;
    scanf("%d", &n);
    int count = 0;
    for(int i=0; i<n; i++) {
        scanf(" %s", email);
        insertEmail(emails, &count, email);
    }
    printf("%d\n", count);

    return 0;
}

void insertEmail(Item *emails, int *n, char email[]) {
    int shouldInsert = 1;
    for (int i=0; i<(*n); i++) {
        if(sameEmail(emails[i].email, email) == 1) {
            return;
        }
    }
    printf("----------------------------\n");
    (*n)++;
    emails = (Item *) realloc(emails, (*n)*sizeof(Item));
    strcpy(emails[(*n)-1].email, email);
}

int sameEmail(char emailX[], char emailY[]) {
    int isSame = 1, xPosition = 0, yPosition = 0, isDomain = 0;
    puts(emailX);
    puts(emailY);
    printf("----------------------------\n");
    char x, y;
    while(1) {
        x = emailX[xPosition];
        y = emailY[yPosition];
        if (x == '\0' && y == '\0') {
            break;
        }

        if(x == '.' && !isDomain) {
            xPosition++;
            continue;
        }
        if(x == '+' && !isDomain) {
            while(emailX[xPosition] != '@') {
                xPosition++;
            }
        }
        if(y == '.' && !isDomain) {
            yPosition++;
            continue;
        }
        if(y == '+' && !isDomain) {
            while(emailY[yPosition] != '@') {
                yPosition++;
            }
        }

        if(x == '@' && y == '@') {
            isDomain = 1;
        }

        if (x != y) {
            isSame = 0;
            break;
        }
        xPosition++;
        yPosition++;
    }
    return isSame;
}