#include<bits/stdc++.h>
using namespace std;
void maxheapify(int a[],int n,int i){
    int largest=i;
    int left=2*i,right=2*i+1;
    while (left<=n && a[left]>a[largest])
    {
        largest=left;
    }
    while(right<=n && a[right]>a[largest])
    {
        largest=right;
    }
    if(largest!=i){
        swap(a[largest],a[i]);
        maxheapify(a,n,largest);
    }
}
void heapsort(int a[],int n)
{   
    for(int i=n/2;i>=1;i--)
        maxheapify(a,n,i);
    for(int i=n;i>=1;i--)
        {   swap(a[1],a[i]);
            maxheapify(a,i-1,1);
        }
}
int main(){
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    heapsort(a,n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
}