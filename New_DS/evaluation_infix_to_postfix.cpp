#include<bits/stdc++.h>
using namespace std;
int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ){
        return 0;
    }
    return 1;
}
int main(){
    string postfix="35*62/+4-";
    int r;
    stack<int>st;
    for(int i=0;i<postfix.length();i++){
        if(isOperand(postfix[i])){
           st.push((postfix[i])-'0');
        }
        else{
            int x2=st.top();
            st.pop();
            int x1=st.top();
            st.pop();
            switch (postfix[i])
            {
            case '+': r=x1+x2; st.push(r); 
                    break;
            case '-' : r=x1-x2; st.push(r); 
                    break;
            case '*' : r=x1*x2; st.push(r);
                    break;
            case '/' : r=x1/x2; st.push(r);
                    break;
            }
        }
    }
    cout<<st.top();
    st.pop();
}