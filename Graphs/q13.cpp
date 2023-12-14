// articulation points (these are the node if they were removed the will divide the graph into components)
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
    unordered_map<int, list<int> > adj;
    void addedge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
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
    void dfs(int node, int &parent, vector<int> &low, vector<int> &disc, int &timer, unordered_map<int, bool> &visited, vector<int> &ans)
    {
        visited[node] = true;
        low[node] = disc[node] = timer++;
        for (auto nbr : adj[node])
        {
            if (nbr == parent)
            {
                continue;
            }
            if (!visited[nbr])
            {
                dfs(nbr, node, low, disc, timer, visited, ans);
                low[node] = min(low[node], low[nbr]);
                if (low[nbr] >= disc[node] && parent != -1)
                {
                    ans.push_back(node);
                }
            }
            else
            {
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }
    vector<int> ap(int n)
    {
        vector<int> low(n);
        vector<int> disc(n);
        int parent = -1;
        for (int i = 0; i < n; i++)
        {
            low[i] = -1;
            disc[i] = -1;
        }
        int timer = 0;
        unordered_map<int, bool> visited;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, parent, low, disc, timer, visited, ans);
            }
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
        g.addedge(u, v);
    }
    g.printlist();
    vector<int> ans = g.ap(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}