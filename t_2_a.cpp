#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

void mergeSort(vector<int> &v);
void merge(vector<int> &left, vector<int> &right, vector<int> &v);

int main() {
    int n_places, n_visited, n_requested, i, j;
    vector<int> visited_places;

    cin >> n_places >> n_visited >> n_requested;

    int **matrix = new int*[n_places];
    for (i = 0; i < n_places; ++i)
        matrix[i] = new int[n_places];

    int n_inline;
    int vertex;
    for(i=0; i<n_places; i++) {
        cin >> n_inline;
        for(j=0; j<n_inline; j++) {
            cin >> vertex;
            matrix[i][vertex] = 1;
            matrix[vertex][i] = 1;
        }
    }

    for(i=0; i<n_visited; i++) {
        cin >> vertex;
        visited_places.push_back(vertex);
        for(j=0; j<n_places; j++) {
            if(matrix[vertex][j] == 1) {
                visited_places.push_back(j);
            }
        }
    }
    
    mergeSort(visited_places);
    while(scanf("%d", &vertex) == 1) {
        if (binary_search(visited_places.begin(), visited_places.end(), vertex)) {
            cout << "Eu vou estar la" << endl;
        } else {
            cout << "Nao vou estar la" << endl;
        }
    }

    return 0;
}

void mergeSort(vector<int> &v) {
    if(v.size() <= 1) return;

    int mid = v.size() / 2;
    vector<int> left;
    vector<int> right;

    for (size_t j = 0; j < mid;j++)
        left.push_back(v[j]);
    for (size_t j = 0; j < (v.size()) - mid; j++)
        right.push_back(v[mid + j]);

    mergeSort(left);
    mergeSort(right);
    merge(left, right, v);
}

void merge(vector<int> &left, vector<int> &right, vector<int> &v) {
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR) 
    {
        if (left[j] < right[k]) {
            v[i] = left[j];
            j++;
        }
        else {
            v[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL) {
        v[i] = left[j];
        j++; i++;
    }
    while (k < nR) {
        v[i] = right[k];
        k++; i++;
    }
}