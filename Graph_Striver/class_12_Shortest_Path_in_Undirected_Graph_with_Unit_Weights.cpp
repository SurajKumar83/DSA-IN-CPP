//TC O(N+E)
// SC O(N)+O(N)
#include "bits/stdc++.h"
using namespace std;
void BFS(vector<int> adj[],int n,int src){
    int dis[n];
    for(int i=0;i<n;i++){
        dis[i]=INT_MAX;// mark all node to infinite
    }
    
    queue<int> q;
    dis[src]=0;
    // as we take the node into consideration we push it into the queue
    q.push(src);

    while(q.empty()==false){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(dis[node]+1<dis[it]){
                dis[it]=dis[node]+1;
                q.push(it);
            }
        }
    }
    for(int i=0; i<n;i++){
        cout<<dis[i]<<" ";
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(adj,n,0);
    return 0;
}