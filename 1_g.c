#include <stdio.h>
#include <stdlib.h>

int main () {
    int stringLen = 26, vLength = 0;
    char* v = (char*) malloc (1 * stringLen * sizeof(char));
    while(scanf("%s", &v[vLength]) == 1) {
        puts(v[0]);
        vLength++;
        v[vLength] = (char*) realloc (v, (vLength+1) * stringLen * sizeof(char));
    }

    for(int i=0; i<vLength; i++) {
        puts(v[i]);
    }

    free(v);
    return 0;
}