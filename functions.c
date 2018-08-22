#include <main.h>

node * insert_node (node * T, int x){
	if(T == NULL){
		T = (node*)malloc(sizeof(node));
		T -> data = x;
		T -> left = NULL;
		T -> right = NULL;
	}
    else
        if(x > T->data)
        {
            T->right=insert_node(T->right,x);
            if(balance_factor(T)==-2)
                if(x>T->right->data)
                    T=right_right(T);
                else
                    T=right_left(T);
        }
        else
            if(x<T->data)
            {
                T->left=insert_node(T->left,x);
                if(balance_factor(T)==2)
                    if(x < T->left->data)
                        T=left_left(T);
                    else
                        T=left_right(T);
            }

        T->ht=height(T);

        return(T);
}

node * remove_node(node *T,int x)
{
    node *p;

    if(T==NULL)
    {
        return NULL;
    }
    else
        if(x > T->data)
        {
            T->right=remove_node(T->right,x);
            if(balance_factor(T)==2)
                if(balance_factor(T->left)>=0)
                    T=left_left(T);
                else
                    T=left_right(T);
        }
        else
            if(x<T->data)
            {
                T->left=remove_node(T->left,x);
                if(balance_factor(T)==-2)
                    if(balance_factor(T->right)<=0)
                        T=right_right(T);
                    else
                        T=right_left(T);
            }
            else
            {
                if(T->right!=NULL)
                {
                    p=T->right;

                    while(p->left!= NULL)
                        p=p->left;

                    T->data=p->data;
                    T->right=remove_node(T->right,p->data);

                    if(balance_factor(T)==2)
                        if(balance_factor(T->left)>=0)
                            T=left_left(T);
                        else
                            T=left_right(T);\
                }
                else
                    return(T->left);
            }
    T->ht=height(T);
    return(T);
}

int height(node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);

    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;


    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;


    if(lh>rh)
        return(lh);

    return(rh);
}

node * rotate_right(node * x){
	node * y;
	y=x->left;
	x->left = y->right;
	y->right = x;
	x->ht = height(x);
	y->ht = height(y);
	return (y);
}

node * rotate_left(node * x){
	node * y;
	y = x->right;
	x->right = y->left;
	y->left=x;
	x->ht = height(x);
	y->ht = height(y);
	return (y);
}

node * right_right (node * T){
	T = rotate_left(T);
	return(T);
}

node * left_left(node * T){
	T=rotate_right(T);
	return (T);
}

node * left_right(node * T){
	T->left = rotate_left(T->left);
	T = rotate_right(T);

	return (T);
}

node * right_left (node * T){
	T->right = rotate_right(T->right);
	T = rotate_left(T);

	return (T);
}

int balance_factor(node * T){
	int lh, rh;
	if(T==NULL)
		return (0);

	if(T->left == NULL)
		lh=0;
	else
		lh = 1 + T->left->ht;

	if(T->right == NULL)
		rh=0;
	else
		rh=1+T->right->ht;

	return(lh-rh);
}

void preorder (node * T){
	if(T != NULL){
		printf("%d (BF=%d) // ", T->data,balance_factor(T));
		preorder(T->left);
		preorder(T->right);
		}
}

void inorder(node * T ){
	if(T!=NULL){
		inorder(T->left);
		printf("%d (BF=%d) // ",T->data,balance_factor(T));
		inorder(T->right);
		}
}
