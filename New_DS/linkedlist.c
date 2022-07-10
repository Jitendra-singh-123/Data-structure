#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
struct node
{
    int data;
    struct node *link;
};
struct node *root=0,*second=0;
int len;
void create();
void display();
int length();
void reversePrint();
void addAtBegin();
void addAfter();
void Delete();
void sum();
void maxMin();
void search();
void insertAtSortedPos();
int sortOrNot();
void sort();
void reverse();
void RemoveDuplicate();
void create1();
void Concatenating();
void main(){
    int ch;
    while (1)
    {
        printf("\nEnter the choice\n");
        printf("1.Create\n");
        printf("2.Display\n"); 
        printf("3.Length\n");
        printf("4.Reverse print\n");
        printf("5.Add at begin\n");
        printf("6.Add After\n");
        printf("7.Delete\n");
        printf("8.Sum\n");
        printf("9.MaxMin\n");
        printf("10.Search\n");
        printf("11.Insert node at sorted linked list in sorted position\n");
        printf("12.Check whether linked list is sorted or not\n");
        printf("13.Sort\n");
        printf("14.Remove Duplicate\n");
        printf("15.Reverse\n");
        printf("16.Create second linked list\n");
        printf("17.Concatenating two linked list\n");
        printf("18.Exit\n");
        scanf("%d",&ch);  
        switch(ch){
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: len=length();
                    printf("Length of linkedlist is %d: ",len);
                    break;
            case 4: reversePrint(root);
                    break;
            case 5: addAtBegin();
                    break;
            case 6: addAfter();
                    break;
            case 7: Delete();
                    break;
            case 8: sum();
                    break;
            case 9:maxMin();
                    break;
            case 10: search();
                        break;
            case 11: insertAtSortedPos();
                     break;
            case 12: if(sortOrNot())
                        printf("Linked list is sorted");
                    else
                        printf("Linked list is not sorted");
                    break;
            case 13: sort(root);
                    break;
            case 14: RemoveDuplicate(root);
                    break;
            case 15: reverse();
                     break;
            case 16: create1();
                     break;
            case 17: Concatenating();
                     break;
            case 18: exit(1);
                    break;
            default: printf("Wrong choice");
        }
    }
    
}
void create(){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter node data\n");
    scanf("%d",&temp->data);
    temp->link=0;
    if(root==0)
        root=temp;
    else{
        struct node *p;
        p=root;
        while(p->link!=0){
            p=p->link;
        }
        p->link=temp;
}
}

void display(){
    struct node *temp;
    temp=root;
    while(temp!=0){
        printf("%d->",temp->data);
        temp=temp->link;
    }
}

int length(){
    struct node *temp;
    temp=root;
    int c=0;
    while(temp!=0){
        temp=temp->link;
        c++;
    }
    return c;
}
void reversePrint(struct node *p){
    if(p!=0){
        reverse(p->link);
        printf("%d->",p->data);
    }
}

void addAtBegin(){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the new node data\n");
    scanf("%d",&temp->data);
    if(root==0)
        root=temp;
    else
    {    temp->link=root;
        root=temp;
    }
}

void addAfter(){
    int loc;
    printf("Enter location after which you want to add your node\n");
    scanf("%d",&loc);
    int i=1;
    if(loc>length())
        printf("Invalid location");
    else
    {
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        printf("Enter node data\n");
        scanf("%d",&temp->data);
        struct node *p;
        p=root;
        while(i<loc){
            p=p->link;
            i++;
        }
        temp->link=p->link;
        p->link=temp;
    }
}
void Delete(){
    struct node *temp,*p;
    printf("Enter location of node which is to be deleted\n");
    int loc;
    scanf("%d",&loc);
    if(loc>length())
        printf("Invalid location");
    else if(loc==1)
        {
            temp=root;
            root=temp->link;
            temp->link=0;
            free(temp);
        }
    else{
        struct node *temp=root,*p;
        int i=1;
        while(i<loc-1){
            temp=temp->link;
            i++;
        }
        p=temp->link;
        temp->link=p->link;
        p->link=0;
        free(p);
    }
}

void sum(){
    struct node *p;
    p=root;
    int sum=0;
    while(p!=0){
        sum+=p->data;
        p=p->link;
    }
    printf("Sum of all nodes is: %d",sum);
}

void maxMin(){
    struct node *p;
    p=root;
    int max=INT_MIN,min=INT_MAX;
    while(p!=0){
        if(max<p->data)
            max=p->data;
        if(min>p->data)
            min=p->data;
        p=p->link;
    }
    printf("\nMaximum is %d",max);
    printf("\nMinimum is %d\n",min);
}

void search(){
    struct node *p;
    p=root;
    int key,flag=0;
    printf("Enter element which is to be searched.\n");
    scanf("%d",&key);
    int i=1;
    while(p!=0){
        if(key==(p->data))
        {    
            flag=1;
            break;
        }
        i++;
        p=p->link;
    }
    if(flag==1)
        printf("Found at node: %d",i);
    else
        printf("Not found\n");
}

void insertAtSortedPos()
{
    struct node *p,*q;
    p=root;
    int n;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter node data\n");
    scanf("%d",&temp->data);
    temp->link=0;
    q=p->link;
    while(q!=0)
    {
        if(p->data < temp->data && q->data > temp->data){
            temp->link=q;
            p->link=temp;
        }
        p=p->link;
        q=p->link;
    }
}

int sortOrNot(){
    struct node *p;
    p=root;
    int min=INT_MIN;
    while(p!=0){
        if(min<p->data)
            min=p->data;
        else if(p->data<min)
            return 0;
        p=p->link;
    }
    return 1;
}

void sort(struct node *p){
    int temp;
    struct node *q;
    while (p!=0)
    {
        q=p->link;
        while (q!=0)
        {
            if(p->data > q->data){
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
            q=q->link;
        }
        p=p->link;
        
    } 
}

void RemoveDuplicate(struct node *p){
    struct node *q;
    q=p->link;
    while(q!=0){
        if(p->data != q->data){
            p=q;
            q=q->link;
        }
        else{
            p->link=q->link;
            free(q);
            q=p->link;
        }
    }
}

void reverse(){
    struct node *p=root,*q=0,*r=0;
    while(p!=0){
        r=q;
        q=p;
        p=p->link;
        q->link=r;
    }
    root=q;
}

void create1(){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter node data\n");
    scanf("%d",&temp->data);
    temp->link=0;
    if(second==0)
        second=temp;
    else{
        struct node *p;
        p=second;
        while(p->link!=0){
            p=p->link;
        }
        p->link=temp;
    }
}
void Concatenating(){
    struct node *p;
    p=root;
    while (p->link!=0)
    {
        p=p->link;
    }
    p->link=second;

}