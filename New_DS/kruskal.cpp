#include<bits/stdc++.h>
using namespace std;
int find(int u,int *parent){
    if(parent[u]<0) return u;
    return find(parent[u],parent);
}
void unionbyweight(int s1,int d1,int *parent){
    int pu=find(s1,parent),pv=find(d1,parent);
    if(pu!=pv){
        if(parent[pu]<parent[pv]){
            parent[pu]+=parent[pv];
            parent[pv]=pu;
        }
        else{
            parent[pv]+=parent[pu];
            parent[pu]=pv;
        }
    }
}
int main(){
    vector<pair<int,pair<int,int>>> kruskal;
    cout<<"Enter number of vertices and edges\n";
    int n,m;
    cin>>n>>m;
    cout<<"Enter weight, source, destination\n";
    int s,d,w;
    for(int i=0;i<m;i++){
        cin>>w>>s>>d;
        kruskal.push_back(make_pair(w,make_pair(s,d)));
    }
    sort(kruskal.begin(),kruskal.end());
    int cost=0;
    int parent[10];
    for(int i=0;i<n;i++)
        parent[i]=-1;
    int w1,s1,d1;
    for(auto i: kruskal){
        w1=i.first;
        s1=i.second.first;
        d1=i.second.second;
        if(find(s1,parent)==find(d1,parent))
            continue;
        else{
            cout<<"\n"<<s1<<"->"<<d1<<endl;
            unionbyweight(s1,d1,parent);
            cost+=w1;
        }
    }
    cout<<"Minimum weight: "<<cost;
}