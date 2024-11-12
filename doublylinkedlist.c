#include <stdio.h>
#include <stdlib.h>

// Node definition
struct node {
    int data;
    struct node *left, *right;
};

struct node* insert(struct node*, int);
struct node* delete(struct node*, int);
struct node* search(struct node*, int);
void display(struct node*);

int main() {  // Changed to 'int main()'
    struct node *start = (struct node*)0;
    int op, data;

    do {
        printf("\n Doubly Linked List Operation \n");
        printf(" 1. Insert\n 2. Delete\n 3. Search\n 4. Display\n 5. Exit\n");
        printf("\n Your choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("\n Enter data: ");
                scanf("%d", &data);
                start = insert(start, data);
                break;

            case 2:
                if (start == (struct node*)0) {
                    printf("\n List is empty\n");
                } else {
                    printf("\n Enter data to delete: ");
                    scanf("%d", &data);
                    start = delete(start, data);
                }
                break;

            case 3:
                if (start == (struct node*)0) {
                    printf("\n List is empty\n");
                } else {
                    printf("\n Enter data to search: ");
                    scanf("%d", &data);
                    struct node* result = search(start, data);
                    if (result != (struct node*)0) {
                        printf("\n Item found: [%d]\n", result->data);
                    } else {
                        printf("\n Item not found\n");
                    }}
                break;

            case 4:
                display(start);
                break;

            case 5:
                exit(0);

            default:
                printf("Enter a valid choice:\n");
                break;
        }
    } while (1);
}

// Insert
struct node* insert(struct node* s, int item) {
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = item;
    t->right = s;
    t->left = (struct node*)0;
    if (s != (struct node*)0) {
        s->left = t;
    }
    return t;
} 

// Delete
struct node* delete(struct node* s, int data) {
    struct node *t = search(s, data);
    if (t != (struct node*)0) {
        printf("\n [%d] is deleted\n", t->data);
        if (t->left == (struct node*)0 && t->right == (struct node*)0) { // only one node
            s = (struct node*)0;
        } else if (t->left == (struct node*)0) { // deleting the first node
            s = t->right;
            if (s != (struct node*)0) {
                s->left = (struct node*)0;
            }
        } else if (t->right == (struct node*)0) { // deleting last node
            t->left->right = (struct node*)0;
        } else { // deleting a node in the middle
            t->left->right = t->right;
            t->right->left = t->left;
        }
        free(t);
    } else {
        printf("\n Item not found\n");
    }
    return s; }

// Search
struct node* search(struct node* s, int item) {
    struct node *t = s;
    while (t != (struct node*)0 && t->data != item) {
        t = t->right;
    }
    return t;
}

// Display
void display(struct node* s) {
    if (s == (struct node*)0) {
        printf("\n List is empty\n");
        return;
    }
    while (s != (struct node*)0) {
        printf("%d\t", s->data);
        s = s->right;
    }
    printf("\n");
}

