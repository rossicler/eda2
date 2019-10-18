#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    unsigned int cod;
    int value;
} Item;

int value;

void mergeSort(Item v[], int l, int r);
void merge(Item v[], int l, int m, int r);
Item *select(Item v[], int l, int r, int n);
void exch(Item *x, Item *y);

int main () {
    Item *itens = (Item *) malloc(sizeof(Item));
    int count = 0, numSelect;
    printf("1\n");
    scanf("%d", &numSelect);
    while(scanf("%u %d", &itens[count]->cod, &itens[count]->value) == 2) {
        count++;
        itens = (Item *) realloc(itens, (count+1)*sizeof(Item));
    }
    printf("2\n");
    value = 0;
    mergeSort(itens, 0, count-1);
    printf("3\n");
    value = 1;
    mergeSort(itens, 0, numSelect);
    printf("4\n");
    for(int i=0; i<numSelect; i++) {
        printf("%u %d\n", itens[i]->cod, itens[i]->value);
    }

    return 0;
}

// Encontra e coloca (kind of a selection sort)
Item *select(Item v[], int l, int r, int n) {
    Item *selected = (Item*) malloc(n*sizeof(Item));
    for (int i=0; i<n; i++) {
        selected->cod = 0;
        selected->value = 0;
    }

    for(int i=l; i<r; i++) {
        
    }
}

void exch(Item *x, Item *y) {
    Item temp = *x;
    *x = *y;
    *y = temp;
}

void mergeSort(Item v[], int l, int r) {
    if(l < r) {
        int m = l+(r-l)/2;

        mergeSort(v, l, m);
        mergeSort(v, m+1, r);

        merge(v, l, m, r);
    }
}

void merge(Item v[], int l, int m, int r) {
    int i, j, k;
    Item *lv, *rv;
    int lvLength = m - l + 1;
    int rvLength = r - m;

    lv = (Item *) malloc(lvLength*sizeof(Item));
    rv = (Item *) malloc(rvLength*sizeof(Item));

    for(i = 0; i<lvLength; i++) lv[i] = v[l+i];
    for(j = 0; j<rvLength; j++) rv[j] = v[m+1+j];

    i=0;
    j=0;
    k=l;

    while(i<lvLength && j<rvLength) {
        if(lv[i].cod <= rv[j].cod) {
            v[k] = lv[i];
            i++;
        } else {
            v[k] = rv[j];
            j++;
        }
        k++;
    }

    while(i<lvLength) {
        v[k] = lv[i];
        i++;
        k++;
    }

    while(j<rvLength) {
        v[k] = rv[j];
        j++;
        k++;
    }
    free(lv);
    free(rv);
}
