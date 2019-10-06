#include <stdio.h>
#include <stdlib.h>

void setTowerVision(char** map, int n, int m, int* towersHeight);
void setNeighborhoods(char** map, int i, int j, int height, int n, int m);
void setField(char* field);

int nFieldsVision = 0;

int main() {
    char **map;
    int n, m, towersLength=0;
    int *towersHeight;

    scanf("%d", &n);
    scanf("%d", &m);

    map = (char **) malloc(n * sizeof(char*));
    for(int i=0; i<n; i++) {
        map[i] = (char *) malloc((m+1) * sizeof(char));
    }

    for(int i=0; i<n; i++) {
        scanf(" %s", map[i]);
    }

    towersHeight = (int *) malloc(1*sizeof(int));
    while(scanf("%d", &towersHeight[towersLength]) == 1) {
        towersLength++;
        towersHeight = (int *) realloc(towersHeight, (towersLength+1)*sizeof(int));
    }

    setTowerVision(map, n, m, towersHeight);

    printf("%d\n", nFieldsVision);
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++)
            printf("%c", map[i][j]);
        printf("\n");
    }
    
    return 0;
}

void setTowerVision(char** map, int n, int m, int* towersHeight) {
    int i, j;
    int currentTower = 0;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if(map[i][j] == 't') {
                setNeighborhoods(map, i, j, towersHeight[currentTower], n, m);
                currentTower++;
            }
        }
    }
}

void setNeighborhoods(char** map, int i, int j, int height, int n, int m) {
    if(height == 0) {
        return;
    }
    int i_s_1, i_p_1, j_s_1, j_p_1;
    i_s_1 = (i > 0) ? i-1 : 0;
    i_p_1 = (i < n-1) ? i+1 : n-1;
    j_s_1 = (j > 0) ? j-1 : 0;
    j_p_1 = (j < m-1) ? j+1 : m-1;

    setField(&map[i][j]);
    if(height % 2 != 0) {
        setField(&map[i_s_1][j_s_1]);
        setField(&map[i_s_1][j]);
        setField(&map[i_s_1][j_p_1]);
        setField(&map[i][j_s_1]);
        setField(&map[i][j_p_1]);
        setField(&map[i_p_1][j_s_1]);
        setField(&map[i_p_1][j]);
        setField(&map[i_p_1][j_p_1]);
    }

    setNeighborhoods(map, i_s_1, j_s_1, height-1, n, m);
    setNeighborhoods(map, i_s_1, j_p_1, height-1, n, m);
    setNeighborhoods(map, i_p_1, j_s_1, height-1, n, m);
    setNeighborhoods(map, i_p_1, j_p_1, height-1, n, m);
}

void setField(char* field) {
    if(*field == '#') {
        *field = '.';
        nFieldsVision++;
    }
}