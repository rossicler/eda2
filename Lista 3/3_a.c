#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *v, int l, int r);
void merge(int *v, int l, int m, int r);
void printArray(int *v, int n);

int main() {
    int *v, vLength=0, n;
    v = (int*) malloc (1 * sizeof(int));
    while(scanf("%d", &v[vLength]) == 1) {
        vLength++;
        v = (int*) realloc (v, (vLength+1) * sizeof(int));
    }
    v = (int*) realloc (v, (vLength) * sizeof(int));

    mergeSort(v, 0, vLength-1);

    printArray(v, vLength);

    free(v);
    return 0;
}

void mergeSort(int *v, int l, int r) {
    if(l < r) {
        int m = l+(r-l)/2;

        mergeSort(v, l, m);
        mergeSort(v, m+1, r);

        merge(v, l, m, r);
    }
}

void merge(int *v, int l, int m, int r) {
    int i, j, k;
    int *lv, *rv;
    int lvLength = m - l + 1;
    int rvLength = r - m;

    lv = (int *) malloc(lvLength*sizeof(int));
    rv = (int *) malloc(rvLength*sizeof(int));

    for(i = 0; i<lvLength; i++) lv[i] = v[l+i];
    for(j = 0; j<rvLength; j++) rv[j] = v[m+1+j];

    i=0;
    j=0;
    k=l;

    while(i<lvLength && j<rvLength) {
        if(lv[i] <= rv[j]) {
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

void printArray(int *v, int n) {
    printf("%d", v[0]);
    for(int i=1; i<n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}