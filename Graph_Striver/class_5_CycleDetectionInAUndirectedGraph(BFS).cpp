#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    bool checkforCycle(int s,vector<int> adj[],vector<int> & visited){
        queue<pair<int,int> > q;// this would store the parent and its adjacent nodes
        visited[s]=true;
        q.push({s,-1});
         while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it: adj[node]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push({it,node});
                }
                else if(parent!=it){
                    return true;
                }
            }
         }
         return false;
    }
    bool isCycle(int v,vector<int> adj[]){
        vector<int> vis(v+1,0);
        for(int i=1;i<=v;i++){
            if(!vis[i]){
              if(checkforCycle(i,adj,vis)) return true;
            }
        }
        return false;
    }
};


bool iscycle(int src, vector<vector<int>> &adj, vector<bool> &visited, int parent)
{
    visited[src] = true;
    for (auto i : adj[src])
    {
        if (i != parent)
        {
            if (visited[i])
            {
                return true;
            }
            if (!visited[i] and iscycle(i, adj, visited, src))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{

    int n, m;
    cin >> n >> m;              // number of nodes and edges
    vector<vector<int>> adj(n); // adjacency list
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycle = false;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] and iscycle(i, adj, visited, -1))
        {
            cycle = true;
        }
    }
    if (cycle)
    {
        cout << "Cycle is present in the given graph" << endl;
    }
    else
    {
        cout << "Cycle is not present in the given graph" << endl;
    }
}