#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int que[SIZE];
int front=0,rear=0;
void main()

{

//initialisation
void insertq(int);
void deleteq();
int search(int);
int op,data;

do
{
printf("\n 1.insert que \n 2.delete que \n 3.search \n 4.exit \n select an option :");
scanf("%d",&op);
switch(op)
{
case 1:printf("\n Enter data: ");
scanf("%d",&data);
insertq(data);
break;
case 2:deleteq();
break;
case 3:
if(front==rear)
{
printf("\n queue is empty \n");
}
else
{

printf("\n Enter value to search : ");
scanf("%d",&data);
       
if(search(data))
printf(" \n The item is present \n");
else
printf(" \n The item is not present \n");
}
break;

case 4:exit(0);
default:printf("\n enter a valid choice                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   \n");
break;
}
}
while(1);
}

//insert an item
void insertq(int data)
{
int trear=rear;
trear=(trear+1)%SIZE;
if(trear==front)
printf(" full queue \n");
else
{
   rear=trear;
   que[rear]=data;
}
}


//delete an item
void deleteq()
{
 if(front==rear)
  {
   printf("\n Empty queue \n");
  }
 else
  {
   front=(front+1)%SIZE;
   printf("\n [%d] is deleted from queue \n",que[front]);
  }
}


//search an item
int search(int item)
{
int tfront;
tfront=(front+1)%SIZE;
//searching
while(tfront!=rear && que[tfront]!=item)
tfront=(tfront+1)%SIZE;

if(que[tfront]==item)
return 1;
return 0;
}
   



