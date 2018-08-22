#include <main.h>

int main(void)
{
	node * root = NULL;
	int x, n, op;

        printf("                       ~~~  self-balancing binary search tree ~~~~ \n");
        printf("\n                      (1)Create || (2)Insert ||");
		printf("\n                      (3)Delete || (4)Print  || (5)Quit");

	do{
		printf("\n\n Enter your choice: ");
		scanf("%d",&op);

		switch(op)
		{
			case 1:	printf("\nEnter no. of elements: ");
                    scanf("%d",&n);
                    printf("\nEnter data: \n");
                    root = NULL;
                    for(int i=0;i<n;i++){
					scanf("%d",&x);
					root = insert_node(root,x);
                                        }
                    break;


			case 2:	printf("\nEnter data: ");
                    scanf("%d",&x);
                    root = insert_node(root,x);
                    break;


			case 3:	printf("\nEnter target data: ");
                    scanf("%d",&x);
                    root = remove_node(root,x);
                    break;


			case 4:	printf("\nPre-order sequence: \n");
                    preorder(root);
                    printf("\nIn-order sequence: \n");
                    inorder(root);
                    printf("\n");
                    break;
		}
	}while(op != 5);

	return 0;
}
