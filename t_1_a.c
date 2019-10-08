#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 250000

typedef struct item {
    long value;
    long previousValue, nextValue;
} Item;

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

    quickSort(itens, 0, count-1);

    long currentValue = getNextValue(itens, 0, count-1, ptr1);
    while(currentValue != 0) {
        if(currentValue == ptr2) {
            printf("sana\n");
            return 0;
        }
        currentValue = getNextValue(itens, 0, count-1, currentValue);
    }
    printf("insana\n");
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
