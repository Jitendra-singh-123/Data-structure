#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int cqueue[SIZE];
front=0;
rear=0;
void insert(int ele);
void delete();

void main(){
int ch,ele;
while(1){
    printf("Enter your choice.\n");
    printf("1.Insert\n");
    printf("2.Delete\n");

    printf("3.Quit\n");
    scanf("%d",&ch);
switch(ch){
case 1:     printf("Enter element:\n");
                    scanf("%d",&ele);
                insert(ele);
                break;

case 2: delete();
                break;
case 3: exit(0);
                break;
default: printf("invalid choice\n");

}
}
}
void insert(int ele){
if(front==rear+1||rear==SIZE-1)
    printf("Circular Queue is full");
else if(front==-1 && rear==-1)
{
front=rear=0;
cqueue[rear]=ele;
}
else if(rear==SIZE-1){
    rear=0;
    cqueue[rear]=ele;
}
else{
    rear++;
    cqueue[rear]=ele;
}
}
void delete(){
    int ele;
if(front==-1&&rear==-1)
    printf("Circular Queue is empty\n");
else if(front==rear)
{
    printf("Deleter element is %d:\t",cqueue[front]);
    ele=cqueue[front];
    front=rear=-1;

}
else if(front==SIZE-1){
            printf("Deleter element is %d:\t",cqueue[front]);

    ele=cqueue[front];
    front=0;
}
else{


    ele=cqueue[front];
     printf("Deleter element is %d:\t",ele);
    front++;
}

}
