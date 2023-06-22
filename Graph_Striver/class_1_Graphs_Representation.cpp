#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
const int N=1e5+2;
vi adj[N];
int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjm(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }
    cout << "adjacency matrix of above graph is given by:" << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    }
    if (adjm[7][3] == 1)
    {
        cout << "Yes there is edge between 3 and 7" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    cin>>n>>m;

    for(int i=0;i<m; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"Adjacent list of the above graph is given by"<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<"->";
        vector<int> :: iterator it;
        for(it=adj[i].begin();it!=adj[i].end();it++){
            cout<<*it<<" ";
        }cout<<endl;
    }cout<<endl;

    cout<<"In case of weighted Graph"<<endl;
    cin>>n>>m;
    vector<pair<int,int>> adjwt[n+1];
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adjwt[u].push_back({v,wt});
        adjwt[v].push_back({u,wt});
    }
    for(int i=0;i<=n;i++){
       cout<<i<<"->";
       for(auto it: adjwt[i]){
        cout<<"("<<it.first<<" , "<<it.second<<") ";
       }cout<<endl;
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define vi vector<int>
// const int N = 1e5 + 2;
// vi adj[N];
// int main()
// {

//     int n;
//     cin>>n;
//     vector<int> v[n];
//     for (int i = 0; i < n; i++)
//     {
//          v[1].push_back(i);
//          v[0].push_back(i+1);
//         i++;
//     }
//     for(int i=0;i<=1;i++){
//         cout<<i<<"-> ";
//         vector<int>:: iterator it;
//         for(it=v[i].begin();it!=v[i].end();it++){
//             cout<<*it<<" ";
//         }cout<<endl;
//     }
//     return 0;
// }
