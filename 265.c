#include <stdio.h>

typedef struct node 
{
	char letter;
	int freq;
}node;

void nular(node **reffer)
{
	int i;
	for (i = 0; i < 256; ++i)
	{
		reffer[i] = NULL;
	}	
}

void add(node **reffer, char letter)
{	
	if(reffer[letter] == NULL)
	{
		reffer[letter] = (node *) malloc(sizeof(node));
		reffer[letter]->letter = letter;
		reffer[letter]->freq++;
	}
	else
	{
		reffer[letter]->freq++;
	}
}

void free_list(node **reffer)
{
	int i;
	for (i = 0; i < 256; ++i)
	{
		if(reffer[i] != NULL)
		{
			free(reffer[i]);
		}
	}
	free(reffer);
}

void print_list(node **list)
{
	int i;
	for(i=255; i>=0; i--)
	{
		if (list[i] != NULL)
		{
			printf("%c %d\n", list[i]->letter, list[i]->freq);
		}
	}
}

int main()
{
	node **list = (node **)malloc(256*sizeof(node *));
	nular(list);

	char letter;

	while(scanf("%c", &letter) != EOF)
	{
		add(list, letter);
		//printf("%c\n", letter);
	}
	print_list(list);
	free_list(list);

	return 0;
}
