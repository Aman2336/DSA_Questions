// shortes path in directed acyclic graph(weighted)
#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
#include <limits>
#include <stack>
using namespace std;
class graph
{
public:
    unordered_map<int, list<pair<int, int> > > adj;
    void addedge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
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
                if (!visited[i.first])
                {
                    q.push(i.first);
                    visited[i.first] = 1;
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
    stack<int> tsort(int n)
    {
        stack<int> ans;
        vector<int> indegree(n);
        for (auto i : adj)
        {
            for (auto j : i.second)
            {
                indegree[j.first]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            ans.push(front);

            for (auto i : adj[front])
            {
                indegree[i.first]--;
                if (indegree[i.first] == 0)
                {
                    q.push(i.first);
                }
            }
        }
        return ans;
    }
    void allshortespath(int s, int n, vector<int> &ans)
    {

        // src
        ans[s] = 0;

        stack<int> topsort = tsort(n);

        stack<int> st;

        while(!topsort.empty()){
            int top = topsort.top();
            st.push(top);
            topsort.pop();
            
        }
        while (!st.empty())
        {
            int top = st.top();
            st.pop();

            if (ans[top] != INT64_MAX)
            {
                for (auto i : adj[top])
                {
                    if (ans[top] + i.second < ans[i.first])
                    {
                        ans[i.first] = ans[top] + i.second;
                    }
                }
            }
        }
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
        g.addedge(u, v, w);
    }
    g.printlist();

// stack<int> sort = g.tsort(n);
// while(!sort.empty()){
//     cout<<sort.top()<<" ";
//     sort.pop();
// }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = INT64_MAX;
    }

    g.allshortespath(0, n, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] <<" ";
    }
}