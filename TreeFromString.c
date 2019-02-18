#include <stdio.h>
#include <string.h>

typedef struct binary_tree
{
	int item;
	struct binary_tree *left;
	struct binary_tree *right;
}b_tree;

typedef struct node
{
	int item;
	struct node *next;
}node;

typedef struct stack
{
	struct node *top;
}stack;

b_tree *create_b_tree(int item)
{
	b_tree *new_tree = (b_tree *) malloc(sizeof(b_tree));
	new_tree->item = item;
	new_tree->left = new_tree->right = NULL;
	return new_tree; 
}

void free_tree(b_tree *tree)
{
	if(tree == NULL)
		return;
	free_tree(tree->left);
	free_tree(tree->right);
	free(tree);
}

stack *create_stack()
{
	stack *new_stack = (stack *) malloc(sizeof(stack));
	new_stack->top = NULL;
	return new_stack;
}

void push(stack *stack, int item)
{
	node *new_top = (node *) malloc(sizeof(node));
	new_top->item = item;
	new_top->next = stack->top;
	stack->top = new_top;
}

int is_empty(stack *stack)
{
	return (stack->top == NULL);
}

int pop(stack *stack)
{
	if(is_empty(stack))
	{
		printf("Stack underflow\n");
		return -1;
	}
	else
	{
		node *current = stack->top;
		stack->top = stack->top->next;
		current->next = NULL;
		int x = current->item;
		free(current);
		return x;
	}
}

int peek(stack *stack)
{
	if(is_empty(stack))
	{
		printf("Stack underflow\n");
		return -1;
	}
	else return stack->top->item;
}

void preOrder(b_tree* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->item); 
    preOrder(node->left); 
    preOrder(node->right); 
} 

int findIndex(char str[], int in, int fn)
{
	int i;
	if(in > fn)
		return -1;

	if(str[in] == ' ') in++;
	
	stack* stack = create_stack();

	for (i = in; i <= fn; ++i)
	{
		if(str[i] == '(')
		{
			push(stack , str[i]);
		}
		else if(str[i] == ')')
		{
			if(peek(stack) == '(')
			{
				pop(stack);
			}
			if (is_empty(stack))
			{
				return i;
			}
		}
	}
	return -1;
}

b_tree *treeFromString(char str[], int in, int fn)
{
	if(in > fn)
		return NULL;

	int num, x, index = -1; num = x = 1;
	char aux[10];

	while(in + x <= in && str[in + x] == '(')
	{
		printf("%c\n", str[in + x]);
		aux[x] = str[in+x];
		x++;
	}
	num = atoi(aux);
	b_tree *root = create_b_tree(num);

	if(in+x <= fn && str[in+x] == '(')
	{
		index = findIndex(str, in+x, fn);
	}
	if (index != -1)
	{
		root->left = treeFromString(str, in+x, index-1);
		root->right = treeFromString(str, index+2, fn-1);
	}
	return root;
}

int main()
{
	char string[1000]; getchar();
	gets(string); int lenght = strlen(string);
	b_tree *tree = treeFromString(string, 0 , lenght-2);

	//preOrder(tree);
	free_tree(tree);
	return 0;
}
