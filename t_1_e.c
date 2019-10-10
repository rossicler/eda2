#include <stdio.h>
#include <stdlib.h>
#define MAX 10000000

typedef struct item {
    unsigned int cod;
    int value;
} Item;

int value;

void quickSort(Item v[], int l, int r);
int separa(Item v[], int l, int r);
void exch(Item *a, Item *b);

int main () {
    Item itens[MAX];
    int count = 0, numSelect;
    printf("1\n");
    scanf("%d", &numSelect);
    while(scanf("%u %d", &itens[count].cod, &itens[count].value) == 2) {
        count++;
    }
    printf("2\n");
    value = 0;
    quickSort(itens, 0, count-1);
    printf("3\n");
    value = 1;
    quickSort(itens, 0, numSelect);
    printf("4\n");
    for(int i=0; i<numSelect; i++) {
        printf("%u %d\n", itens[i].cod, itens[i].value);
    }

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
    if (value == 1) {
	unsigned int c = v[r].cod;
	int j = l;
	for(int i=l; j<r; i++){
	    if(v[i].cod <= c) {
	        exch(&v[i], &v[j]);
		j++;
	    }
	}
	exch(&v[j], &v[r]);
	return j;
    }
    int c = v[r].value;
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
