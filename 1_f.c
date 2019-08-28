#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* v, int l, int r);
void compexch(int a, int b);

int main (int argc, char* argv[]) {
    int vLength = 1;
    int* v = (int*) malloc (vLength * sizeof(int));
    while(scanf("%d", v[vLength-1]) == 1) {
        printf("aaaa\n");
        printf("%d\n", v[vLength-1]);
        vLength++;
        v = (int*) realloc (v, (vLength) * sizeof(int));
    }

    return 0;
}

void compexch(int a, int b) {
    if(b < a) {
        int temp = b;
	b = a;
	a = temp;
    }
}

void insertionSort(int* v, int l, int r) {
    int i, j;
    for(i=r; i>l; i--) compexch(v[i], v[i-l]);
    for(i=l+1; i<=r; i++) {
        int menor = v[i];
	j = i;
	while(menor < v[j-1]) {
	    v[j] = v[j-1];
	    j--;
	}
	v[i] = menor;
    }
}

