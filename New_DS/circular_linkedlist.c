#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *root;
void create();
void display();
void  insert();
void delete();
void main(){
    int ch;
    while(1){
        printf("\nEnter the choice\n");
        printf("1.Create\n");
        printf("2.Display\n");
        printf("3.Insert\n");
        printf("4.Delete\n");
        printf("5.Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: create();
                break;
        case 2: display();
                break;
        case 3: insert();
                break;
        case 4: delete();
                break;
        case 5: exit(1);
                break;
        default: printf("Invalid choice");
        }

    }
}

void create(){
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter node data\n");
    scanf("%d",&temp->data);
    if(root==0)
    {
        root=temp;
        temp->link=root;
    }
    else{
        p=root;
        while(p->link!=root){
            p=p->link;
        }
        p->link=temp;
        temp->link=root;
    }
}

void display(){
    struct node *p=root;
    do{
        printf("%d->",p->data);
        p=p->link;
    }while(p!=root);
}

void insert(){
    struct node *temp,*p=root,*q=root;
    int i=1,loc;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter location after which you want to insert your node\n");
    scanf("%d",&loc);
    printf("Enter the node data\n");
    scanf("%d",&temp->data);
    temp->link=0;
    if(loc==1){
        temp->link=root;
        root=temp;
        while(p->link!=q){
            p=p->link;
        }
       p->link=root;
    }
    else{
        while(i<loc){
            p=p->link;
            i++;
        }
        temp->link=p->link;
        p->link=temp;
    }


}

void delete(){
    struct node *p=root,*q=root,*temp;
    int loc,i=1;
    printf("Enter the location of node which is to be deleted\n");
    scanf("%d",&loc);
    temp=(struct node*)malloc(sizeof(struct node));
    if(loc==1){
        while(p->link!=root){
            p=p->link;
        }
        root=q->link;
        q->link=0;
        free(q);
        p->link=root;
    }
else{
    while(i<loc-1){
            p=p->link;
            i++;
        }
        temp=p->link;
        p->link=temp->link;
        temp->link=0;
        free(temp);
    }
}