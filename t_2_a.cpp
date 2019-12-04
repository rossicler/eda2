#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

int main() {
    int n_places, n_visited, n_requested, i, j;
    vector<int> visited_places;
    int **matrix = new int*[n_places];
    for (i = 0; i < n_places; ++i)
        matrix[i] = new int[n_places];

    std::cin >> n_places;
    std::cin >> n_visited;
    std::cin >> n_requested;

    int n_inline;
    int vertex;
    for(i=0; i<n_places; i++) {
        std::cin >> n_inline;
        for(j=0; j<n_inline; j++) {
            std::cin >> vertex;
            matrix[i][vertex] = 1;
            matrix[vertex][i] = 1;
        }
    }

    for(i=0; i<n_visited; i++) {
        std::cin >> vertex;
        visited_places.push_back(vertex);
        for(j=0; j<n_places; j++) {
            if(matrix[vertex][j] == 1) {
                visited_places.push_back(matrix[vertex][j]);
            }
        }
    }

    while(scanf("%d", &vertex) == 1) {
        check_place(matrix, n_places, visited_places, vertex);
    }

    return 0;
}