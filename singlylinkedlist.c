#include<stdio.h>
#include<stdlib.h>

//node definition
struct node
{
int data;
struct node *link;
};

void main()
{
struct node *start=(struct node*)0;
struct node *insert(struct node*,int);
struct node *delete(struct node*);
void display(struct node*);
int op,data;

do
{
printf("\n- Link_list operation -\n 1.insert \n 2.delete \n 3.display \n 4.exit \n Enter your choice: ");
scanf("%d",&op);
switch(op)
{
case 1:printf("\n Enter Data : ");
       scanf("%d",&data);
       start=insert(start,data);
       break;
       
case 2:start=delete(start);
       break;
       
case 3:display(start);
       break;
    
case 4:exit(0);
       
default:printf("\n Enter a valid choice : \n");
        break;
}
}
while(1);
}

//insert
struct node* insert(struct node* s,int item)
{
struct node* t;
t=(struct node*)malloc(sizeof(struct node*));
t->data=item;
t->link=s;
return t;
}

//delete
struct node* delete(struct node* s)
{
struct node* t;
t=s;
if(s!=(struct node*)0)
{
printf("\n %d is deleted \n",t->data);
s=s->link;
free(t);
}
else
printf("\n The link list is empty \n");
return s;
}

//display
void display(struct node*s)
{
while(s!=(struct node*)0)
{
printf("\n %d\t \n",s->data);
s=s->link;
}
}


  
 
