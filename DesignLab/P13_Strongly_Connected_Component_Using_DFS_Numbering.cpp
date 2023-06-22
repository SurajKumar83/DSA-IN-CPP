#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &pre, vector<int> &post, vector<int> &vis, int &cnt)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            pre[it] = cnt;
            cnt++;
            dfs(it, adj, pre, post, vis, cnt);
        }
    }
    post[node] = cnt;
    cnt++;
    return;
}
void dfscc(int node,vector<int>revadj[],vector<int>&cur,vector<int>&vis){
    vis[node]=1;
    cur.push_back(node);
    for(auto it:revadj[node]){
        if(vis[it]==0){
            dfscc(it,revadj,cur,vis);
        }
    }
}
int main()
{
    int n;
    cout << "Enter the Number of vertices: ";
    cin >> n;
    int e;
    cout << "Enter the Number of Edges: ";
    cin >> e;
    vector<vector<int>> edges(e, vector<int>(2, 0));
    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> edges[i][j];
        }
    }

    vector<int> adj[n];
    vector<int>revadj[n];
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        revadj[edges[i][1]].push_back(edges[i][0]);
    }
    cout << "The Adjacency List: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (auto it : adj[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<int> pre(n, 0);
    vector<int> post(n, 0);
    vector<int> vis(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            pre[i] = cnt;
            cnt++;
            dfs(i, adj, pre, post, vis, cnt);
        }
    }
    cout << "Pre and Post of each node: " << endl;
    cout << "Node: "
         << "Pre "
         << "Post" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "     " << pre[i] << "    " << post[i] << endl;
    }
    vector<pair<int, int> >vpost;
    for(int i=0;i<n;i++){
        vpost.push_back({post[i],i});
    }
    sort(vpost.begin(),vpost.end(),greater<pair<int,int>>());
    
    cout << "The Rev Adjacency List: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (auto it : revadj[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
    vector<int>revvis(n,0);
    vector<vector<int>>ans;
   
    for(auto it:vpost){
        int node=it.second;
        
        vector<int>scc;
        if(revvis[node]==0){
           dfscc(node,revadj,scc,revvis);
        }
        
        ans.push_back(scc);
    }
   cout<<"The SCC Components are: "<<endl;
    for(auto it:ans){
        for(auto node:it){
            cout<<node<<" ";
        }cout<<endl;
    }
    return 0;
}