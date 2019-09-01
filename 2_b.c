#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

bool searchValue(int *v, int l, int r, int x);
void quickSort(int *v, int l, int r);
int separa(int *v, int l, int r);
void exch(int *a, int *b);

int main() {
    int *v, n, x;
    scanf("%d", &n);
    v = (int *) malloc(n * sizeof(int));
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    quickSort(v, 0, n-1);

    bool found;
    while(scanf("%d", &x) == 1) {
        found = searchValue(v, 0, n, x);
        if(found) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }

    free(v);
    return 0;
}

bool searchValue(int *v, int l, int r, int x) {
    int middleIndex;
    // Get the middle index of the array
    if((r+l+1) % 2 == 0) {
        middleIndex = (r+l+1)/2;
    } else {
        middleIndex = (r+l)/2;
    }
    // See if the number is to the left or
    // right of the array
    if(x == v[middleIndex]) {
        return true;
    } else if(l>=r) {
        return false;
    }
    
    if(x > v[middleIndex]) {
        return searchValue(v, middleIndex+1, r, x);
    } else {
        return searchValue(v, l, middleIndex-1, x);
    }
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
