// topological sort
//(kahn's algo)
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
    vector<int> tsort(int n)
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

        for(int i = 0 ;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for(auto i : adj[front]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
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