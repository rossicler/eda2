#include <stdio.h>
#include <stdlib.h>

void quickSort(int *v, int l, int r);
int separa(int *v, int l, int r);
void exch(int *a, int *b);

int main() {
    int *v, vLength=0, n;
    v = (int*) malloc (1 * sizeof(int));
    while(scanf("%d", &v[vLength]) == 1) {
        vLength++;
        v = (int*) realloc (v, (vLength+1) * sizeof(int));
    }
    v = (int*) realloc (v, (vLength) * sizeof(int));

    quickSort(v, 0, vLength-1);

    printf("%d", v[0]);
    for(int i=1; i<vLength; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");

    free(v);
    return 0;
}

int separa(int *v, int l, int r) {
    int c = v[r];
    int j = l;
    for(int i=l; i<r; i++) {
        if(v[i] <= c) {
            exch(&v[i], &v[j]);
            j++;
        }
    }
    exch(&v[j], &v[r]);
    return j;
}

void quickSort(int *v, int l, int r) {
    if(l<r) {
        int j = separa(v, l, r);
        quickSort(v, l, j-1);
        quickSort(v, j+1, r);
    }
}

void exch(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
