#include<bits/stdc++.h>
using namespace std;
class Solution{
     void findtoposort(int node,vector<int>&vis,stack<int> &st,vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                findtoposort(it,vis,st,adj);
            }
        }
        st.push(node);

     }
     public:
     vector<int> toposort(int n,vector<int> adj[]){
        stack<int> st;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                findtoposort(i,vis,st,adj);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
     }
};
int main()
{
    Solution solution;
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> v=solution.toposort(n,adj);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}