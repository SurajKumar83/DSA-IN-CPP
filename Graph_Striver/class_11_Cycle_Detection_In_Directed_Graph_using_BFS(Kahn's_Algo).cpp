#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCyclic(int n, vector<int> adj[])
    {
        queue<int> q;
        vector<int> indeg(n,0);
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                indeg[it]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt=0;
        
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            
            for (auto it : adj[node])
            {
                indeg[it]--;
                if (indeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if(cnt==n)return false;
        return true;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    Solution sol;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <n; i++)
    {
        cout<<i<<"->";
         for(auto it:adj[i]){
            cout<<it<<" ";
         }cout<<endl;

    }

     cout<<sol.isCyclic(n,adj)<<endl;
    return 0;
} 