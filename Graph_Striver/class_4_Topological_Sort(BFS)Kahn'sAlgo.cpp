//TC O(N+E)
//SC O(N)+O(N)

#include <bits/stdc++.h>
using namespace std;
class solution{
 public:
 vector<int> toposort(int n,vector<int> adj[])
 {
    queue<int>q;
    vector<int> indeg(n,0);
    for(int i=0;i<n;i++){
        for(auto it: adj[i]){
            indeg[it]++;
        }
    }
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node]){
            if(indeg[node]==0){
                q.push(node);
            }
        }
    }
    return ans;
 }
};


int main()
{
    int n,m;cin>>n>>m;
    int cnt=0;
    vector<vector<int> > adj_list(n);
    vector<int> indeg(n,0);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        // u-->v;
        adj_list[u].push_back(v);
        indeg[v]++;
    }
    for(int i=0;i<n;i++){
         cout<<i<<"->";
         for(auto it:adj_list[i]){
            cout<<it<<" ";
         }cout<<endl;
    }
    queue<int> pq;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        cnt++;
        int x=pq.front();
        pq.pop();
        cout<<x<<" ";
        for(auto it:adj_list[x]){
            indeg[it]--;
            if(indeg[it]==0){
                pq.push(it);
            }
        }
    }
    return 0;
}