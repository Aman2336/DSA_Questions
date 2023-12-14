// bridges in graphc(removing an edge will divide the graph into 2 or more components)
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
    void dfs(int node, int &parent,vector<int> &low, vector<int> &disc, unordered_map<int, bool> &visited, int timer, vector<vector<int> > &result)
    {

        low[node] = disc[node] = timer++;
        
        visited[node] = true;
        for (auto nbr : adj[node])
        {
            if (nbr == parent)
            {
                continue;
            }
            if (!visited[nbr])
            {
                dfs(nbr, node, low, disc, visited, timer, result);
                low[node] = min(low[nbr], low[node]);
                if (low[nbr] > disc[node])
                {
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(nbr);
                    result.push_back(ans);
                }
            }
            else
            {
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }
    vector<vector<int> > findbridges(int n)
    {
        vector<vector<int> > result;
        vector<int> low(n);
        vector<int> disc(n);
        int parent =-1;
        for (int i = 0; i < n; i++)
        {
            low[i] = -1;
            disc[i] = -1;
        }
        unordered_map<int, bool> visited;
        int timer = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, parent, low, disc, visited, timer, result);
            }
        }
        return result;
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
    vector<vector<int> > ans = g.findbridges(n);
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
