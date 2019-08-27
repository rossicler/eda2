#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Erro ao ler o aquivo!\n");
        return 1;
    }
    printf("1\n");
    int height, n_branchs;
    fscanf(fp, "%d", &height);
    printf("%d\n", height);
    fscanf(fp, "%d", &n_branchs);
    printf("%d\n", n_branchs);

    int* x_branchs = (int*) malloc(n_branchs * sizeof(int));
    char* y_branchs = (char*) malloc(n_branchs * sizeof(char));
    for(int i=0; i<n_branchs; i++) {
        fscanf(fp, "%c %d", y_branchs[i], x_branchs[i]);
    }
    printf("2\n");

    char player_position;
    fscanf(fp, "%d", &player_position);
    printf("3\n");

    char* commands;
    fscanf(fp, "%s", commands);

    return 0;
}
