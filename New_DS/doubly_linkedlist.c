#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
}*root=0;

void create();
void display();
void length();
void insert();
void delete();
void reverse();
void main(){
    int ch;
    while (1)
    {
        printf("Enter your choice\n");
        printf("1.Create\n");
        printf("2.Display\n");
        printf("3.Length\n");
        printf("4.Insert\n");
        printf("5.Delete\n");
        printf("6.Reverse\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:create();
                    break;
            case 2: display();
                    break;
            case 3: length();
                    break;
            case 4: insert();
                    break;
            case 5: delete();
                    break;
            case 6: reverse();
                    break;
            default : printf("Invalid choice\n");
        }
    }
    
}
void create(){
    struct node* temp,*p=root;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter node data\n");
    scanf("%d",&temp->data);
    temp->prev=temp->next=0;
    if(root==0)
        root=temp;
    else
    {
        while(p->next!=0)
        {
            p=p->next;
        }
        temp->prev=p;
        p->next=temp;
    }


}

void display(){
    struct node* p=root;
    while (p!=0)
    {   printf("%d->",p->data);
        p=p->next;
    }
    
}
void length(){
    struct node* p=root;
    int c=0;
    while (p!=0)
    {
        c++;
        p=p->next;
    }
    printf("Length of doubly linked list is %d\n",c);
    
}

void insert(){
    struct node* p=root,*temp;
    printf("Enter the location at which you want to insert the node\n");
    int loc,i=1;
    scanf("%d",&loc);
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the node data\n");
    scanf("%d",&temp->data);
    if(loc==1)
    {
        temp->next=root;
        root->prev=temp;
        root=temp;
    }
    else{
        while(i<loc){
            p=p->next;
            i++;
        }
        temp->next=p->next;
        temp->prev=p;
        if(p->next)
            p->next->prev=temp;
        p->next=temp;
        
    }
}

void delete(){
    struct node* p=root,*q;
    printf("Enter the location of node which you want to delete\n");
    int loc,i=1;
    scanf("%d",&loc);
    if(loc==1)
    {
        root=p->next;
        p->next->prev=0;
        p->next=0;
        free(p);
    }
    else {
        while (i<loc-1)
        {
            p=p->next;
            i++;
        }
        q=p->next;
        if(q->next)
        {   p->next=q->next;
            q->next->prev=p;
            q->next=q->prev=0;
            free(q);
        }
        else{
            p->next=0;
            q->prev=0;
            free(q);
        }
    }
}

void reverse(){
    struct node* p=root,*temp;
    while(p!=0)
    {   temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=0 && p->next==0)
            root=p;
   }

}