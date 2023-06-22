#include <bits/stdc++.h>
using namespace std;
struct edges
{
    int dist, u, v;
};
class Compare
{
public:
    bool operator()(edges a, edges b)
    {
        return a.dist > b.dist;
    }
};
int main()
{
    int n, e;
    cout << "Enter the Nodes and edges : ";
    cin >> n >> e;
    cout << "Enter the edges and weights : " << endl;
    int u, v, wt;
    vector<pair<int, int>> adj[n + 1];
    priority_queue<edges, vector<edges>, Compare> pq;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> wt;
        pq.push({wt, u, v});
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> components(n + 1);
    for (int i = 1; i <= n; i++)
    {
        components[i] = i;
    }
    int minimumCost = 0;
    int cnt = 0;
    while (cnt < n - 1)
    {
        auto it = pq.top();
        int u1 = it.u;
        int v1 = it.v;
        pq.pop();
        if (components[u1] != components[v1])
        {
            cnt++;
            minimumCost += it.dist;
            for (int i = 1; i <= n; i++)
            {
                if (components[i] == components[v1])
                {
                    components[i] = components[u1];
                }
            }
        }
    }
    cout << endl;

    cout << "The minimum cost: " << minimumCost << endl;
}