#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
bool vis[N]={0} ;       // this is going to store the visited array initialized with zero
vector<int> adj[N]; // store the adjacency list

class solution{
    public:

    vector<int>bfsOfGraph(int n,vector<int> adj[]){
        vector<int> bfs;//to store the traversal
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);
                    for(auto it:adj[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it]=1;
                        }
                    }
                }
            }
        }
        return bfs;
    }
};
int main()
{
    
    // we define two variables n,m for number of nodes and edges
    int n, m;
    cin >> n >> m;
    // now we define two variables x and y for the edges input
    int x, y;
    // to insert the edges
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=m;i++){
        cout<<i<<"->";
        vector<int>:: iterator it;
        for(it=adj[i].begin();it!=adj[i].end();it++){
            cout<<*it<<" ";
        }cout<<endl;
    }

                   /*   1                       
                     /   \                  
                    2 ---  6                   
                  / | \  \   \                 
                 4  5  3  -----7     */          
                                             
                                             
                                                 
    // we use queue to keep track of visited nodes
    queue<int> q;
    q.push(1);
    //as we start from the first node i.e., 1 so we push it into the queue and mark it as visited in visited array by setting it's index value to true;
    vis[1] = true;
    // now we traverse the queue untill it gets empty
    while (!q.empty())
    {
        // now we make the front of the queue as node then we pop it from its queue
        int node = q.front();
        q.pop();
        // now we print the node 
        cout << node << endl;
        // now we move to each of the edges of the node and check if it is visited or not so we take help of iterator of the vector 
        vector<int>::iterator it;
        for(it=adj[node].begin(); it!=adj[node].end();it++) {
            if(!vis[*it]){
                vis[*it] =1;
                q.push(*it);
            }
        }
    }
    return 0;
}

