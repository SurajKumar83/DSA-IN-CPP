#include <bits/stdc++.h>
using namespace std;
class solution{
    bool checkCycle(int node,vector<int>adj[],int vis[],int dfsVis[]){
        vis[node] = 1;
        dfsVis[node] =1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(checkCycle(it,adj,vis,dfsVis)){
                    return true;
                }
            }
            else if(dfsVis[it]){
                return true;
            }
        }
        dfsVis[node] =0;
        return false;
    }
    public:
    bool isCycle(int n,vector<int> adj[]){
        int vis[n],dfsVis[n];
        memset(vis,0,sizeof(vis));
        memset(dfsVis,0,sizeof(dfsVis));
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(checkCycle(i,adj,vis,dfsVis)){
                    return true;
                }
            }
        }
        return false;
    }
};
bool iscycle(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &stack)
{
   stack[node] = true;
   if(!visited[node]) {
      visited[node] = true;
      for(auto i:adj[node]) {
        if(!visited[i] and iscycle(i,adj,visited,stack)) {
            return true;
        }
        // if node is there in the stack then return true;
        if(stack[i]){
            return true;
        }
      }
   }
   stack[node] = false;
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
        
    }
    bool cycle = false;
    vector<int> stack(n, 0);
    vector<bool> visited(n,0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] and iscycle(i, adj, visited, stack))
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