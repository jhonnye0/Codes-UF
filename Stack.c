#include <stdio.h>

typedef struct node
{
	int item;
	struct node *next;
}node;

typedef struct stack
{
	struct node *top;
}stack;

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

void print_stack(stack *stack)
{
	node *current = stack->top;
	while(current != NULL)
	{
		printf("%d\n", current->item);
		current = current->next;
	}
}

void free_stack(stack *stack)
{
	node *current = stack->top;

	while(current != NULL)
	{
		stack->top = stack->top->next;
		free(current);
		current = stack->top;
	}	
}

int main()
{
	stack *st = create_stack();
	int item;
	while(scanf("%d", &item) != EOF)
	{
		push(st, item);
	}
	print_stack(st);

	free_stack(st);
	return 0;
}
