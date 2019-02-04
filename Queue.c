#include <stdio.h>

typedef struct node
{
	int item;
	struct node *next;
}node;

typedef struct queue
{
	node *head;
	node *tail;
}queue;

queue *create_queue()
{
	queue *new_queue = (queue *) malloc(sizeof(queue));
	new_queue->head = NULL;
	return new_queue;
}

int is_empty(queue *queue)
{
    return(queue->head == NULL);
}

void enqueue(queue *queue, int item)
{
	if(is_empty(queue))
	{
	    queue->head = (node *) malloc(sizeof(node));
	    queue->tail = (node *) malloc(sizeof(node));

		queue->head->item = item;
		queue->head->next = NULL;
		queue->tail = queue->head;
	}
	else
	{
	    node *new_node = (node *) malloc(sizeof(node));
		new_node->item = item;
		new_node->next = NULL;
		queue->tail->next = new_node;
		queue->tail = new_node;
	}
}

void dequeue(queue *queue)
{
	node *current = queue->head;
	queue->head = queue->head->next;
	printf("%d\n", current->item);
	free(current);
}

int main()
{
	queue *queue = create_queue();
	int item;

	while(scanf("%d", &item) != EOF)
	{
		enqueue(queue, item);
	}
    dequeue(queue);
    
	return 0;
}
