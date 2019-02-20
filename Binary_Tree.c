#include <stdio.h>
#include <string.h>

typedef struct binary_tree
{
	int item;
	struct binary_tree *left;
	struct binary_tree *right;
}b_tree;

b_tree *create_b_tree(int item)
{
	b_tree *new_tree = (b_tree *) malloc(sizeof(b_tree));
	new_tree->item = item;
	new_tree->left = new_tree->right = NULL;	
	return new_tree; 
}
b_tree *create_empty_b()
{
	return NULL;
}

b_tree *insert(b_tree *tree, int item)
{	 
	if(tree == NULL){
		tree = create_b_tree(item); 
	}else{
		if(item >= tree->item){
			tree->right = insert(tree->right, item);
		}else{
			tree->left = insert(tree->left, item);
		}
	}
	return tree;
}

void free_tree(b_tree *tree)
{
	if(tree == NULL)
		return;
	free_tree(tree->left);
	free_tree(tree->right);
	free(tree);
}


void printOrder(b_tree* tree)
{ 
	if(tree == NULL) return;
	else{
		printf(" %d ", tree->item);
		printOrder(tree->left);
		printOrder(tree->right);
	}
} 

b_tree *minTree(b_tree *node)
{
	b_tree* current = node;
	while(current->left != NULL){
		current = current->left;
	}
	return current;
}

b_tree *remove_node(b_tree *tree, int item)
{
	if(tree == NULL){
		return tree;
	} 

	if(item < tree->item){
		tree->left = remove_node(tree->left, item);
	}else if(item > tree->item){
		tree->right = remove_node(tree->right, item);
	}else{
		b_tree *temp;
		if(tree->left == NULL){
			temp = tree->right;
			free(tree);
			return temp;
		}else if(tree->right == NULL){
			temp = tree->left;
			free(tree);
			return temp;
		}
		temp = minTree(tree->right);
		tree->item = temp->item;
		tree->right = remove_node(tree->right, temp->item);
	}
	return tree;
}
int main()
{
	b_tree *tree = create_empty_b();
	int n;
	while(scanf("%d", &n) != EOF)
	{
		tree = insert(tree, n);		
	}

	remove_node(tree, 15);
	printOrder(tree);
	free_tree(tree);
	return 0;
}
