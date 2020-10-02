#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int info;
struct node* link;
}nodetype;
nodetype* push(nodetype*,int);
nodetype* pop(nodetype*);
void display(nodetype*);
int main(){
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
                        top=push(top,num);
                        break;
        case 2:  if(top!=0)
                            top=pop(top);
                        else
                            printf("Stack is is underflow\n");
                        break;
         case 3: if(top!=0)
                            display(top);
                        else
                            printf("stack is underflow");
                        break;
            case 4: exit(1);
                            break;
            case 5: printf("Invalid choice\n");
                            break;

    }

}
return 0;
}
nodetype* push(nodetype* tp,int nm){
nodetype* temp;
temp=(nodetype*)malloc(sizeof(nodetype));
if(temp==0)
    printf("Not enough memory.\n");
else{
    temp->info=nm;
    temp->link=tp;
    tp=temp;
}
return tp;
}
nodetype* pop(nodetype* tp){
nodetype* temp;
temp=tp;
printf("Element popped is %d\n",tp->info);
tp=tp->link;
free(temp);
return (tp);
}
void display(nodetype* tp){
while(tp!=0)
{
    printf("%d\n",tp->info);
    tp=tp->link;

}
}
