#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    bool cycleDFS(int node, int parent, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                if (cycleDFS(it, node, vis, adj))
                    return true;
            }
            else if (it != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int v, vector<int> adj[])
    {
        vector<int> vis(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (vis[i] == 0)
            {
                if (cycleDFS(i, -1, vis, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    solution s;
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < v + 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool found = s.isCycle(v, adj);
    if (found)
        cout << "1" << endl;
    else
        cout << "0" << endl;
}