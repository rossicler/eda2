#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 3000
#define STRINGLEN 26

typedef struct city {
    char name[STRINGLEN];
    struct city *next;
} City;

City *lastCity;

City *sort(City *l);
void exch(City *l);
City *newCity(City *l, char name[STRINGLEN]);
void freeList(City *l);
void printList(City *l);

int main () {
    City *cities = NULL;
    int vLength = 0;
    char tempName[STRINGLEN];
    while(scanf("%s", tempName) == 1) {
        cities = newCity(cities, tempName);
        vLength++;
    }

    cities = sort(cities);
    printList(cities);
    freeList(cities);

    return 0;
}

City *newCity(City *l, char name[STRINGLEN]) {
    City *new = (City *) malloc(sizeof(City));
    if(new == NULL) {
        printf("Error trying to allocate memory!");
        exit(-1);
    }
    new->next = NULL;
    strcpy(new->name, name);

    if (l == NULL) {
        l = new;
    } else if (l->next == NULL) {
        l->next = new;
    } else {
        City *temp = l->next;
        lastCity->next = new;
    }
    lastCity = new;
    return l;
}

void freeList(City *l) {
    City *temp;
    for(temp = l; temp != NULL; l = temp) {
        temp = temp->next;
        free(l);
    }
}

void printList(City *l) {
    City *temp;
    for(temp = l; temp != NULL; temp = temp->next) {
        printf("%s\n", temp->name);
    }
}

City *sort(City *l) {
    int len;
    City *temp1;
    for(temp1 = l; temp1->next != NULL; temp1 = temp1->next) {
        len = strlen(temp1->name);
        if(tolower(temp1->name[len-1]) == tolower(temp1->next->name[0])) {
            exch(temp1);
        }
    }
    return l;
}

void exch(City *l) {
    City *end = lastCity, *previousNode, *actualNode;
    previousNode = l;
    actualNode = l->next;
    previousNode->next = actualNode->next;
    end->next = actualNode;
    actualNode->next = NULL;
    lastCity = actualNode;
}