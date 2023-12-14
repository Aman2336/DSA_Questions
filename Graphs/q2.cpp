// cycle detetction using bfs
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class graph
{
public:
    unordered_map<int, list<int> > adj;
    void addedge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
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
    void solve(int node, vector<int> &ans, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto i : adj[front])
            {
                if (!visited[i])
                {
                    solve(i, ans, visited);
                }
            }
        }
    }
    vector<int> bfs(int n)
    {
        vector<int> ans;
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                solve(i, ans, visited);
            }
        }
        return ans;
    }
    bool solve1(int node, unordered_map<int, bool> &visited)
    {
        unordered_map<int, int> parent;
        parent[node] = -1;
        visited[node] = 1;

        queue<int> q;
        q.push(node);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto i : adj[front])
            {
                if (visited[i] == true && parent[front] != i)
                {
                    return true;
                }
                else if (!visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                    parent[i] = front;
                }
            }
        }
        return false;
    }
    bool iscycle(int n)
    {
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            //component ke liye
            if (!visited[i])
            {
                bool ans = solve1(i, visited);
                if (ans == 1)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, 0);
    }
    g.printlist();
    vector<int> ans = g.bfs(n);
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    if (g.iscycle(n))
    {
        cout << "yes";
    }
    else
    {
        cout << "false";
    }
    return 0;
}