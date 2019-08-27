#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, sum = 0, temp;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
	scanf("%d", &temp);
	sum += temp;
    }
    printf("%d\n", sum);
    return 0;
}
