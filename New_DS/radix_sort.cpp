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
    cout<<"Enter size of array\n";
    cin>>n;
    cout<<"Enter elements\n";
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector< int > c[10];
    int max=findMax(a,n);
    int rem;
    string s=to_string(max);
    int l=s.length()-1;
    int j=1;
    int power=pow(10,l);
    while (j<=power)
    {
        for(int i=0;i<n;i++){
            rem=(a[i]/j)%10;
            c[rem].push_back(a[i]);
        }
        int t=0,k=0;
        vector<int> :: iterator it;
        while (t<10)
        {   if(!c[t].empty())
            {    
                for(it=c[t].begin();it!=c[t].end();it++){
                    a[k]=*it;
                    k++;
                }
            }
        t++;
        }   
        j=j*10;
        
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    

}