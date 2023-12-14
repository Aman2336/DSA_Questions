#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;
class graph2
{
public:
    int n;
    bool **adj;
    graph2(int n)
    {
        this->n = n;
        adj = new bool *[n];
        for (int i = 0; i < n; i++)
        {
            adj[i] = new bool[n];
        }
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {
                adj[i][j] = 0;
            }
        }
    }
    void addedge(int u, int v, bool direction)
    {
        adj[u][v] = 1;
        if (direction == 0)
        {
            adj[v][u] = 1;
        }
    }
    void printmatrix()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};
class graph
{
public:
    unordered_map<int, list<int> > adj;
    void addedge(int u, int v, bool direction)
    {
        // direction - 1 directed
        // direction - 0 undirected

        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printadjlist()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};
int main()
{
    // graph g;
    // int n;
    // int m;
    // cin >> n >> m;
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     g.addedge(u, v, 0);
    // }

    // g.printadjlist();
    graph2 g(5);
    for (int i = 0; i < 6; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, 0);
    }
    g.printmatrix();
    return 0;
}