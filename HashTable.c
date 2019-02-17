#include <stdio.h>
#include <stdlib.h>
const int MAX = 5;

typedef struct element
{
	int key;
	int value;
	struct element *next;
}element;

typedef struct hash
{
	int size;
	element **table;
}hash;

hash *create_hash()
{
	int i;
	hash *new_hash = (hash *) malloc(sizeof(hash));
	new_hash->table = (element **) malloc(sizeof(element *) * MAX);
	
	for (i = 0; i < MAX; ++i)
	{
		new_hash->table[i] = NULL;
	}
	new_hash->size = MAX;

	return new_hash;
}

element *create_element(int key, int value)
{
	element *new_element = (element *) malloc(sizeof(element));
	new_element->key = key;
	new_element->value = value;
	new_element->next = NULL;
	return new_element;
}

void print_hash(hash *hashtable)
{
	int i;
	for (i = 0; i < MAX; ++i)
	{
		if(hashtable->table[i] != NULL)
		{
			printf("I: %d\n", i);
			element *current = hashtable->table[i];
			while(current != NULL)
			{
				(current->next != NULL)? 
				printf("%d ", current->value):
				printf("%d\n", current->value);
				current = current->next;
			}
		}
	}
}

void destruct(hash* hash)
{
	int i;
	element *current = NULL;
	for (i = 0; i < MAX; ++i)
	{
		if(hash->table[i] != NULL)
		{
			current = hash->table[i];
			while(current != NULL)
			{
				hash->table[i] = current->next;
				free(current);
				current = hash->table[i];
			}
		}
	}
	free(hash->table);
	free(hash);
}

int hashing(int key)
{
	return (key) % MAX;
}

void put(hash *hashtable, int key, int value)
{
	int k = hashing(key);

	if(hashtable->table[k] != NULL)
	{
		element *ant = NULL;
		element *current = hashtable->table[k];
		while(current != NULL)
		{
			if(current->key == key)
			{
				current->value = value;
				break;
			}
			ant = current;
			current = current->next;
		}
		if(current == NULL)
		{
			element *new = create_element(key, value);
			ant->next = new;
		}
	}
	else
	{
		element *new = create_element(key, value); 
		new->next = hashtable->table[k];
		hashtable->table[k] = new;
	}
}

int get(hash *hashtable, int key)
{
	int k = hashing(key);
	if(hashtable->table[k] != NULL)
	{
		element *current = hashtable->table[k];
		while(current != NULL)
		{
			if (current->key == key)
			{
				return current->value;
			}
			current = current->next;
		}
	}
	return -1;
}

void remove_element(hash *hashtable, int key)
{
	int k = hashing(key);
	if(hashtable->table[k] != NULL)
	{
		element *current = hashtable->table[k];
		if(current->key == key)
		{
			hashtable->table[k] = hashtable->table[k]->next;
		}
		else
		{
			element *previous = NULL;
			while(current != NULL)
			{
				if (current->key == key)
				{
					break;
				}
				previous = current;
				current = current->next;
			}
			if(current != NULL)
			{
			    previous->next = current->next;
			}
		}
		free(current);
		return;
	}
}

int main()
{
	hash *hashtable = create_hash();
	int n, i; scanf("%d", &n);

	while(n--)
	{
		int value, key; scanf("%d%d", &value, &key);
		put(hashtable, key, value);
	}
	printf("Get: %d\n", get(hashtable, 2));
	remove_element(hashtable, 7);
	print_hash(hashtable);
	destruct(hashtable);
}
