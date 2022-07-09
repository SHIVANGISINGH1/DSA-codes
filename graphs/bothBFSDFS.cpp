// Here we will implement both DFS(depth first search) and BFS(Breadth first search)

#include<iostream>
#include<queue>
using namespace std;

void DFS(int** matrix_edge, int vertices, int startingVertex, bool* verticesArr) {

    cout << startingVertex << endl;
    verticesArr[startingVertex] = true;

    for (int idx=0; idx<vertices; idx++) {

        if (idx == startingVertex) continue;

        if (verticesArr[idx] == false && matrix_edge[startingVertex][idx] == 1) {
            DFS(matrix_edge, vertices, idx, verticesArr);
        }
    }
}

void BFS(int **matrix_edge, int vertices, int startingVertex, bool* verticesArr) {

    queue<int> verticesQueue;
    verticesQueue.push(startingVertex);
    verticesArr[startingVertex] = true;

    while(verticesQueue.size() > 0) {

        int val = verticesQueue.front();

        cout << val << endl;
        verticesQueue.pop();

        for (int idx=0; idx<vertices; idx++) {

            if (idx == val) {
                continue;
            }

            if (verticesArr[idx] == false && matrix_edge[val][idx] == 1) {
                verticesQueue.push(idx);
                verticesArr[idx] = true;
            }
        }
    }
}

int main() {

    int vertices,edges;

    cin >> vertices >> edges;

    int **matrix_edge = new int*[vertices];

    for (int rIdx=0; rIdx<vertices; rIdx++) {
        
        matrix_edge[rIdx] = new int[vertices];

        for (int cIdx=0; cIdx<vertices; cIdx++) {
            matrix_edge[rIdx][cIdx] = 0;
        }
    }

    for (int idx=0; idx<edges; idx++) {

        int first;
        int second;

        cin >> first >> second;

        matrix_edge[first][second] = 1;
    }


    bool *verticesArr = new bool[vertices];

    for (int idx=0; idx<vertices; idx++) {
        verticesArr[idx] = false;
    }
    cout << "DFS:: " << endl;
    DFS(matrix_edge, vertices, 0, verticesArr);
    for (int idx=0; idx<vertices; idx++) {
        verticesArr[idx] = false;
    }
    cout << "BFS:: " << endl;
    BFS(matrix_edge, vertices, 0, verticesArr);

    return 0;
}
