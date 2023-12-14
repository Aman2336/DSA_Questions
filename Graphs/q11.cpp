// minimum spanning tree(kruskal's algo & disjoint sets)
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <limits>
using namespace std;
class graph
{
public:
    int u;
    int v;
    int w;
    graph(int u, int v, int w)
    {
        this->u = u;
        this->w = w;
        this->v = v;
    }
};
void makeset(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
bool cmp(graph g1, graph g2)
{
    return g1.w < g2.w;
}
int findparent(int node, vector<int> &parent)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findparent(parent[node], parent);
}
void unionset(int u, int v, vector<int> &rank, vector<int> &parent)
{
    u = findparent(u, parent);
    v = findparent(v, parent);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int mst(int n, vector<graph> edges)
{
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent, rank, n);
    int min = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        graph g = edges[i];
        int x = findparent(g.u, parent);
        int y = findparent(g.v, parent);
        int z = g.w;
        if (x != y)
        {
            unionset(x, y, parent, rank);
            min += z;
        }
    }
    return min;
}

int main()
{
    // 0 1 3
    // 0 3 5
    // 1 2 1
    // 2 3 8

// 1 2 6
// 2 3 2
// 1 3 2
// 1 0 2
    graph g1(1, 2, 6);
    graph g2(2, 3, 2);
    graph g3(1, 3, 2);
    graph g4(1, 0, 2);
    vector<graph> edges;
    edges.push_back(g1);
    edges.push_back(g2);
    edges.push_back(g3);
    edges.push_back(g4);
    cout<<mst(4,edges);
}