#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int item;
	struct node *next;
	struct node *down;
}node;

typedef struct stack
{
	node *top;
}stack;

stack *create_stack()
{
	stack *new_stack = (stack*) malloc(sizeof(stack));
	new_stack->top = NULL;
	return new_stack;
}

node *catch_list()
{
	int item;
	char c;
	node *tail = NULL;
	node *head = NULL;
			
	while(1)
	{
		scanf("%d%c", &item, &c);
		node *new_node = (node *) malloc(sizeof(node));
		new_node->item = item;
		new_node->down = NULL;
		new_node->next = NULL;

		if(head == NULL)
		{
			head = new_node;
		 	tail = head;
		}
		else
		{
		 	tail->next = new_node;
		 	tail = new_node;
		}
	    if(c == '\n') break;			    			    
	}
	return head;
}

void push(stack *stack, node *new_list)
{
	new_list->down = stack->top;
	stack->top = new_list;
}

int is_empty(stack *stack)
{
	return (stack->top == NULL);
}

void pop(stack *stack)
{
	if(is_empty(stack))
	{
		printf("EMPTY STACK\n");
		return;
	}
	else
	{
		node *current = stack->top;
		stack->top = stack->top->down;
		print__free_list(current);
	}
	return;
}

void print__free_list(node *list)
{	
	while(list != NULL)
	{
		node *current = list;
		if(current->next != NULL)
		{
			printf("%d ", current->item);
		} else {
			printf("%d\n", current->item);
			}
		free(current);
		list = list->next;
	}
}

void main()
{
	stack *stack = create_stack();
	while(1)
	{
		char op[10];
		memset(op, 0, sizeof(op));
		
		if(scanf("%s", op) == EOF)
		{   
		    free(stack);
		    return;
		}
		if(!strcmp(op, "PUSH"))
		{			
		 	node *new_list = catch_list();
		 	push(stack, new_list);
		}
		else
		{
			pop(stack);			
		}
	}
}
