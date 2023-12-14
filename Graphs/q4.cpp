// topological sort
//(only for directed acyclic graph)
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include <stack>
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
    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s)
    {
        visited[node] = 1;
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                dfs(i, visited, s);
            }
        }
        s.push(node);
    }
    vector<int> tsort(int n)
    {
        vector<int> ans;
        unordered_map<int, bool> visited;
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, s);
            }
        }
        while (!s.empty())
        {

            ans.push_back(s.top());
            s.pop();
        }
        return ans;
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

    vector<int> ans = g.tsort(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}