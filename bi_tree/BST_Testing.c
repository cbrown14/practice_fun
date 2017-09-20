#include <stdio.h>
#include <stdlib.h>
#include "my_BST_lib.h"
#include <time.h>

void main(){
	srand(time(NULL));

	tree_node* root = insert_node(NULL,(rand()%50));

	int i;
	for(i=0;i<20;i++){
		insert_node(root,rand()%50);
	}

	inorder(root);

	int count = get_size(root);

	printf("\nCount1 = %d\n",count);

	insert_node(root,40);
	insert_node(root,102);

	count = get_size(root);

	printf("\nCount2 = %d\n",count);
}
