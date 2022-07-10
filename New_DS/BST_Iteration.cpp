#include <bits/stdc++.h>
using namespace std;
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};
Node *search(struct Node *p, int key)
{
    while (p)
    {
        if (p->data == key)
            return p;
        else if (p->data > key)
            p = p->left;
        else
            p = p->right;
    }
    return NULL;
}
void create(struct Node *p, int key)
{
    struct Node *temp = new Node();
    struct Node *r = 0;
    while (p)
    {
        r = p;
        if (p->data > key)
            p = p->left;
        else if (p->data < key)
            p = p->right;
        else
            return;
    }
    temp->data = key;
    temp->left = temp->right = 0;
    if (key > r->data)
        r->right = temp;
    else
        r->left = temp;
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

int main()
{
    struct Node *root = new Node();
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
        cout << "4.Exit\n";
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
            exit(1);
            break;
        }
    }
}