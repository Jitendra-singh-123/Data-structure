#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node* link;
}nodetype;
nodetype* insert(nodetype*);
nodetype* delete(nodetype*);
void display(nodetype*);
void main(){
int ch;
nodetype* front=0,*rear=0;
while(1){
    printf("Enter your choice.\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Traverse\n");
    printf("4.Quit\n");
    scanf("%d",&ch);
switch(ch){
case 1: rear=insert(rear);
                if(front==0)
                    front=rear;
                break;
case 2 : front=delete(front);
                if(front==0)
                    rear=0;
                break;
case 3: display(front);
                break;
case 4: exit(0);
                break;
default: printf("Invalid choice\n");
}
}
}
nodetype* insert(nodetype* rear){
nodetype* p=0;
p=(nodetype*)malloc(sizeof(nodetype));
if(p==0)
    printf("not enough memory");
else{
    printf("Enter node data:\n");
    scanf("%d",&p->data);
    p->link=0;
    if(rear==0)
        rear=p;
else{
    rear->link=p;
    rear=p;
    }


}
return rear;
}
nodetype* delete(nodetype* front){
    nodetype* p=0;
if(front==0){
    printf("list is empty");
}
else{
        printf("Deleted element is %d:\n",front->data);
        p=front;
        front=front->link;
        free(p);
        }
        return front;
}

void display(nodetype*front){
if(front==0)
    printf("list is empty\n");
else{
    while(front!=0){
        printf("%d\n",front->data);
        front=front->link;
    }

}
}
