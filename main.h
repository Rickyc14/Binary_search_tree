#include <stdio.h>

typedef struct node{
	int data;
	struct node * left;
	struct node * right;
	int ht;
}node;

node * insert_node (node *, int);
node * remove_node (node *, int);
void preorder (node *);
void inorder (node *);
int height (node *);
node * rotate_right (node *);
node * rotate_left (node *);
node * right_right (node *);
node * left_left (node *);
node * left_right (node *);
node * right_left (node *);
int balance_factor(node *);

