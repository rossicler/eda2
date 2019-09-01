#include <stdio.h>
#include <stdlib.h>

int searchValue(int *v, int l, int r, int x);

int main() {
    int *houses, *deliveries, housesLength, deliveriesLength;
    scanf("%d %d", &housesLength, &deliveriesLength);

    houses = (int*) malloc (housesLength * sizeof(int));
    deliveries = (int*) malloc (deliveriesLength * sizeof(int));

    for(int i=0; i<housesLength; i++) {
        scanf("%d", &houses[i]);
    }

    for(int i=0; i<deliveriesLength; i++) {
        scanf("%d", &deliveries[i]);
    }

    int currentPosition = 0, nextPosition, timeSpent = 0;
    for(int i=0; i<deliveriesLength; i++) {
        nextPosition = searchValue(houses, 0, housesLength-1, deliveries[i]);
        timeSpent += abs(nextPosition - currentPosition);
        currentPosition = nextPosition;
    }

    printf("%d\n", timeSpent);

    free(houses);
    free(deliveries);
    return 0;
}

int searchValue(int *v, int l, int r, int x) {
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
        return middleIndex;
    } else if(l>=r) {
        return 0;
    }
    
    if(x > v[middleIndex]) {
        return searchValue(v, middleIndex+1, r, x);
    } else {
        return searchValue(v, l, middleIndex-1, x);
    }
}
