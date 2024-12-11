#include <stdio.h>
#include <stdlib.h>

//Node structure for a binary search tree
struct node
{
int data;
struct node *left;
struct node *right;
};

//function prototypes
struct node *insert(struct node *root,int data);
struct node *search(struct node *root,int data);
struct node *delete(struct node *root,int data);
void display(struct node *root);

void main()
{
struct node *root=NULL; //intialize an empty BST
int op,data;
do
{
printf("\n1.Insert \n2.Search \n3.Delete \n4.Display \n5.Exit \n");
printf("Your choice : ");
scanf("%d",&op);

switch(op)
{
case 1:printf("\nEnter data to insert : ");
       scanf("%d",&data);
       root=insert(root,data);
       break;

case 2:if(root==(struct node *)0) {
       printf("\nThe tree is empty\n");
       }else {
       printf("\nEnter data to search : ");
       scanf("%d",&data);
       if(search(root,data))
          printf("\nItem found \n");
       else
          printf("\nItem Not found \n");
          }
       break;

case 3:if(root==(struct node *)0) {
       printf("\nThe tree is empty\n");
       }else{
       printf("\nEnter data to delete : ");
       scanf("%d",&data);
       root=delete(root,data);
       }
       break;

case 4:if(root==(struct node *)0) {
       printf("\nThe tree is empty\n");
       }else{
       printf("\nTree traversal(inorder)\n");
       display(root);
       printf("\n");
       }
       break;
   
case 5:exit(0);
default:printf("\nInvalid choice.please try again.\n");
}
}while(1);
}

//function to insert a new node
struct node *insert(struct node *root,int data)
{
struct node *t,*t1=root;
t=(struct node *)malloc(sizeof(struct node));
t->data=data;
t->left=t->right=(struct node *)0;
if(root==(struct node *)0)
   root=t;
else
{
while(t1!=(struct node *)0 && t1->data!=data)
{
if(data<t1->data)
{
if(t1->left==(struct node *)0) //if left child is null,insert here
{
t1->left=t;
break;
}
t1=t1->left; //move to left subtree
}
else
{
if(t1->right==(struct node *)0) //if right child is null,insert here
{
t1->right=t;
break;
}
t1=t1->right; //move to right subtree
}
}
if(t1!=(struct node *)0 && t1->data==data) //check for duplicates *after* the loop
{
printf("\nDuplicate element not allowed \n");
free(t);
}
}
return root;
}

//function search new node
struct node *search(struct node *root,int data)
{
while(root!=(struct node *)0 && root->data!=data) //corrected comparison
{
if(data<root->data)
   root=root->left;
else
   root=root->right;
}
return root;
}

//function to delete a node in the BST(corrected)
struct node *delete(struct node *root,int data)
{
struct node *t1=root,*t2=(struct node *)0; //initialize t2 to NULL
while(t1!=(struct node *)0 && t1->data!=data)
{
t2=t1;
if(data<t1->data)
t1=t1->left;
else
t1=t1->right;
}
if(t1==(struct node *)0)
{
printf("\nNode not found \n");
return root;
}
if(t1->left==(struct node *)0 && t1->right==(struct node *)0) //case1:Node has no children
{
if(t2==(struct node *)0) //if the node to delete is the root
   root=(struct node *)0; //set root to NULL,the tree is now empty
else
if(t2->left==t1) //if t1 is the left child of t2
t2->left=(struct node *)0;
free(t1);
}
else if(t1->left==(struct node *)0 || t1->right==(struct node *)0) //case 2:Node has one child
{
struct node *child=(t1->left!=(struct node *)0) ? t1->left : t1->right; //determine which child
if(t2==(struct node *)0)        //if the node to delete is the root
root=child;
else if(t2->left==t1)  //if t1 is the left child of t2
t2->left=child;
else
t2->right=child;  //replace t1 with its child
free(t1);  //free the memory for t1
}
else //case 3:node has two children
{
struct node *sucpar=t1;
struct node *t2=t1->right;
while(t2->left!=(struct node *)0)
{
sucpar=t2;
t2=t2->left;
}
t1->data=t2->data;
if(sucpar->left==t2)
sucpar->left=t2->right;
else
sucpar->right=t2->right;
free(t2);
}
return root;
}

//function to display the BST in inorder(sorted order)-corrected for left-right order
void display(struct node *root)
{
if(root!=(struct node *)0)
{
display(root->left); //correct order for inorder traversal
printf("%d ",root->data);
display(root->right);
}
}




