#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cout << "Enter the number of Nodes: ";
    cin >> n;
    cout << "Enter the number of Edges: ";
    cin >> e;

    vector<vector<int>> edges;
    int u, v, wt;
    cout << "Enter the edges: " << endl;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
    vector<int> dis(n, INT_MAX);
   
    dis[0] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u1 = edges[j][0];
            int v1 = edges[j][1];
            int wt1 = edges[j][2];
            if (dis[u1] != INT_MAX && dis[u1] + wt1 < dis[v1])
            {
                dis[v1] = dis[u1] + wt1;
                
            }
        }
    }
    // for checking negative cycle
    for (int i = 0; i < e; i++)
    {
        int u1 = edges[i][0];
        int v1 = edges[i][1];
        int wt1 = edges[i][2];
        if (dis[u1] != INT_MAX && dis[v1] > dis[u1] + wt1)
        {
            cout << "Graph contains negative Cycle" << endl;
            break;
        }
    }
    cout << "The distance from 0: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Node : " << i << " distance " << dis[i] << endl;
    }
    cout << endl;
    return 0;
}