#include<bits/stdc++.h>
using namespace std;
struct node{
    struct node* left;
    int data;
    struct node* right;
};
void preorder(struct node *p){
    if(p){
        cout<<p->data<<endl;
        preorder(p->left);
        preorder(p->right);
    }
}
int count(struct node* p){
    if(p){
        int x=count(p->left);
        int y=count(p->right);
        return x+y+1;
    }
    return 0;
}
int sum(struct node* p){
    if(p){
        int x=sum(p->left);
        int y=sum(p->right);

        return x+y+p->data;
    }
    return 0;
}
int degree(struct node* p){
    if(p){
        int x=degree(p->left);
        int y=degree(p->right);
        if(p->left && p->right)
            return x+y+1;
        else
            return x+y;
    }

}

int height(struct node* p){
    if(p){
        int x=height(p->left);
        int y=height(p->right);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

int leafnode(struct node* p){
    if(p){
        int x=leafnode(p->left);
        int y=leafnode(p->right);
        if(p->left==NULL && p->right==NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int internalnode(struct node* p){
    if(p){
        int x=internalnode(p->left);
        int y=internalnode(p->right);
        if(p->left==NULL || p->right==NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int main (){
    queue<struct node*> q;
    struct node* p=new node();
    struct node* root=new node();
    cout<<"Enter root data"<<endl;
    cin>>root->data;
    root->left=root->right=NULL;
    q.push(root);   
    while (!q.empty())
    {   int l,r;
        p=q.front();
        q.pop();
        cout<<"Enter left child of "<<p->data<<endl;
        cin>>l;
        if(l!=-1){
            struct node* temp=new node();
            temp->data=l;
            temp->left=temp->right=NULL;
            p->left=temp;
            q.push(temp);
        }
        cout<<"Enter right child of "<<p->data<<endl;
        cin>>r;
        if(r!=-1){
            struct node* temp1=new node();
            temp1->data=r;
            temp1->left=temp1->right=NULL;
            p->right=temp1;
            q.push(temp1);
        }
    }

    preorder(root);
    cout<<"Number of Node is: "<<count(root)<<endl;
    cout<<"Sum of all Node data is: "<<sum(root)<<endl;
    cout<<"Nodes with degree 2: "<<degree(root)<<endl;
    cout<<"Height of Binary tree is: "<<height(root)<<endl;
    cout<<"Number of leaf Nodes: "<<leafnode(root)<<endl;
    cout<<"Number of internal node: "<<internalnode(root)<<endl;
}