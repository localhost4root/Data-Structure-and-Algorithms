#include <iostream>
#include <fstream>

using namespace std;

bool HasPath(int V, int** edges, int* visited, int v1, int v2)
{
    if (edges[v1][v2] == 1)
        return true;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] != 1 && edges[v1][i] == 1)
        {
            visited[i] = 1;
            if (HasPath(V, edges, visited, i, v2))
                return true;
        }
    }
    return false;
}

int main()
{
    ifstream FILE("1.txt");
    if (FILE.is_open())
    {
        int V, E;
        FILE >> V >> E;
        cout << "Number of edges and vertexes: " << E << "   " << V<< endl;
        int** edges = new int* [V];
        for (int i = 0; i < V; i++)
        {
            edges[i] = new int[V];
            for (int j = 0; j < V; j++)
            {
                edges[i][j] = 0;
            }
        }

        for (int i = 0; i < E; i++)
        {
            int f, s;
            FILE >> f >> s;
            cout << f <<" "<< s << endl;
            edges[f][s] = 1;
            edges[s][f] = 1;
        }

        int* visited = new int[V];
        for (int i = 0; i < V; i++)
            visited[i] = 0;

        int v1, v2;
        FILE >> v1 >> v2;
        cout << "Find path between : " << v1 << " " << v2 << endl;
        FILE.close();
        bool ans = HasPath(V, edges, visited, v1, v2);
        cout << (ans == 1 ? "true" : "false") << endl;

        for (int i = 0; i < V; i++)
            delete[] edges[i];

        delete[] edges;
        delete[] visited;

    }
    else
    {
        cout << "Error reading file";
    }
    return 0;
}