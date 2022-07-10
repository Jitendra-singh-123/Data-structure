#include <bits/stdc++.h>
using namespace std;
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
}*root=NULL;
Node *create(struct Node *p, int key)
{

    if (p == NULL)
    {
        struct Node *t = new Node();
        t->data = key;
        t->left = t->right = NULL;
        return t;
    }
    if (p->data == key)
        return p;
    else if (p->data > key)
        p->left = create(p->left, key);
    else if (p->data < key)
        p->right = create(p->right, key);
}
Node *search(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    else if (p->data == key)
        return p;
    else if (p->data > key)
        return search(p->left, key);
    else
        return search(p->right, key);
}
void preorder(struct Node *p)
{
    if (p)
    {
        cout << p->data << endl;
        preorder(p->left);
        preorder(p->right);
    }
}
int Height(Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->left);
    y = Height(p->right);
    return x > y ? x + 1 : y + 1;
}
Node *inorderSuccessor(Node *p)
{
    while (p && p->left != NULL)
    {
        p = p->left;
    }
    return p;
}
Node *inorderPredecessor(Node *p)
{
    while (p && p->right != NULL)
    {
        p = p->right;
    }
    return p;
}

Node *remove(Node *p, int key)
{
    struct Node *q = new Node();
    if (p == NULL)
        return NULL;
    if (p->left == NULL && p->right == NULL)
    {
        if (p == root)
            root = NULL;
        delete p;
        return NULL;
    }
    if (key < p->data)
        p->left = remove(p->left, key);
    else if (key > p->data)
        p->right = remove(p->right, key);
    else
    {
        if (Height(p->left) >= Height(p->right))
        {
            q = inorderPredecessor(p->left);
            p->data = q->data;
            p->left = remove(p->left, q->data);
        }
        else
        {
            q = inorderSuccessor(p->right);
            p->data = q->data;
            p->right = remove(p->right, q->data);
        }
    }

    return p;
}

int main()
{   struct Node* root=new Node();
    cout << "Insert Root Node data first\n";
    int x, ch;
    cin >> x;
    root->data = x;
    root->left = root->right = 0;
    while (1)
    {
        cout << "Enter your choice\n";
        cout << "1.Enter New Node\n";
        cout << "2.Preorder traversal\n";
        cout << "3.Search\n";
        cout << "4.Delete\n";
        cout << "5.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter data\n";
            cin >> x;
            create(root, x);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            cout << "Enter key to be searched\n";
            cin >> x;
            cout << search(root, x)->data << endl;
            break;
        case 4:
            cout << "Enter which Node to be delete\n";
            cin >> x;
            remove(root, x);
            break;
        case 5:
            exit(1);
            break;
        }
    }
}