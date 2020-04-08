#include <stdio.h>
#include <stdlib.h>
#define MAX 5000

typedef struct duck {
    int color;
    int count;
    struct duck *next;
} Duck;

void insertToStruct(Duck ducks[], int *nInserted);
void initList(Duck ducks[]);

int main() {
    int n;

    scanf("%d", &n);
    Duck *ducks = (Duck *) malloc(n*sizeof(Duck));
    initList(ducks);
    while(n != 0) {
        for(int i=0; i<n;i++) {
            insertToStruct(ducks);
        }
    }

    return 0;
}

void insertToStruct(Duck ducks[], int *nInserted) {
    int temp;
    scanf("%d", &temp);

    Duck *ducksTemp;
    if(ducks->next == NULL) {
        ducks->next = (Duck *) malloc(sizeof(Duck));
        scanf("%d", &ducks->next->color);
        ducks->next->count = 1;
        return;
    }
    for(ducksTemp = ducks; ducksTemp->next != NULL; ducksTemp=ducksTemp->next) {
        if(ducksTemp->next == NULL) {
            ducksTemp->
        } else {
            if(temp > ducksTemp->next->color) {

            }
        }
    }
}

void initList(Duck ducks[]) {
    ducks->color = 0;
    ducks->count = 0;
    ducks->next = NULL;
}