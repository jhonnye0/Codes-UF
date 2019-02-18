#include <stdio.h>
#define MAX 10

// INCOMPLETE........

typedef struct node
{
	int	item;
	struct node *next;
}node;

typedef struct tree
{
	node *adj[MAX];
	short visited[MAX];
}tree;

node *create_node(int item)
{
	node *new_node = (node*) malloc(sizeof(node));
	new_node->item = item;
	new_node->next = NULL;
	return new_node;
}

tree *create_tree()
{
	int i;
	tree *new_tree = (tree *) malloc(sizeof(tree));
	return new_tree;
}

void destruct(tree *tree)
{
	int i;
	node *current = NULL;
	for (i = 0; i < MAX; ++i)
	{
		if(tree->adj[i] != NULL)
		{
			current = tree->adj[i];
			while(current != NULL)
			{
				tree->adj[i] = tree->adj[i]->next;
				free(current);
				current = tree->adj[i];
			}
		}
	}
	free(tree);
}

node *create_list(int qt)
{
	int num, i;
	node *head = NULL;
	node *tail = NULL;

	for (i = 0; i < qt; ++i)
	{
		scanf("%d", &num);
		if(head == NULL)
		{
			head = create_node(num);
			tail = head;
		}		
		else
		{
			tail->next = create_node(num);
			tail = create_node;
		} 
	}
	return head;
}

void add_node(tree *tree, int source, node *list)
{
	tree->adj[source] = list;
}

void dfs(tree *tree, int source)
{
	if(source == -1) return;
	printf("%d\n", source);

	node *adj = tree->adj[source];
	while(adj != NULL)
	{
		dfs(tree, adj->item);
		adj = adj->next;
	}
}

void print_post_order(tree *tree, int source)
{
	if(source == -1) return;
	node *adj = tree->adj[source];
	
	while(adj != NULL)
	{
		print_post_order(tree, adj->item);	    
		adj = adj->next;		
	}
	printf("SOURCE: %d\n", source);		
}
//----------------
void print_pre_order(tree *tree, int source)
{
	//---------------- INCOMPLETE;
	if(source == -1) return;
	node *adj = tree->adj[source];
	printf("SOURCE: %d\n", source);	
	while(adj != NULL)
	{
		print_post_order(tree, adj->item);	    
		adj = adj->next;		
	}	
}

void printa(tree *tree)
{
	int i;
	node *current;
	for (i = 0; i < MAX; ++i)
	{
		if(tree->adj[i] != NULL)
		{
		    printf("I: %d\n", i);
			current = tree->adj[i];
			while(current != NULL)
			{
				printf("%d\n", current->item);
				current = current->next;
			}
		} 
	}
}

int main()
{
	tree *tree = create_tree();
	int n, i; scanf("%d", &n);

	// Scan n nodes, each node have a qt of adj-nodes to put in a list..
	// example 1 3 2 3 4
	// node 1 have 3 adj-nodes: 2, 3 and 4;
	while(n--)
	{
		int source, qt;
		scanf("%d%d", &source, &qt);
		add_node(tree, source, create_list(qt));
	}
	printa(tree);
	print_post_order(tree, 1);
	dfs(tree, 1);
	destruct(tree);
	return 0;
}
