#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<char> st;
    string s="[(])";
    int flag=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{' || s[i]=='(' || s[i]=='[')
            st.push(s[i]);
        else if(s[i]=='}' || s[i]==')' || s[i]==']')
        {
            int x=st.top();
            if((x=='[' && s[i]!=']') || (x=='{' && s[i]!='}') || (x=='(' && s[i]!=')'))
             {flag=1;   break;}
            else
                st.pop();
        }
    }
    if(flag==1)
        cout<<"Invalid Parenthesis\n";
    else
        cout<<"Valid Parenthesis\n";
}