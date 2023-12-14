// bfs traversal
// dfs traversal
#include <iostream>
#include <unordered_map>
#include <list>
#include <map>
#include <vector>
#include <queue>
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
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
    void solve(int i, vector<int> &ans, map<int, bool> &visited)
    {
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto j : adj[front])
            {
                if (!visited[j])
                {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }
    vector<int> bfs(int n)
    {
        vector<int> ans;
        map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                solve(i, ans, visited);
            }
        }
        return ans;
    }
    void solve2(int i, vector<int> &component, map<int, bool> &visited)
    {
        component.push_back(i);
        visited[i] = true;

        for (auto j : adj[i])
        {
            if (!visited[j])
            {
                solve2(i, component, visited);
            }
        }
    }
    vector<vector<int> > dfs(int n)
    {
        vector<vector<int> > ans;
        map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {

            if (!visited[i])
            {
                vector<int> component;
                solve2(i, component, visited);
                ans.push_back(component);
            }
        }
        return ans;
    }
};

int main()
{
    graph g;
    int n;
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, 0);
    }

    g.printlist();

    vector<int> ans = g.bfs(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    vector<vector<int> > ans2 = g.dfs(n);
    for (int i = 0; i < ans2.size(); i++)
    {
        for (int j = 0; j < ans2[i].size(); j++)
        {
            cout << ans2[i][j] << " ";
        }
    }
    return 0;
}