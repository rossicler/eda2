#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    unsigned int cod;
    int value;
} Item;

int value;

void mergeSort(Item *v, int l, int r);
void merge(Item *v, int l, int m, int r);
void getNSmallest(Item *v, int l, int r, int n);
void exch(Item *x, Item *y);

int main () {
    Item *itens = (Item *) malloc(sizeof(Item));
    int count = 0, numSelect;
    scanf("%d", &numSelect);
    while(scanf("%u %d", &itens[count].cod, &itens[count].value) == 2) {
        count++;
        itens = (Item *) realloc(itens, (count+1)*sizeof(Item));
    }
    
    getNSmallest(itens, 0, count, numSelect);
    mergeSort(itens, 0, numSelect-1);
    for(int i=0; i<numSelect; i++) {
        printf("%u %d\n", itens[i].cod, itens[i].value);
    }

    return 0;
}

void getNSmallest(Item *v, int l, int r, int n) {
    int i, j, k;
    for(i=l; i<n; i++) {
        k = i;
        for(j=i; j<r; j++) {
            if (v[j].value < v[k].value) {
                k = j;
            } else if (v[j].value == v[k].value && v[j].cod < v[k].cod) {
                k = j;
            }
        }
        exch(&v[i], &v[k]);
    }
}

void exch(Item *x, Item *y) {
    Item temp = *x;
    *x = *y;
    *y = temp;
}

void mergeSort(Item *v, int l, int r) {
    if(l < r) {
        int m = l+(r-l)/2;

        mergeSort(v, l, m);
        mergeSort(v, m+1, r);

        merge(v, l, m, r);
    }
}

void merge(Item *v, int l, int m, int r) {
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
