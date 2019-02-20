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
	if(tree == NULL)
	{
		tree = create_b_tree(item); 
	}
	else
	{
		if(item >= tree->item){
			tree->right = insert(tree->right, item);
		}
		else{
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
	printf("(");
	if (tree != NULL)
	{
		printf(" %d ", tree->item);
		printOrder(tree->left);
		printOrder(tree->right);
	}
	printf(") ");
} 

b_tree *remove_atual(b_tree *node)
{
	b_tree *ant, *aux = NULL;
	if(node->left == NULL)
	{
		aux = node->right;
		free(node);
	return aux;
	}
	ant = node;
	aux = node->left;
	while(aux->right != NULL){
		ant = aux;
		aux = aux->right;
	}

	if(ant != node){
		ant->right = aux->left;
		aux->left = node->left;
	}
	aux->right = node->right;
	free(node);
	return aux;
}

void remove_node(b_tree *tree, int item)
{
	if(tree == NULL) return;

	b_tree *ant = NULL;
	b_tree *atual = tree;

	while(atual != NULL){
		if(item == atual->item){
			if(atual == tree){
				tree = remove_atual(atual);
			}else{
				if(ant->right == atual){
					ant->right = remove_atual(atual);
				}else{
					ant->left = remove_atual(atual);
				}
			}	
		}
		ant = atual;	
		if(item >= atual->item){
			atual = atual->right;
		}else{
			atual = atual->left;
		}
	} 
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
