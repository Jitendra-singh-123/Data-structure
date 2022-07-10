#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void traverse();
#define CAPACITY 5
int queue[CAPACITY];
int front=-1,rear=-1;

void main(){
    int ch;
    while(1){
        printf("Enter your choice\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Traverse\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: traverse();
                    break;
            case 4: exit(1);
                    break;
            default: printf("Invalid choice\n");
        }
    }
}

void enqueue(){
    int data;
    if(rear==CAPACITY-1)
        printf("Queue is full\n");
    else{
        printf("Enter your data\n");
        scanf("%d",&data);
        rear++;
        queue[rear]=data; 
    }
}

void dequeue(){
    if(front==rear)
        printf("Queue is Empty\n");
    else{
        front++;
        printf("%d",queue[front]);
    }
}

void traverse(){
    for(int p=front+1;p<=rear;p++){
        printf("%d",queue[p]);
        printf("\n");
    }
    
}