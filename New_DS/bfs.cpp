#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter number of vertices and edges\n";
    int n,m,u,v;
    cin>>n>>m;
    bool visited[100];
    for(int i=1;i<=n;i++)
        visited[i]=false;
    vector<int> adj[100];
    cout<<"Enter edges u and v\n";
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    queue<int> q;
    q.push(1);
    visited[1]=true;
    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        vector<int> :: iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++)
        {
            if(!visited[*it])
            {
                visited[*it]=true;
                q.push(*it);
            }
        }
    }
    
}