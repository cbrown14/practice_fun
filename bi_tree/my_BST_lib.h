/* Cameron Brown
 * 9/19/2017
 * my_BST_lib.h
 *
 * Some simple helper functions for a BST libary
 */

#include <stdio.h>
#include <stdlib.h>

/* tree_node definition */
typedef struct tree_node{
	int val;
	struct tree_node* left;
	struct tree_node* right;
} tree_node;


/* Function Primitives */
tree_node* new_node(int);
tree_node* insert_node(tree_node*,int);
tree_node* search(tree_node*,int);
void inorder(tree_node*);
void postorder(tree_node*);
void preorder(tree_node*);
int get_size(tree_node*);

/* Create a new node. Returns pointer to new node */
tree_node* new_node(int data){

	/* Malloc the size of the node and initialize the value to the inputted data, 
	   and pointers to null */
	tree_node* temp = (tree_node*)malloc(sizeof(tree_node*));
	temp->val = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

/* Recursively insert a node into the tree.
   Usage: insert_node(root_node, new_node_value) Inserts node into tree with existing root node.
	  root = insert_node(NULL, root_node_value) Returns new root node */
tree_node* insert_node(tree_node* cur_node, int data){

	/* If we traversed to a point where the node is NULL, it means we must input our node there.
	   We return the new node so that its parent can point to it. */
	if(cur_node == NULL){ return new_node(data); }

	/* If new node value is less than the current node value, traverse left */
	if(data < cur_node->val){
		cur_node->left = insert_node(cur_node->left,data);
	}

	/* If the new node value is greater than the current node value, traverse right */
	else if(data >= cur_node->val){
		cur_node->right = insert_node(cur_node->right,data);
	}

	/* If neither, we are done and can return the current node */
	return cur_node;
}

/* Recursively searches for a node given a root node and a value to search for
   Usage: tree_node* node = search(root,value) Returns node with data = value
*/
tree_node* search(tree_node* cur_node, int data){

	/* If the current node is NULL, the node with value = data does not exist
	   If the current node's value = data, our search is over. */
	if(cur_node == NULL || cur_node->val == data)
		return cur_node;

	/* Traverse left if data < current node's value */
	if(data < cur_node->val){
		return cur_node->left = search(cur_node->left,data);
	}

	/* Else, traverse right */
	return cur_node->right = search(cur_node->right, data);
}

int get_size(tree_node* root){
	if(root == NULL)
		return 0;
	else
		return(get_size(root->left) + get_size(root->right) + 1);

}

/* Post order printing of tree */
void postorder(tree_node* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d \n",root->val);
	}
}

/* Pre order printing of tree */
void preorder(tree_node* root){
	if(root != NULL){
		printf("%d \n",root->val);
		preorder(root->left);
		preorder(root->right);
	}

}

/* In order printing of tree */
void inorder(tree_node* root){
	if(root != NULL){
		inorder(root->left);
		printf("%d \n",root->val);
		inorder(root->right);
	}
}

