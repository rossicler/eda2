#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    unsigned int cod;
    int value;
} Item;

void quickSort(Item v[], int l, int r);
int separa(Item v[], int l, int r);
void exch(Item *a, Item *b);
Item *selectFeatures(Item *selected, Item item, int numSelected);

int main () {
    Item *itens = (Item *) malloc(sizeof(Item));
    int count = 0, numSelect;

    scanf("%d", &numSelect);
    while(scanf("%u %d", &itens[count]->cod, &itens[count]->value) == 2) {
        count++;
        itens = (Item *) realloc(itens, (count+1) * sizeof(Item));
    }

    return 0;
}

void quickSort(Item v[], int l, int r) {
    if(l<r) {
        int j = separa(v, l, r);
        quickSort(v, l, j-1);
        quickSort(v, j+1, r);
    }
}

int separa(Item v[], int l, int r) {
    long c = v[r].value;
    int j = l;
    for(int i=l; i<r; i++) {
        if(v[i].value <= c) {
            exch(&v[i], &v[j]);
            j++;
        }
    }
    exch(&v[j], &v[r]);
    return j;
}

void exch(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

long getNextValue(Item v[], int l, int r, long x) {
    int middleIndex;
    if((r+l+1) % 2 == 0) {
        middleIndex = (r+l+1)/2;
    } else {
        middleIndex = (r+l)/2;
    }

    if(x == v[middleIndex].value) {
        return v[middleIndex].nextValue;
    } else if(l>=r) {
        return 0;
    }
    
    if(x > v[middleIndex].value) {
        return getNextValue(v, middleIndex+1, r, x);
    } else {
        return getNextValue(v, l, middleIndex-1, x);
    }
}

Item *selectFeatures(Item *selected, Item item) {

}
