#include <stdio.h>
#include <stdlib.h>
#define MAX 250000

typedef struct item {
    long value;
    long previousValue, nextValue;
} Item;

void mergeSort(Item v[], int l, int r);
void merge(Item v[], int l, int m, int r);
void quickSort(Item v[], int l, int r);
int separa(Item v[], int l, int r);
void exch(Item *a, Item *b);
long getNextValue(Item v[], int l, int r, long x);

int main () {
    Item itens[MAX];
    long ptr1, ptr2;
    int count = 0;

    scanf("%x %x %x", &itens[count].value, &itens[count].previousValue, &itens[count].nextValue);
    ptr1 = itens[count].value;
    count++;
    scanf("%x %x %x", &itens[count].value, &itens[count].previousValue, &itens[count].nextValue);
    ptr2 = itens[count].value;
    count++;
    while(scanf("%x %x %x", &itens[count].value, &itens[count].previousValue, &itens[count].nextValue) == 3) {
        count++;
    }

    mergeSort(itens, 0, count-1);

    long currentValue = getNextValue(itens, 0, count-1, ptr1);
    while(currentValue != 0 && currentValue  != ptr1) {
        if(currentValue == ptr2) {
            printf("sana\n");
            return 0;
        }
        currentValue = getNextValue(itens, 0, count-1, currentValue);
    }
    printf("insana\n");
    return 0;
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
        if(lv[i].value <= rv[j].value) {
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
