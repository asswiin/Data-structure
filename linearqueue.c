#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int queue[SIZE];
int front=-1,rear=-1;
void main()
{

//initialisation of function for queue operation
void insertq(int);
int deleteq();
int searchq(int);
int data,opt;
do
{
printf("\n 1.insert q \n 2.delete q  \n 3.search q \n 4.exit");
printf("\n select an option: ");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("\n Enter data:");
       scanf("%d",&data);
       insertq(data);
       break;
case 2:data=deleteq();
       printf("\n deleted item=%d \n",data);
       break;
case 3:
if(!(rear==front))
 {
       printf("\n item to be searched:");
       scanf("%d",&data);
       searchq(data);
       if(searchq(data)==1)
          printf("\n item found \n");
       else
          printf("\n item not found \n");
  }
  else
    {
     printf("\n empty queue \n");
     }

       break;
case 4:exit(0);
}
}
while(1);
}

//function to insert an item in a linear queue
void insertq(int item)
{
if(rear==SIZE-1)
  printf("queue in full \n");
else
  queue[++rear]=item;
}

//function to delete an item in a linear queue
int deleteq()
{
  if(front==rear)
  {
    printf(" queue in empty \n");
    exit(1);
    }
    return queue[++front];
    
}

//function to search an element in queue
int searchq(int item)
{
int tfront=front+1;

//searching
while(tfront!=rear && queue[tfront]!=item)
++tfront;
if(queue[tfront]==item)
return 1;
return 0;

}
