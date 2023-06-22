#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,src;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];

    int a,b,wt;
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }

    cin>>src;
    // Dijkstra's algorithm begins here
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//min-heap:in pair={dis,node}
    vector<int> distTo(n+1,INT_MAX);// 1 indexed array for calculating shortest paths;

    distTo[src]=0;
    pq.push({0,src});//{dist,from}

    while(!pq.empty()){
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();

        
        for(auto it: adj[prev])
        {
            int next=it.first;
            int nextDist=it.second;
            if(distTo[next]>distTo[prev]+nextDist){
                 distTo[next] = distTo[prev]+nextDist;
                 pq.push({distTo[next],next});
            }
        }
    }
   cout<<"The distances from the source "<<src<<" are: "<<endl;
   for(int i=1;i<=n;i++){
    cout<<distTo[i]<<" ";
   }cout<<endl;

 return 0;
}