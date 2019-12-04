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
    
    getNSmallest(itens, 0, count-1, numSelect);
    mergeSort(itens, 0, numSelect-1);
    for(int i=0; i<numSelect; i++) {
        printf("%u %d\n", itens[i].cod, itens[i].value);
    }

    return 0;
}

int partition(Item *v, int l, int r) {
    int m;
    if((r+l+1) % 2 == 0) {
        m = (r+l+1)/2;
    } else {
        m = (r+l)/2;
    }

    if((v[l].value <= v[m].value && v[l].value >= v[r].value) || (v[l].value <= v[r].value && v[l].value >= v[m].value)) {
        if(v[l].value == v[r].value && v[r].value == v[m].value) {
            if((v[l].cod < v[m].cod && v[l].cod > v[r].cod) || (v[l].cod < v[r].cod && v[l].cod > v[m].cod)) {
                exch(&v[l], &v[r]);
            } else if ((v[m].cod < v[l].cod && v[m].cod > v[r].cod) || (v[m].cod < v[r].cod && v[m].cod > v[l].cod)) {
                exch(&v[m], &v[r]);
            }
        } else {
            exch(&v[l], &v[r]);
        }
    } else if((v[m].value < v[l].value && v[m].value > v[r].value) || (v[m].value < v[r].value && v[m].value > v[l].value)) {
        exch(&v[m], &v[r]);
    }
    Item pivot = v[r];

	int i = l, x;

	for(x=l; x<r; x++) {
		if(v[x].value < pivot.value) {
			exch(&v[i], &v[x]);
			i++;
		} else if(v[x].value == pivot.value && v[x].cod < pivot.cod) {
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
    quickSelect(v, 0, r, n);
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
