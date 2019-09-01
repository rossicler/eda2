#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    char *nome;
    struct pessoa *prox;
    struct pessoa *ant;
} Pessoa;

Pessoa *initList();
Pessoa *insert(Pessoa *l, char*);
void freeList(Pessoa *l);
void printList(Pessoa *l);
void bubbleSort(Pessoa *l);

int main() {
    Pessoa *students = initList();
    int studentsLength, winnerIndex;

    scanf("%d %d", &studentsLength, &winnerIndex);

    char *tempName = (char *) malloc(20 * sizeof(char));
    for(int i=0; i<studentsLength; i++) {
        scanf("%s", tempName);
        students = insert(students, tempName);
    }

    bubbleSort(students);
    
    Pessoa *winner = students;
    for(int i=1; i<winnerIndex; winner = winner->prox, i++);
    printf("%s\n", winner->nome);
    
    freeList(students);
    return 0;
}

Pessoa *initList() {
    return NULL;
}

Pessoa *insert(Pessoa *l, char *nome) {

    Pessoa *novo;
    novo = (Pessoa *) malloc(sizeof(Pessoa));
    if(novo == NULL) {
        printf("Erro na alocação!\n");
        exit(-1);
    }

    novo->nome = (char*) malloc(sizeof(char)*20);

    strcpy(novo->nome, nome);

    if(l == NULL) {
        novo->prox = NULL;
        novo->ant = NULL;
        return novo;
    } else {
        novo->prox = l;
        l->ant = novo;
        return novo;
    }
}

void freeList(Pessoa *l) {
    Pessoa *aux;

    for(aux = l; aux != NULL; l = aux) {
        aux = aux->prox;
        free(l);
    }
}

void printList(Pessoa *l){
    Pessoa *aux;

    for(aux = l; aux != NULL; aux = aux->prox) {
        printf("------------------------------\n");
        printf("Nome: %s\n", aux->nome);
    }

}

void bubbleSort(Pessoa *l) {
    int swapped, i;
    Pessoa *ptrl;
    Pessoa *lptr = NULL;

    if(l == NULL) {
        return;
    }

    char *tempName = (char *) malloc(20 * sizeof(char));

    do {
        swapped = 0;
        ptrl = l;

        while(ptrl->prox != lptr) {
            if(strcmp(ptrl->nome, ptrl->prox->nome) > 0) {
                strcpy(tempName, ptrl->nome);
                strcpy(ptrl->nome, ptrl->prox->nome);
                strcpy(ptrl->prox->nome, tempName);
                swapped = 1;
            }
            ptrl = ptrl->prox;
        }
        lptr = ptrl;
    } while(swapped);
}
