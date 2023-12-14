#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;
class graph
{
public:
    unordered_map<int, list<int> > adj;
    void addedge(int u, int v, bool flag)
    {
        adj[u].push_back(v);
        if (flag == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printlist()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
    bool solve2(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfscall)
    {

        dfscall[node] = 1;
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto i : adj[front])
            {

                if (visited[i] == true && dfscall[i] == true)
                {
                    return true;
                }
                else if (!visited[i])
                {
                    bool ans = solve2(i, visited, dfscall);
                    if (ans)
                    {
                        return true;
                    }
                }
            }
        }
        dfscall[node] = false;
        return false;
    }
    bool checkcycle(int n)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfscall;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bool ans = solve2(i, visited, dfscall);
                if (ans == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    graph g;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, 1);
    }
    g.printlist();

    if(g.checkcycle(n)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}