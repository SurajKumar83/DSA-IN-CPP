#include <bits/stdc++.h>
using namespace std;

void connected_comp(int src, vector<int> &vis, vector<int> adj[], vector<int> &cur)
{
    queue<int> q;
    vis[src] = 1;
    cur.push_back(src);
    for(auto it:adj[src]){
        if(vis[it]==0){
            connected_comp(it,vis,adj,cur);
        }
    }
    
}
int main()
{
    int n, e;
    cout << "Enter the number of nodes ";
    cin >> n;
    cout << "Enter the number of edges ";
    cin >> e;
    cout << "Enter the nodes :" << endl;

    vector<vector<int>> v(e, vector<int>(2, 0));
    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<int> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        adj[v[i][0]].push_back(v[i][1]);
        adj[v[i][1]].push_back(v[i][0]);
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
    vector<int> vis(n + 1, 0);
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
    {
        vector<int> cur;
        if (vis[i] == 0)
        {
            connected_comp(i, vis, adj, cur);
        }
        ans.push_back(cur);
        
    }
    cout << "Components " << endl;
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }cout<<endl;
    }
    return 0;
}