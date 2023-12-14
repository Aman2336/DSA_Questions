//minimum spanning tree (prim's algo)
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
    unordered_map<int, list<pair<int, int> > > adj;
    void addedge(int u, int v, int w, bool flag)
    {
        adj[u].push_back(make_pair(v, w));
        if (flag == 0)
        {
            adj[v].push_back(make_pair(u, w));
        }
    }
    void printlist()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "[" << j.first << "," << j.second << "]"
                     << ",";
            }
            cout << endl;
        }
    }
    vector<pair<pair<int, int>, int> > primsalgo(int n)
    {
        vector<int> key(n + 1);
        vector<bool> mst(n + 1);
        vector<int> parent(n + 1);

        for (int i = 0; i <= n; i++)
        {
            key[i] = INT_MAX;
            parent[i] = -1;
            mst[i] = false;
        }

        key[1] = 0;
        parent[1] = -1;

        for (int i = 1; i < n; i++)
        {
            int mini = INT_MAX;
            int u;
            // finding min node
            for (int j = 1; j <= n; j++)
            {
                if (mst[j] == false && key[j] < mini)
                {
                    u = j;
                    mini = key[j];
                }
            }
            // marking that min node true
            mst[u] = true;

            // checking min node's child nodes and updating their key values i.e weights
            for (auto k : adj[u])
            {
                int v = k.first;
                int w = k.second;
                if (mst[v] == false && key[v] > w)
                {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }
        vector<pair<pair<int, int>, int> > ans;

        for (int i = 2; i <= n; i++)
        {
            ans.push_back(make_pair(make_pair(parent[i], i), key[i]));
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
        int u, v, w;
        cin >> u >> v >> w;
        g.addedge(u, v, w, 0);
    }
    g.printlist();

     vector<pair<pair<int, int>, int> > ans = g.primsalgo(n);

     for(int i = 0;i<ans.size();i++){
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
     }
    return 0;
}