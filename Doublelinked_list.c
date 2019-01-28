#include <stdio.h>

typedef struct node
{
	int item;
	struct node *next;
	struct node *previous;
}node;

node *create_d_list()
{
	return NULL;
}

node *add(node *head, int item)
{
	node *new_node = (node *) malloc(sizeof(node));
	new_node->item = item;
	new_node->next = head;
	new_node->previous = NULL;
	if(head != NULL)
	{
		head->previous = new_node;
	}

	return new_node;
}

node *remove_from_list(node *head, int item)
{
	node *current = head;
	while(current != NULL || current->item != item)
	{
		current = current->next;
	}

	if(head == current)
	{
		head = current->next;
	}
	else
	{
		current->previous->next = current->next;
	}

	if(current->next != NULL)
	{
		current->next->previous = current->previous;
	}
	free(current);
	return head;
}

node *search(node *head, int item)
{
	node *current = head;
	while(current != NULL || current->item != item)
	{
		current = current->next;
	}
	return current;
}

void print_d_list(node *head)
{
	while(head != NULL)
	{
		printf("%d ", head->item);
		head = head->next;
	}
}

void print_invert(node *head)
{
	node *current = head;
	while(current->next != NULL)
	{
		current = current->next;
	}

	while(current != head)
	{
		printf("%d ", current->item);
		current = current->previous;
	}

	printf("%d\n", head->item);
}

int main()
{
	node *h = create_d_list();
	int item; scanf("%d", &item);

	while(item != -1)
	{
		h = add(h, item);
		scanf("%d", &item);
	}

	print_d_list(h);
	printf("\n");

	print_invert(h);

	return 0;
}
