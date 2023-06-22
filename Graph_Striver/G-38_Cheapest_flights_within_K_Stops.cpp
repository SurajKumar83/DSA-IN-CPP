#include <bits/stdc++.h>
using namespace std;
int cheapestflight(int n, vector<vector<int>> &flight, int src, int dst, int k)
{

    vector<pair<int, int>> adj[n];
    for (auto it : flight)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }
    vector<int> dis(n, 1e9); // dis vector
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}}); // step,node,cost
    dis[src] = 0;

    while (!q.empty())
    {
        int curnode = q.front().second.first;
        int step = q.front().first;
        int cost = q.front().second.second;
        q.pop();
        if (step > k)
            continue;

        for (auto neigh : adj[curnode])
        {
            int node = neigh.first;
            int wt = neigh.second;

            if (cost + wt < dis[node] && step <= k)
            {
                dis[node] = cost + wt;
                q.push({step + 1, {node, cost + wt}});
            }
        }
    }
    return dis[dst] == 1e9 ? -1 : dis[dst];
}