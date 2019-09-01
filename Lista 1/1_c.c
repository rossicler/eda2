#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE* fp = fopen(argv[1], "r");
    int total = 0;
    while(scanf("%d", &fp) == 1) {
        total += 1;
    }
    printf("%d\n", total);
    return 0;
}
