#include<iostream>
using namespace std;

bool ifPath(int** matrix_edge, int startingVertex, int endingVertex, int vertices, bool* verticesArr) {

    if (matrix_edge[startingVertex][endingVertex] == 1) return true;
    verticesArr[startingVertex] = true;

    for (int idx=0; idx<vertices; idx++) {

        if (startingVertex == idx) continue;

        if (!verticesArr[idx] && matrix_edge[startingVertex][idx] == 1) {
            bool val = ifPath(matrix_edge, idx, endingVertex, vertices, verticesArr);
            if (val) return true;
            else return false;
        }
    }

    return false;
}

int main() {

    int vertices, edges;

    cin >> vertices >> edges;

    int **matrix_edge = new int *[vertices];

    for (int rIdx = 0; rIdx < vertices; rIdx++)
    {

        matrix_edge[rIdx] = new int[vertices];

        for (int cIdx = 0; cIdx < vertices; cIdx++)
        {
            matrix_edge[rIdx][cIdx] = 0;
        }
    }

    for (int idx = 0; idx < edges; idx++)
    {

        int first, second;

        cin >> first >> second;
        matrix_edge[first][second] = 1;
        matrix_edge[second][first] = 1;
    }

    bool *verticesArr = new bool[vertices];

    for (int idx = 0; idx < vertices; idx++)
    {
        verticesArr[idx] = false;
    }

    int startingVertex, endingVertex;

    cin >> startingVertex >> endingVertex;

    bool val = ifPath(matrix_edge, startingVertex, endingVertex, vertices, verticesArr);
    if (val) cout << "true";
    else cout << "false";

}