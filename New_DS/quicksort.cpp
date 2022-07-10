#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int l,int h){
    int i=l,j=h;
    int pivot=a[l];
    while(i<j){
        do{
            i++;
        }while(a[i]<=pivot);
        while(a[j]>pivot){
            j--;
        }
        if(i<j)
            swap(a[i],a[j]);
    }
    swap(a[l],a[j]);
    return  j;
}
void quicksort(int a[],int l,int h){
    int j;
    if(l<h){
        j=partition(a,l,h);
        quicksort(a,0,j-1);
        quicksort(a,j+1,h);
    }
}
int main(){
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}