 #include<bits/stdc++.h>
 using namespace std;
 struct node{
    int u;
    int v;
    int wt;
    node(int first,int second,int weight){
        u=first;v=second;wt=weight;
    }
 };
 bool comp(node a, node b){
    return a.wt<b.wt;
 }

 int findParent(int u,vector<int> &parent){
    if(u==parent[u]) return u;
    return findParent(parent[u],parent);
 }
 
 void unionn(int u,int v,vector<int> &parent,vector<int> &rank){
    u=findParent(u,parent);
    v=findParent(v,parent);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
 }
 int main(){
    int n,m;
    cin>>n>>m;
    vector<node> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
    sort(edges.begin(), edges.end(),comp);
    vector<int> parent(n);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    vector<int> rank(n,0);
    int cost=0;
    vector<pair<int,int>> mst;
    for(auto it: edges)
    {
        if(findParent(it.v,parent)!=findParent(it.u,parent)){
            cost+=it.wt;
            mst.push_back({it.u,it.v});
            unionn(it.u,it.v,parent,rank);
        }
    }
    return 0;
 }