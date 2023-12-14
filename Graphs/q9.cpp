// dijkstra algo
#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
#include <limits>
#include <stack>
#include <set>
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
    vector<int> dijkstra(int n, int src)
    {
        vector<int> dist(n);
        for (int i = 0; i < n; i++)
        {
            dist[i] = INT_MAX;
        }
        
        set<pair<int, int> > st;
        dist[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {

            // fetch auto record
            auto top = *(st.begin());
            int nodedistance = top.first;
            int topnode = top.second;

            // erase auto record
            st.erase(st.begin());

            for (auto i : adj[topnode])
            {
                if (nodedistance + i.second < dist[i.first])
                {
                    auto record = st.find(make_pair(dist[i.first], i.first));
                    if (record != st.end())
                    {
                        st.erase(record);
                    }
                    dist[i.first] = nodedistance + i.second;
                    st.insert(make_pair(dist[i.first], i.first));
                }
            }
        }
        return dist;
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
    vector<int> ans = g.dijkstra(n,0);
    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}