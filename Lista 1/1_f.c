#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* v, int l, int r);

int main () {
    int vLength = 1;
    int* v = (int*) malloc (vLength * sizeof(int));
    while(scanf("%d", &v[vLength-1]) == 1) {
        vLength++;
        v = (int*) realloc (v, (vLength) * sizeof(int));
    }

    insertionSort(v, 0, vLength-2);

    printf("%d", v[0]);
    for (int i=1; i<vLength-1; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");

    return 0;
}

void insertionSort(int*v, int l, int r) {
    int i, menor, j;
    for (i=1; i<=r; i++) {
        menor = v[i];
        j = i-1;

        while(j>=0 && v[j] > menor) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = menor;
    }
}

