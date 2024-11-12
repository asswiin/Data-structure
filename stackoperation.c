#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int stack[SIZE];
int sp=-1;   //empty stack
void main()
{
int opt,data;
void push(int);
int pop();
void display();
do
{
printf("\n1:push\n2:pop\n3:display\n4:exit");
printf("\nyour option is: ");
scanf("%d", &opt);

switch(opt)
{
case 1:printf("\ndata:");
scanf("%d",&data);
push(data);
break;
case 2:data=pop();
printf("\npopped data: %d ",data);
break;
case 3:display();
break;
case 4:exit(0);
}
}while(1);
}


//function to insert element
void push(int data)
{
if(sp==SIZE-1)
printf("full stack \n");
else
stack[++sp]=data;
}


//function to delete element
int pop()
{
if(sp==-1)
{
printf("empty stack \n");
exit(0);
}
else
return stack[sp--];
}


//function to display the stack content 
void display()
{
int tsp=sp;
printf("\n stack contents:\n");
while(tsp!=-1)
{
printf(" %d ",stack[tsp]);
tsp--;
}
printf("\n");
}
