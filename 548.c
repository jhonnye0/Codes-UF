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
	int item, i=1;
	char c;
			
	while(i)
	{

	    scanf("%d%c", &item, &c);
	    printf("%d\n", item);
	    if(c == '\n') break;			    			    
	}
}

int main()
{
	stack *stack = create_stack();
	while(1)
	{
		char op[10];
		memset(op, 0, sizeof(op));
		scanf("%s", op);
		
		if(strlen(op) == 0)
		{   
		    free(stack);
		    return 0;
		}

		if(!strcmp(op, "PUSH"))
		{
			puts(op);			
		 	//node *new_list = catch_list();
		 	//stack = push(stack, )
		}
		else
		{
			puts(op);
		}
	}
}
