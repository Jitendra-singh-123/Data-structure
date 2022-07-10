#include<bits/stdc++.h>
using namespace std;

int isOperand(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return 0;
    else 
        return 1;
    return -1;
}

int prec(char c){
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    return 0;
}




int main(){
    stack<char>st;
    st.push(' ');
    string infix="a+b*c-d/e";
    string postfix="";
    int i=0;
    while (i<infix.length())
    {
        if(isOperand(infix[i]))
        {   postfix+=infix[i++]; }
        else{
            if(prec(infix[i])>prec(st.top()))
            {    st.push(infix[i++]);   }
            else{
                postfix+=st.top();;
                st.pop();
            }
        }
    }
    while(!st.empty()){
        postfix+=st.top();
        st.pop();
    }
    cout<<postfix;
}