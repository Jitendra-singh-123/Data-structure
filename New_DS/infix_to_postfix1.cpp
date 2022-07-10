#include<bits/stdc++.h>
using namespace std;
int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}
int outPrecedence(char c){
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 3;
    else if(c=='^')
        return 6;
    else if(c=='(')
        return 7;
    else if(c==')')
        return 0;
    return -1;
}

int inPrecedence(char c){
    if(c=='+' || c=='-')
        return 2;
    else if(c=='*' || c=='/')
        return 4;
    else if(c=='^')
        return 5;
    else if(c=='(')
        return 0;
    return -1;
}

int main(){
    string infix="a+b*(c^d-e)^(f+g*h)-i";
    string postfix="";
    int i=0;
    stack<char> st;
    while (i<infix.length())
    {
        if(isOperand(infix[i]))
        {
            postfix+=infix[i];
            i++;
        } 
        else{
            if(st.empty() || inPrecedence(st.top())<outPrecedence(infix[i]) )
            {
                st.push(infix[i]);
                i++;
            }
            else if(outPrecedence(infix[i])==inPrecedence(st.top())){
                st.pop(); i++;
            }
            else{
                postfix+=st.top();
                st.pop();
            }
        }

    }
    while (!st.empty() && st.top() != ')')
    {
        postfix+=st.top();
        st.pop();
    }
    cout<<postfix;

}