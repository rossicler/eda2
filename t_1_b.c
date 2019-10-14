#include <stdio.h>
#include <stdlib.h>
#define MAX 250000

typedef struct item {
    int visited;
    long value;
    long previousValue, nextValue;
} Item;

void mergeSort(Item v[], int l, int r);
void merge(Item v[], int l, int m, int r);
int getIndex(Item v[], int l, int r, long x);
int findBegin(Item v[], int l, int r, long x);

int main () {
    Item itens[MAX];
    Item ptr1, ptr2;
    int count = 0;

    scanf("%x %x %x", &itens[count].value, &itens[count].previousValue, &itens[count].nextValue);
    ptr1 = itens[count];
    itens[count].visited = 0;
    count++;
    scanf("%x %x %x", &itens[count].value, &itens[count].previousValue, &itens[count].nextValue);
    ptr2 = itens[count];
    itens[count].visited = 0;
    count++;
    while(scanf("%x %x %x", &itens[count].value, &itens[count].previousValue, &itens[count].nextValue) == 3) {
        itens[count].visited = 0;
        count++;
    }

    mergeSort(itens, 0, count-1);

    int prevPtr1Index = getIndex(itens, 0, count-1, ptr1.previousValue);
    int nextPtr2Index = getIndex(itens, 0, count-1, ptr2.nextValue);
    
    itens[prevPtr1Index].nextValue = itens[nextPtr2Index].value;
    itens[nextPtr2Index].previousValue = itens[prevPtr1Index].value;

    int currentIndex = findBegin(itens, 0, count-1, ptr1.previousValue);
    while(itens[currentIndex].value != 0 && currentIndex != -1) {
        if(itens[currentIndex].visited == 1) break;
        printf("%x %x %x\n", itens[currentIndex].value, itens[currentIndex].previousValue, itens[currentIndex].nextValue);
        itens[currentIndex].visited = 1;
        currentIndex = getIndex(itens, 0, count-1, itens[currentIndex].nextValue);
    }
    printf("\n");

    currentIndex = getIndex(itens, 0, count-1, ptr1.value);
    while(itens[currentIndex].value != ptr2.nextValue) {
        if(itens[currentIndex].visited == 1) break;
        printf("%x\n", itens[currentIndex].value);
        itens[currentIndex].visited = 1;
        currentIndex = getIndex(itens, 0, count-1, itens[currentIndex].nextValue);
    }

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

int getIndex(Item v[], int l, int r, long x) {
    int middleIndex;
    if((r+l+1) % 2 == 0) {
        middleIndex = (r+l+1)/2;
    } else {
        middleIndex = (r+l)/2;
    }

    if(x == v[middleIndex].value) {
        return middleIndex;
    } else if(l>=r) {
        return -1;
    }
    
    if(x > v[middleIndex].value) {
        return getIndex(v, middleIndex+1, r, x);
    } else {
        return getIndex(v, l, middleIndex-1, x);
    }
}

int findBegin(Item v[], int l, int r, long x) {
    int previousIndex = getIndex(v, l, r, x);
    int index = getIndex(v, l, r, v[previousIndex].previousValue);
    while(v[index].value != 0 && index != -1) {
        previousIndex = index;
        index = getIndex(v, l, r, v[index].previousValue);
    }
    return previousIndex;
}
