#include<bits/stdc++.h>
using namespace std;
 int parent[100000];
 int Rank[100000];
void makeSet(){
    for(int i=0;i<=100000;i++){
          parent[i]=i;
          Rank[i]=0;
    }
}

int findparent(int node){
    if(node==parent[node]) return node;
    // path comression
    return parent[node]= findparent(parent[node]);
}

void Union(int u,int v){
     u =findparent(u);
     v=findparent(v);
     if(Rank[u]<Rank[v]){
        parent[u]=v;
     }
     else if(Rank[u]>Rank[v]){
        parent[v]=u;
     }
     else{
        parent[v]=u;
        Rank[u]++;// level will increase
     }
}
int main(){
    makeSet();
    int m;
    cin>>m;
    int u,v;
    while(m--){
        
        cin>>u>>v;
        Union(u,v);
    }
    // to check their parents
    int p,q;cin>>p>>q;
    if(findparent(p)==findparent(q)){
       cout<<"Yes all are in same Component"<<endl;
    }
    else{
        cout<<"No all are in same Component"<<endl;
    }
    return 0;
}