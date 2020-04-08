#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int separa(char m[100][21], int l, int r);
void quickSort(char m[100][21], int l, int r);
void exch(char a[21], char b[21]);

int main() {
    char m[100][21];
    int studentsLength, winnerIndex;

    scanf("%d", &studentsLength);
    scanf("%d", &winnerIndex);

    for(int i=0; i<studentsLength; i++) {
        scanf(" %s", m[i]);
    }

    quickSort(m, 0, studentsLength-1);
    
    printf("%s\n", m[winnerIndex-1]);
    
    return 0;
}

int separa(char m[100][21], int l, int r) {
    char c[21];
    strcpy(c, m[r]);
    int j = l;
    for(int i=l; i<r; i++) {
        if(strcmp(m[i], c) <= 0) {
            exch(m[i], m[j]);
            j++;
        }
    }
    exch(m[j], m[r]);
    return j;
}

void quickSort(char m[100][21], int l, int r) {
    if(l<r) {
        int j = separa(m, l, r);
        quickSort(m, l, j-1);
        quickSort(m, j+1, r);
    }
}

void exch(char a[21], char b[21]) {
    char temp[21];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

