// Depth First Search

#include <iostream>
using namespace std;

void print(int **graph, int vertices, int startingVertex, bool* arr)
{   
    cout << startingVertex << endl;
    arr[startingVertex] = true;

    for (int idx=0; idx<vertices; idx++) {

        if (startingVertex == idx) {
            continue;
        }

        if (!arr[idx] && graph[startingVertex][idx] == 1) {
            print(graph, vertices, idx, arr);
        }
    }
}

int main()
{

    int vertices, edges;

    cin >> vertices >> edges;

    int **graph = new int *[vertices];

    for (int rIdx = 0; rIdx < vertices; rIdx++)
    {

        graph[rIdx] = new int[vertices];

        for (int cIdx = 0; cIdx < vertices; cIdx++)
        {
            graph[rIdx][cIdx] = 0;
        }
    }

    for (int idx = 0; idx < edges; idx++)
    {

        int first, second;

        cin >> first >> second;
        graph[first][second] = 1;
        graph[second][first] = 1;
    }

    bool* arr = new bool[vertices];

    for (int idx=0; idx<vertices; idx++) {
        arr[idx] = false;
    }
    
    print(graph, vertices, 0, arr);

    
    return 0;
}