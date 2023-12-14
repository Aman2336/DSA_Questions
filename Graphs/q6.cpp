// cycle detection using BFS
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
    bool tsort(int n)
    {
        queue<int> q;
        vector<int> indegree(n);
        for (auto i : adj)
        {
            for (auto j : i.second)
            {
                indegree[j]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int cnt = 0;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            cnt++;

            for (auto i : adj[front])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        if(cnt == n){
            return false;
        }
        else{
            return true;
        }
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
    if (g.tsort(n))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}