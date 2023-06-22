#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &pre, vector<int> &post, vector<int> &vis, int &cnt)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            pre[it] = cnt;
            cnt++;
            dfs(it, adj, pre, post, vis, cnt);
        }
    }
    post[node] = cnt;
    cnt++;
    return;
}
int main()
{
    int n;
    cout << "Enter the Number of vertices: ";
    cin >> n;
    int e;
    cout << "Enter the Number of Edges: ";
    cin >> e;
    vector<vector<int>> edges(e, vector<int>(2, 0));
    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> edges[i][j];
        }
    }

    vector<int> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    cout << "The Adjacency List: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (auto it : adj[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<int> pre(n + 1, 0);
    vector<int> post(n + 1, 0);
    vector<int> vis(n + 1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            pre[i] = cnt;
            cnt++;
            dfs(i, adj, pre, post, vis, cnt);
        }
    }
    cout << "Pre and Post of each node: " << endl;
    cout << "Node: "
         << "Pre "
         << "Post" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << "     " << pre[i] << "    " << post[i] << endl;
    }
    // check back edge using (pre[j],post[j]) contain (pre[i],post[i])
    int flag = 0;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        if (pre[v] < pre[u] && post[u] < post[v])
        {
            cout << "The first occurence of back edges between nodes " << u << " " << v << endl;
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        cout << "Yes, there is Cycle in the graph " << endl;
    }
    else
        cout << "No, there is no Cycle in the graph " << endl;
}