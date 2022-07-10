#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*front=NULL,*rear=NULL;
void enqueue();
void dequeue();
void display();
void main(){
    int ch;
    while (1)
    {
        printf("Enter to your choice\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: enqueue();
            break;
        case 2: dequeue();
            break;
        case 3: display();
            break;
        case 4: exit(1);
            break;
        
        default:printf("Invalid  choice\n");
            break;
        }
    }
    
}

void enqueue(){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    if(temp==NULL)
        printf("Queue is Full\n");
    else{
        printf("Enter node data\n");
        scanf("%d",&temp->data);
        if(front==NULL)
            front=rear=temp;
        else{
            rear->next=temp;
            rear=temp;
        }
    }
}


void dequeue(){
    if(front==NULL)
        printf("Queue is Empty\n");
    else{
        struct node* p=front;
        printf("Element dequeud is: %d",front->data);
        front=p->next;
        p->next=NULL;
        free(p);
    }
}

void display(){
    struct node* p=front;
    while (p!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    
}