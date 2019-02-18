#include <stdio.h>
#include <stdlib.h>
#define MAX 10

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

typedef struct graph
{
	node *vertices[MAX];
	short visited[MAX];
	int directed;
}graph;

node *create_node(int item)
{
	node *new_node = (node *) malloc(sizeof(node));
	new_node->item = item;
	new_node->next = NULL;
	return new_node;
}

queue *create_queue()
{
	queue *new_queue = (queue*) malloc(sizeof(queue));
	new_queue->head = NULL;
	new_queue->tail = NULL;
	return new_queue;
}

int is_empty(queue *queue)
{
    return(queue->head == NULL);
}

void free_queue(queue *queue)
{
	node *current = queue->head;
	while(current != NULL)
	{
		queue->head = queue->head->next;
		free(current);
		current = queue->head;
	}

	free(queue);
}

void enqueue(queue *queue, int item)
{
    node *new_node = (node *) malloc(sizeof(node));
	new_node->item = item;
	new_node->next = NULL;
	
	if(is_empty(queue))
	{
		queue->head = new_node;
		queue->tail = new_node;
	}
	else
	{
		queue->tail->next = new_node;
		queue->tail = new_node;
	}
}

int dequeue(queue *queue)
{
	node *current = queue->head;
	queue->head = queue->head->next;
	int x = (current->item);
	free(current);
	return x;
}

graph *create_graph()
{
	graph *new_graph = (graph*) malloc(sizeof(graph));
	new_graph->directed = 0;
	int i;
	for (i = 0; i < MAX; ++i)
	{
		new_graph->vertices[i] = NULL;
		new_graph->visited[i] = 0;
	}
	return new_graph;
}

void destruct(graph *graph)
{
	int i;
	node *current = NULL;
	for (i = 0; i < MAX; ++i)
	{
		if(graph->vertices[i] != NULL)
		{
			current = graph->vertices[i];
			while(current != NULL)
			{
				graph->vertices[i] = graph->vertices[i]->next;
				free(current);
				current = graph->vertices[i];
			}
		}
	}
	free(graph);
}

void add_edge(graph *graph, int vertex1, int vertex2)
{
	node* vertex = create_node(vertex2);
	vertex->next = graph->vertices[vertex1];
	graph->vertices[vertex1] = vertex;

	if(!graph->directed)
	{
		vertex = create_node(vertex1);
		vertex->next = graph->vertices[vertex2];
		graph->vertices[vertex2] = vertex;
	}
}

void dfs(graph *graph, int source)
{
	graph->visited[source] = 1;
	printf("%d\n", source);

	node *adj_list = graph->vertices[source];
	while(adj_list != NULL)
	{
		if(!graph->visited[adj_list->item])
		{
			dfs(graph, adj_list->item);
		}
		adj_list = adj_list->next;
	}
}

void bfs(graph *graph, int source)
{
	queue *queue = create_queue();
	int dequeued;
	node *adj_list = NULL;//graph->vertices[source];
	printf("%d\n", source);
	graph->visited[source] = 1;
	enqueue(queue, source);

	while(!is_empty(queue))
	{
		dequeued = dequeue(queue);
		adj_list = graph->vertices[dequeued];
		while(adj_list != NULL)
		{
			if(!graph->visited[adj_list->item])
			{
				printf("%d\n", adj_list->item);
				graph->visited[adj_list->item] = 1;
				enqueue(queue, adj_list->item);
			}
			adj_list = adj_list->next;
		}
	}
	free_queue(queue);
}

int main()
{
	graph *graph = create_graph();
	int n; scanf("%d", &n);

	while(n--)
	{
		int vertex1, vertex2; scanf("%d%d", &vertex1, &vertex2);
		add_edge(graph, vertex1, vertex2);
	}
	bfs(graph, 1);
	return 0;
}
