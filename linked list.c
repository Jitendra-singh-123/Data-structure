#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* link;
};
struct node* root=0;
int len;
void append();
void addafter();
int length();
void addatbegin();
void display();
void Delete();

void main(){
int ch;
while(1){
    printf("Enter the choice\n");
    printf("1.Append\n");
    printf("2.Add at begin\n");
    printf("3.Add at after\n");
    printf("4.Length\n");
    printf("5.Display\n");
    printf("6.Delete\n");
    printf("7.Quit\n");
    scanf("%d",&ch);
    switch(ch){
    case 1 : append();
                    break;
    case 2: addatbegin();
                    break;
    case 3: addafter();
                    break;
    case 4: len=length();
                    printf("Length is %d: ",len);
                    break;

    case 5: display();
                    break;

    case 6:  Delete();
                    break;
    case 7: exit(1);
                    break;
    default: printf("Invalid choice\n");
    }

}
}
 void append(){
struct node *temp,*p;
temp=(struct node*)malloc(sizeof(struct node));
if(temp==0)
        printf("not enough memory");
else {
printf("Enter the node data:\n");
scanf("%d",&temp->data);
temp->link=0;
    if(root==0){
        root=temp;
    }
    else
    {
        struct node* p;
        p=root;
    while(p->link!=0){
    p=p->link;
    }
    p->link=temp;
}
}
 }
int length(){
struct node* temp;
int c=0;
temp=root;
while(temp!=0){
    c++;
    temp=temp->link;
}
return c;
}
void display(){
struct node *temp;
temp =root;
if(temp==0){
    printf("list is empty\n");
}
else{
  while(temp!=0)
{
    printf("%d->",temp->data);
    temp=temp->link;
}
}
printf("\n");
}
void Delete(){
int loc;
struct node*temp;
printf("Enter location to delete:\n");
scanf("%d",&loc);
if(loc>length())
    printf("Invalid location\n");
else if(loc==1){
temp=root;
root=temp->link;
temp->link=0;
    free(temp);
    }
else{
    struct node *temp=root,*p;
    int i=1;
    while(i<loc-1){
        temp=temp->link;
        i++;
    }
    p=temp->link;
    temp->link=p->link;
    p->link=0;
    free(p);
}
}
void addatbegin(int item){
struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter the node data:\n");
scanf("%d",&temp->data);
temp->link=0;
if(root==0)
    root=temp;
else{
    temp->link=root;
    root=temp;
    }
}
void addafter()
{
    struct node *temp,*p;
    int loc,i=1;
printf("Enter the location after which u want to insert your node:\n");
scanf("%d",&loc);
if(loc>length())
    printf("Invalid location:\n");
else{
p=root;
while(i<loc){
    p=p->link;
    i++;
}
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter node data:\n");
scanf("%d",&temp->data);
temp->link=0;
temp->link=p->link;
p->link=temp;
}

}
