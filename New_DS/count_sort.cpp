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
    int n;
    cout<<"Enter number of elements\n";
    cin>>n;
    cout<<"Enter elements\n";
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int max=findMax(a,n);
    int c[max+1];
    for(int i=0;i<max+1;i++)
        c[i]=0;
    for(int i=0;i<n;i++)
        c[a[i]]++;
    int i=0,j=0;
    while(i<max+1){
        if(c[i]>0){
            a[j]=i;
            j++;
            c[i]--;
        }
        else 
            i++;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

}