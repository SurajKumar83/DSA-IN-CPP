#include <bits/stdc++.h>
using namespace std;


vector<pair<int, int>> BFS(vector<int> adj[], int src, vector<int> &vis,vector<int>&parent)
{

    vector<pair<int, int>> ans;

    // queue of the pair node and level from the source node
    queue<pair<int, int>> q;
    q.push({src, 0});
    
    vis[src] = 1;
    while (!q.empty())
    {
        int node = q.front().first;
        int level = q.front().second;
        ans.push_back({node, level});

        q.pop();
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                vis[it] = 1;
                parent[it]=node;
                q.push({it, level + 1});
            }
        }
    }
    return ans;
}

int main()
{
    int n, e;
    cout << "Enter the number of nodes ";
    cin >> n;
    cout << "Enter the number of edges ";
    cin >> e;
    cout << "Enter the nodes :" << endl;

    vector<vector<int>> v(e, vector<int>(2, 0));
    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<int> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        adj[v[i][0]].push_back(v[i][1]);
        adj[v[i][1]].push_back(v[i][0]);
    }
    cout << "The Adjacency List: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (auto it : adj[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
    // visited array
    vector<int> vis(n + 1, 0);
    vector<int> parent(n+1,-1);
    // BFS CALL
    vector<pair<int, int>> ans = BFS(adj, 1, vis,parent);
    vector<int>path[n+1];
    for(int i=0;i<ans.size();i++){
    
        int node=ans[i].first;
       vector<int>cur;
       while(node!=-1){
          cur.push_back(node);
          node=parent[node];
       }
       path[ans[i].first]=cur;
    }
    for(int i=0;i<ans.size();i++){
        cout<<"Node: "<<ans[i].first<<"  Dis: "<<ans[i].second<<" "<<"Path: ";
         for(auto it:path[ans[i].first]){
            cout<<it<<"->";
         }cout<<"-1"<<endl;
    }
    
    return 0;
}