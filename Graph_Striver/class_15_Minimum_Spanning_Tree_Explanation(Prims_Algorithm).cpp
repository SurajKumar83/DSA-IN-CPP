// If we can draw the tree using  graph where
// 1. Number of nodes are the same(N) but the number of edges are (N-1)
// 2. Weight of the tree is minimum.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }
    int parent[n];
    int key[n];
    bool mstSet[n];
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;
    }

    // Brute force approach for Prims algorithm  T=O(N*N) AND S=O(N)

    // key[0]=0;
    // parent[0]=-1;
    // for(int count =0;count<n-1;count++){
    //     int mini=INT_MAX,u;//mini store the minimum value while the u for its index

    //     for(int v=0;v<n;v++){
    //         if(mstSet[v]==false && key[v]<mini){
    //             mini=key[v],u=v;
    //         }
    //     }

    //     mstSet[u]=true;// once you stored the mini and its index now traverse its adjacent nodes;
    //     for(auto it :adj[u]){
    //         int v=it.first;
    //         int weight=it.second;
    //         if(mstSet[v]==false && weight<key[v]){
    //             parent[v]=u,key[v]=weight;
    //         }
    //     }
    // }

    //    Optimal Approach for prims Algorithm T=O(N+E+NlogN)
    //    USE THE PRIORITY QUEUE

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});
    for (int count = 0; count < n - 1; count++)
    {
        int u = pq.top().second; // minimum weight element
        pq.pop();

        mstSet[u] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }
    return 0;
}
