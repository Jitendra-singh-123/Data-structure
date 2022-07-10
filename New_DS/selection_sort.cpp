#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cout<<"Enter number of elements\n";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    //selection sort 
    for(int i=0;i<n;i++){
        for(int j=k=i;j<n;j++){
            if(a[j]<a[k])
                k=j;
        }
        swap(a[i],a[k]);
    }

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

}