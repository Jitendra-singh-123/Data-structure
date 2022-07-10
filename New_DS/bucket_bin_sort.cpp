#include<bits/stdc++.h>
using namespace std;
int findMax(int a[],int n){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max)
            max=a[i];
    }
    return max;
}

int main(){
    int n,x;
    cout<<"Enter size of array\n";
    cin>>n;
    int a[n];
    cout<<"Enter elements\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    int max=findMax(a,n);
    vector<int> c[max+1];
    for(int i=0;i<n;i++)
     {   
         x=a[i];
         c[x].push_back(x);
     }
    vector<int> :: iterator it;
    int i=0,j=0;
    while (i<max+1)
    {   if(!c[i].empty())
        {    for(it=c[i].begin();it!=c[i].end();it++){
                a[j]=*it;
                j++;
            }
        }
        i++;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    
}