#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int queue[SIZE];
front=0;
rear=0;
void insert();
void delete();
void traverse();
void main(){
int ch;
while(1){
    printf("Enter your choice.\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Traverse\n");
    printf("4.Quit\n")
    scanf("%d",&ch);
switch(ch){
case 1: insert();
                break;

case 2: delete();
                break;
case 3: traverse();
                break;
case 4: exit(0);
                break;
default: printf("invalid choice\n");

}
}
}
void insert(){
if(SIZE==rear)
    printf("Queue is full\n");
else{
        int ele;
    printf("Enter the element\n");
   scanf("%d",&ele);
    queue[rear]=ele;
    rear++;
}
}
void delete(){
if(front==rear)
    printf("Queue is empty\n");
else
{
  printf("Deleted element is %d",queue[front]);
for(int i=0;i<rear-1;i++)
{
    queue[i]=queue[i+1];
}
rear--;
}
}
void traverse(){
if(front==rear)
    printf("Queue is empty");
else
  {
    printf("Elements are:");
  for(int i=0;i<rear;i++)
  {
      printf("%d\n",queue[i]);

  }
  }

}
