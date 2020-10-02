#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX],top=-1;
void push(int );
void pop();
void peek();
void traverse();
int isEmpty();
int isFull();
void main(){
int ch,item;
while(1){
printf("\nChoose the option\n");
printf("1.push\n");
printf("2.pop\n");
printf("3.peek\n");
printf("4.traverse\n");
printf("5.Quit\n");
scanf("%d",&ch);
switch(ch){
case 1: printf("Enter the element\n");
                scanf("%d",&item);
                push(item);
                break;
case 2: pop();
              break;
 case 3: peek();
                break;
case 4: traverse();
                break;
 case 5: exit(0);
                break;
default : printf("Enter valid choice\n");
}
}
}
void push(int ele){
if(isFull()){
printf("Stack is overflow\n");
}
else
{
top++;
stack[top]=ele;
printf("pushed element is %d: ",ele);
}
}

int isFull(){
if(top==MAX-1)
    return 1;
else
    return 0;
}
void pop(){
if(isEmpty()){
    printf("Stack is underflow\n");
}
else{
    printf("popped element is %d",stack[top]);
    top--;
    }
}
int isEmpty(){
if(top==-1)
    return 1;
else
    return 0;
}
void peek(){
if(isEmpty()){
    printf("Stack is underflow\n");
}
else{
        printf("peek element is %d",stack[top]);
}
}
void traverse(){
if(isEmpty()){
    printf("Stack is underflow\n");
}
else{
    printf("Stack elements are:\n");
    for(int i=0;i<=top;i++)
   {
    printf("%d\n",stack[i]);
   }
}
}
