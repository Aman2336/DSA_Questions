// shortes path in an undirected graph
#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
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
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
    vector<int> bfs(int n)
    {
        vector<int> ans;
        unordered_map<int, bool> visited;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                solve(i, ans, visited);
            }
        }
        return ans;
    }
    // void func(int node, unordered_map<int, bool> &visited, unordered_map<int, int> &parent)
    // {
    //     queue<int> q;
    //     q.push(node);
    //     visited[node] = 1;
    //     parent[node] = -1;

    //     while (!q.empty())
    //     {
    //         int front = q.front();
    //         q.pop();

    //         for (auto i : adj[front])
    //         {
    //             if (!visited[i])
    //             {
    //                 q.push(i);
    //                 visited[i] = 1;
    //                 parent[i] = front;
    //             }
    //         }
    //     }
    // }
    vector<int> shortestpath(int src, int dest, int n)
    {
        vector<int> ans;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // setting parent array
        queue<int> q;
        q.push(src);
        visited[src] = 1;
        parent[src] = -1;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto i : adj[front])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                    parent[i] = front;
                }
            }
        }

        int currentnode = dest;
        ans.push_back(dest);
        while (currentnode != src)
        {
            currentnode = parent[currentnode];
            ans.push_back(currentnode);
        }
        return ans;
    }
};
int main()
{
    graph g;
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, 0);
    }
    g.printlist();

    // vector<int> ans = g.bfs(n);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    cout << "for shortest path enter source and destination : " << endl;
    int s, d;
    cin >> s >> d;

    vector<int> ans = g.shortestpath(s, d, n);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
}