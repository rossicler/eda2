#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 3000
#define STRINGLEN 26

void sort(char v[MAX][STRINGLEN], int l, int r);
void exch(int x, char v[MAX][STRINGLEN], int r);

int main () {
    int vLength = 0;
    char v[MAX][STRINGLEN];
    while(scanf("%s", v[vLength]) == 1) {
        vLength++;
    }

    sort(v, 0, vLength);

    for(int i=0; i<vLength; i++) {
        printf("%s\n", v[i]);
    }

    return 0;
}

void sort(char v[MAX][STRINGLEN], int l, int r) {
    int len;
    for(int i=l+1; i<r; i++) {
        for(int j=i; j<r; j++) {
            len = strlen(v[j-1]);
            if(tolower(v[j-1][len-1]) == tolower(v[j][0])) {
                exch(j, v, r);
            } else {
                break;
            }
        }
    }
}

void exch(int x, char v[MAX][STRINGLEN], int r) {
    char temp[STRINGLEN];
    for(int i=x+1; i<r; i++) {
        strcpy(temp, v[i-1]);
        strcpy(v[i-1], v[i]);
        strcpy(v[i], temp);
    }
}