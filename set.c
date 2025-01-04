#include <stdio.h>
#include <stdlib.h>

int uset[]={1,2,3,4,5,6,7,8,9,10},SIZE=9;

typedef struct bit{
    unsigned char x:1; //1-bit flag for each element
}bit;

//Function prototype
void readset(bit s[],int n);
void printset(bit s[]);
void set_union(bit a[],bit b[],bit c[]);
void set_intersection(bit a[],bit b[],bit c[]);
void set_difference(bit a[],bit b[],bit c[]);
 
void main()
{
     printf("\n-----Set operation-----\n");
     bit a[10]={0}, b[10]={0}, c[10]={0};
     int n;
     
     //input of set A
     printf("\nNo of Elements in Set A : ");
     scanf("%d",&n);
     readset(a,n);
     
     //input of set B
     printf("\nNo of Elements in Set B : ");
     scanf("%d",&n);
     readset(b,n);
     
//Display set
printf("\nSet A: ");
printset(a);
printf("Set B: ");
printset(b);

//set union
set_union(a,b,c);
printf("\nSet union : ");
printset(c);

//set intersection
set_intersection(a,b,c);
printf("\nSet intersection : ");
printset(c);

//set difference
set_difference(a,b,c);
printf("\nSet difference(A-B) : ");
printset(c);
}

void printset(bit s[])
{
     int k;
     printf("{ ");
     for(k=0;k<=SIZE;k++)
        if(s[k].x==1)
           printf("%d ",uset[k]);//proper coma separated 
     printf(" }\n");
}

void readset(bit s[],int n)
{
     int i,x,k;
     printf("\nEnter %d Elements: ",n);
     for(i=0;i<n;i++)
     {
        scanf("%d",&x);
        for(k=0;k<=SIZE;k++)
            if(uset[k]==x)
            {
               s[k].x=1; //mark the corresponding element as part of the set
               break;
            }
     }
}

void set_union(bit a[], bit b[], bit c[])
{
    int i;
    for(i=0; i<=SIZE;i++)
        c[i].x=a[i].x | b[i].x; //union:OR operation 
}

void set_intersection(bit a[], bit b[], bit c[])
{
     int i;
     for(i=0; i<=SIZE;i++)
        c[i].x=a[i].x & b[i].x; //intersection:AND operation
}

void set_difference(bit a[], bit b[], bit c[])
{
    int i;
    for(i=0; i<=SIZE; ++i)
    if(a[i].x==1)
       c[i].x=a[i].x ^ b[i].x; //difference(A-B):XOR operation
     
}




