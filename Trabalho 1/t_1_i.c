#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *l, *r;
} Node;

Node *rotR(Node *h);
Node *rotL(Node *h);
Node *insertT(Node *h, int value);
void printInOrder(Node *h, int isRoot);
Node *newNode(int value);

int main () {
    Node *h = NULL;
    int temp;

    while(scanf("%d", &temp) == 1) {
        h = insertT(h, temp);
        printInOrder(h, 1);
        printf(".\n");
    }


    return 0;
}

Node *rotR(Node *h) {
	Node *x = h->l;
	h->l = x->r;
	x->r = h;
	return x;
}

Node *rotL(Node *h) {
	Node *x = h->r;
	h->r = x->l;
	x->l = h;
	return x;
}

Node *insertT(Node *h, int value) {
	if(h==NULL) return newNode(value);
	if(value < h->value) {
		h->l = insertT(h->l, value);
		h = rotR(h);
	} else {
		h->r = insertT(h->r, value);
		h = rotL(h);
	}
	return h;
}

void printInOrder(Node *h, int isRoot) {
	if(h==NULL) return;
	printInOrder(h->l, 0);
    if(isRoot == 1) printf("*%d ", h->value);
    else printf("%d ", h->value);
	printInOrder(h->r, 0);
}

Node *newNode(int value) {
    Node *h = (Node *) malloc(sizeof(Node));
    h->value = value;
    h->l = NULL;
    h->r = NULL;
    return h;
}