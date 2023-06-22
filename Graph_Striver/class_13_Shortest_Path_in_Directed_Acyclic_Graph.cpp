#include <bits/stdc++.h>
using namespace std;

void findtoposort(int node,int vis[],vector<pair<int,int>> adj[],stack<int>&st){
    vis[node] =1;
    for(auto it : adj[node]){
          if(!vis[it.first]){
            findtoposort(it.first,vis,adj,st);
          }
    }
    st.push(node);
}

void shortestPath(int src,int n,vector<pair<int,int>> adj[]){
    // Toposort using  DFS algorithm
    int vis[n]={0};
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            findtoposort(i,vis,adj,st);
        }
    }
    // now we calculate the distance.
    int dis[n];
    for(int i=0;i<n;i++){
        dis[i]=1e9;
    }
    dis[src]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();

           // if that node has been reached previously
        if(dis[node]!=1e9){
            for(auto it: adj[node]){
                if(dis[node]+it.second<dis[it.first]){
                    dis[it.first]=dis[node]+it.second;
                }
            }
        }
    }
    for(int i=0; i<=n;i++){
        (dis[i]==1e9)?cout<<"INF ":cout<<dis[i]<<" ";
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,wt;
        //u-->v
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        
    }
    
    shortestPath(0,n,adj);
    return 0;
}