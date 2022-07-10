#include<stdio.h>
#define CAPACITY 5
int stack[CAPACITY];
int top=-1;
void push();
void pop();
void peek();
void display();
int isFull();
int isEmpty();

void main(){
    int ch;
    while(1){
        printf("\nEnter your choice\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            case 5: exit(1);
                    break;
            default: printf("Invalid choice");   
        }

    }
} 
int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}

int isFull(){
    if(top==CAPACITY-1)
        return 1;
    else
        return 0;
}
void push(){
    int ele;
    printf("Enter the element to be push\n");
    scanf("%d",&ele);
    if(isFull())
        printf("Stack Overflow");
    else{
        top++;
        stack[top]=ele;
    }
}
void pop(){
    if(isEmpty())
        printf("Stack Underflow\n");
    else{
        printf("Element popped is: %d",stack[top]);
        top--;
    }
}

void peek(){
    if(isEmpty())
        printf("Stack is Underflow\n");
    else{
        printf("Peek element is: %d",stack[top]);
    }
}
void display(){
    if(isEmpty())
        printf("Stack is underflow\n");
    else{
        int i=0;
        while(i<=top){
            printf("%d\t",stack[i]);
            i++;
        }
    }
}