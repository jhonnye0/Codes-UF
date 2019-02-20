#include <stdio.h>

typedef struct binary_tree
{
	int item;
	int h;
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

int is_balanced(b_tree *tree)
{
	int bf = h(tree->left) - h(tree->right);
	return ((-1 <=bf) && (bf <=1));
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

int h(b_tree *tree)
{
	if (tree == NULL){
		return -1;
	}else{
		return 1 + max(h(tree->left), h(tree->right));
	}
}

int b_factor(b_tree *tree)
{
	if (tree == NULL){
		return 0;
	}else if ((tree->left != NULL) && (tree->right != NULL)){
		return (tree->left->h - tree->right->h);
	}else if((tree->left != NULL) && (tree->right == NULL)){
		return (1 + tree->left->h);
	}else{
		return (-tree->right->h -1);
	}
}

b_tree *rotate_left(b_tree *tree)
{
	b_tree *aux = NULL;
	if (tree != NULL && tree->right != NULL){
		aux = tree->right;
		tree->right = aux->left;
		aux->left = tree;
	}
	
	aux->h = h(aux);
	tree->h = h(tree);
	return aux;
}

b_tree *rotate_right(b_tree *tree)
{
	b_tree *aux = NULL;
	if (tree != NULL && tree->left != NULL){
		aux = tree->left;
		tree->left = aux->right;
		aux->right = tree;
	}

	aux->h = h(aux);
	tree->h = h(tree);
	return aux;
}

b_tree *add(b_tree *tree, int item)
{
	if(tree == NULL){
		return create_b_tree(item);
	}else if(tree->item > item){
		tree->left = add(tree->left, item);
	}else{
		tree->right = add(tree->right, item);
	}

	tree->h = h(tree);
	b_tree* child;

	if (b_factor(tree) == 2 || b_factor(tree) == -2){
		if(b_factor(tree) == 2){
			child = tree->left;
			if(b_factor(child) == -1){
				tree->left = rotate_left(child);
			}
			tree = rotate_right(tree);
		}else if (b_factor(tree) == -2){
			child = tree->right;
			if(b_factor(child) == 1){
				tree->right = rotate_right(child);
			}
			tree = rotate_left(tree);
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

int main()
{
	b_tree *tree = create_empty_b();
	int n;
	while(scanf("%d", &n) != EOF){
		tree = add(tree, n);
	}

	printOrder(tree);
	free_tree(tree);
	return 0;
}
