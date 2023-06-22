#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
bool vis[N] = {0};
vector<int> adj[N];

class solution{
  void dfs(int node,vector<int> &vist,vector<int> adj[], vector<int> storeDfs){
    storeDfs.push_back(node);
    vist[node]=1;
    for(auto it:adj[node]){
      if(!vis[it]){
        dfs(it,vist,adj,storeDfs);
      }
    }
  }
  public:
    vector<int>dfsofGraph(int v,vector<int> adj[]){
        vector<int> storeDfs;
        vector<int> vist(v+1,0);
        for(int i=1;i<=v;i++){
            if(!vist[i]){
                dfs(i,vist,adj,storeDfs);
            }
        }
    }
};

void dfs(int node)
{
    // preorder
    vis[node] = 1;
    // cout << node << " ";
   
    // inorder
    vector<int>::iterator it;
    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (vis[*it])
            ;
        else
        {
            dfs(*it);
        }
    }
    //post-order traverse
   cout<<node<<" ";//4 5 6 3 7 2 1
}
   /*                  1                       
                     /   \                  
                    2 ---  3                   
                  / | \  \   \                 
                 4  5  6  -----7     */  
int main()
{
    int n, m;
    cin >> n >> m; // number of edges and node not respectivily

    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
    return 0;
}