#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<char>st;
    string s="((a+b)*((-d)))";
    //st.push();
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='(' )
            st.push(s[i]);
        else if(s[i]==')' ){
            if(st.empty())
                cout<<"Invalid parenthesis\n";
            st.pop();
        }
    }
    st.empty() ? cout<<"valid parenthesis" : cout<<"Invalid parenthesis";

}