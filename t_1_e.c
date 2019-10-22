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
int partition(Item *v, int l, int r);
int quickSelect(Item *v, int l, int r, int k);

int main () {
    Item *itens = (Item *) malloc(sizeof(Item));
    int count = 0, numSelect;
    scanf("%d", &numSelect);
    while(scanf("%u %d", &itens[count].cod, &itens[count].value) == 2) {
        count++;
        itens = (Item *) realloc(itens, (count+1)*sizeof(Item));
    }
    
    getNSmallest(itens, 0, count, numSelect);
    mergeSort(itens, 0, numSelect);
    for(int i=1; i<numSelect+1; i++) {
        printf("%u %d\n", itens[i].cod, itens[i].value);
    }

    return 0;
}

int partition(Item *v, int l, int r) {
    int middleIndex;
    if((r+l+1) % 2 == 0) {
        middleIndex = (r+l+1)/2;
    } else {
        middleIndex = (r+l)/2;
    }

	Item pivot = v[r];
    /*if(v[l].value > v[middleIndex].value && v[l].value < v[r].value) {
        pivot = v[l];
    } else if(v[middleIndex].value > v[r].value && v[middleIndex].value < v[l].value) {
        pivot = v[middleIndex];
    } else {
        pivot = v[r];
    } */

	int i = l, x;

	for(x=l; x<r; x++) {
		if(v[x].value < pivot.value) {
			exch(&v[i], &v[x]);
			i++;
		}
	}

    exch(&v[i], &v[r]);
    return i;
}

int quickSelect(Item *v, int l, int r, int k) {
    if(k>0 && k < r-l+1) {
        int p = partition(v, l, r);
        if(p - l == k-1) {
            return p;
        } else if(k-1 < p - l) {
            return quickSelect(v, l, p-1, k);
        } else {
            return quickSelect(v, p+1, r, k-p+l-1);
        }
    }
}

void getNSmallest(Item *v, int l, int r, int n) {
    int i;
    for(i=l; i<n; i++) {
        quickSelect(v, i, r, 1);
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
