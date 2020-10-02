#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int info;
struct node* link;
}nodetype;
void push(nodetype**,int);
void pop(nodetype**);
void display(nodetype*);
void main(){
nodetype *top=0;
int ch,num;
while(1){
    printf("Enter your choice\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Display\n");
    printf("4.Quit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("Enter the item to push.\n");
                        scanf("%d",&num);
                        push(&top,num);
                        break;
    case 2: if(top!=0)
                        pop(&top);
                    else
                        printf("stack is underflow\n");
                    break;
    case 3: if(top!=0)
                            display(top);
                        else
                            printf("stack is underflow");
                        break;
  case 4: exit(0);
                break;
  default:  printf("Invalid choice\n");

    }
}
}
void push(nodetype** tp,int nm){
nodetype* temp;
temp=(nodetype*)malloc(sizeof(nodetype));
temp->info=nm;
temp->link=*tp;
*tp=temp;
}
void pop(nodetype** tp){
nodetype*temp;
temp=*tp;
printf("Element popped is %d\n",(*tp)->info);
(*tp)=(*tp)->link;
free(temp);
}
void display(nodetype* tp){
while(tp!=0)
{
    printf("%d\n",tp->info);
    tp=tp->link;

}
}


