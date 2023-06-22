#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int node, edge;
    vector<vector<int>>edges;
public:
    Graph(int n, int e)
    {
        node = n;
        edge = e;
    }
    // To take Edges
    void makeEdges(int u,int v)
    {
        edges.push_back({u,v});
    }
};
int main()
{
    int n;
    cout << "Enter the Number of vertices: ";
    cin >> n;
    int e;
    cout << "Enter the Number of Edges: ";
    cin >> e;
    vector<vector<int>> edges(e, vector<int>(2, 0));
    for(int i=0;i<e;i++){
        for(int j=0;j<2;j++){
            cin>>edges[i][j];
        }
    }
    vector<int> adj[n + 1];
    vector<int> indegre(n + 1, 0);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        indegre[it[1]]++;
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

    queue<int> q;
    for (int i = 1; i < n; i++)
    {
        if (indegre[i] == 0)
        {
            q.push(i);
        }
    }
    cout << "The Topological Ordering: " << endl;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto it : adj[node])
        {
            indegre[it]--;
            if (indegre[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return 0;
}