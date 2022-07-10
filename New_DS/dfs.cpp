#include<bits/stdc++.h>
using namespace std;
bool visited[100];
vector<int>adj[100];
void dfs(int u){
    if(visited[u]==false){
        cout<<u<<" ";
        visited[u]=true;
        vector<int> :: iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
            if(!visited[*it])
                dfs(*it);
        }
    }
}
int main(){
    cout<<"Enter number of vertices and edges\n";
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
        visited[i]=false;
    cout<<"Enter edges u and v\n";
    int u,v;
    
 
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
}