#include <stdio.h>
#include <stdlib.h>

void minimalyExceeds(int *v, int sum, int index, int n);

int main() {
    int *v, i=0, shouldContinue = 0, n;
    v = (int*) malloc (1 * sizeof(int));
    while(shouldContinue == 0) {
        v = (int*) realloc (v, (i+1) * sizeof(int));
        scanf("%d", &v[i]);
        if (v[i] == 0) {
            shouldContinue = 1;
        }
        i++;
    }
    scanf("%d", &n);

    minimalyExceeds(v, 0, 0, n);
    free(v);
    return 0;
}

void minimalyExceeds(int *v, int sum, int index, int n) {
    if (v[index] != 0) {
        sum += v[index];

        if (sum > n) {
            minimalyExceeds(v, 0, index+1, n);
            printf("%d\n", v[index]);
        } else {
            minimalyExceeds(v, sum, index+1, n);
        }
    } else {
        return;
    }
}
