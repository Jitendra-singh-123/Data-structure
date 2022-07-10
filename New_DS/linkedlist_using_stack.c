#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*top=0;
void push();
void pop();
void peek();
void stackTop();
int isEmpty();
int isFull();
void display();

void main(){
    int ch;
    while(1){
        printf("\nEnter your choice\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Stack top\n");
        printf("5.Display\n");
        printf("5.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: stackTop();
                    break;
            case 5: display();
                    break;
            case 6:exit(1);
                    break;
            default : printf("Invalid Choice\n");   
        }
    }
}
int isEmpty(){
    if(top==0)
        return 1;
    else 
        return 0;
}

int isFull(){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==0)
        return 1;
    else
        return 0;
}

void push(){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be pushed\n");
    scanf("%d",&temp->data);
    if(isFull())
        printf("Stack is Overflow\n");
    else{
        temp->next=top;
        top=temp;
    }
}

void pop(){
    struct node* p=top;
    if(isEmpty())
        printf("Stack is Underflow\n");
    else{
        top=top->next;
        printf("Popped data is %d \t",p->data);
        free(p);
    }
}

void peek(){
    struct node* p=top;
    printf("Enter location which you want to see\n");
    int loc;
    scanf("%d",&loc);
    for(int i=0;p!=0 && i<loc-1;i++){
        p=p->next;
    }
    if(p!=0)
        printf("Peeked element is %d: ",p->data);
    else
        printf("Invalid location entered\n");
}

void stackTop(){
    if(top)
        printf("Stack top is %d\n",top->data);
    else
        printf("Top is not exists\n");
}

void display(){
    struct node* p=top;
    while (p!=0)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    
}