#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    unsigned long value;
    unsigned long previousValue, nextValue;
    struct item *previous, *next;
} Item;

Item *newItem(Item *itens, Item *temp);
unsigned long getNextValue(Item *itens, unsigned long value);

int main () {
    Item *itens = NULL;
    Item *temp = NULL;
    temp = (Item *) malloc(sizeof(Item));
    unsigned long ptr1, ptr2;

    scanf("%x %x %x", &temp->value, &temp->previousValue, &temp->nextValue);
    ptr1 = temp->value;
    itens = newItem(itens, temp);
    scanf("%x %x %x", &temp->value, &temp->previousValue, &temp->nextValue);
    ptr2 = temp->value;
    itens = newItem(itens, temp);
    while(scanf("%x %x %x", &temp->value, &temp->previousValue, &temp->nextValue) == 3) {
        itens = newItem(itens, temp);
    }

    unsigned long currentValue = getNextValue(itens, ptr1);
    while(currentValue != 0) {
        if(currentValue == ptr2) {
            printf("sana\n");
            return 0;
        }
        currentValue = getNextValue(itens, currentValue);
    }
    prinf("insana\n");
    return 0;
}

Item *newItem(Item *itens, Item *temp) {
    Item *new;
    new = (Item *) malloc(sizeof(Item));
    if(new == NULL) {
        printf("Erro na alocação!\n");
        exit(-1);
    }

    new->value = temp->value;
    new->nextValue = temp->nextValue;
    new->previousValue = temp->previousValue;

    if(itens == NULL) {
        new->next = NULL;
        new->previous = NULL;
        return new;
    } else {
        new->next = itens;
        itens->previous = new;
        return new;
    }
}

unsigned long getNextValue(Item *itens, unsigned long value) {
    Item *temp;
    for(temp = itens; temp->next != NULL; temp = temp->next) {
        if(temp->value == value) {
            return temp->nextValue;
        }
    }
}