#include <bits/stdc++.h>
using namespace std;

bool Cycle_Check(int src, vector<int> &vis, vector<int> &par, vector<int> adj[])
{
    queue<int> q;
    vis[src] = 1;

    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                vis[it] = 1;
                par[it] = node;

                q.push(it);
            }
            else if (par[node] != it)
            {
                return true;
            }
        }
    }
    return false;
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
    vector<int> par(n + 1, -1);
    bool flag=false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if(Cycle_Check(i,vis,par,adj)){
               flag=true;
               break;
            }
        }
    }
    if(flag){
        cout<<"There is cycle in the graph. "<<endl;
    }
    else {
        cout<<"There is no cycle in the graph. "<<endl;
    }
    return 0;
}