// Depth First Search

#include <iostream>
#include <queue>
using namespace std;

void print(int **graph, int vertices, int startingVertex, bool *arr)
{
    queue<int> q;
    q.push(startingVertex);
    arr[0] = true;

    while (q.size() > 0)
    {
        int sv = q.front();

        q.pop();

        cout << sv << endl;

        for (int idx = 0; idx < vertices; idx++)
        {

            if (!arr[idx] && graph[sv][idx] == 1)
            {
                q.push(idx);
                arr[idx] = true;
            }
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

    bool *arr = new bool[vertices];

    for (int idx = 0; idx < vertices; idx++)
    {
        arr[idx] = false;
    }

    print(graph, vertices, 0, arr);

    return 0;
}