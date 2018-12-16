#include <stdio.h>

int div_2(int x) // generic function
{
	return (x%2) ? 0 : 1;
}

int *filter(int (*f)(int x), int *v, int size, int *qt)
{
	int i;
	int *a = (int *) malloc(sizeof(int));

	for (i = 0; i < size; ++i)
	{
		if((*f)(v[i])) // se for true
		{
			a[(*qt)] = v[i];
			(*qt)++;
			a = (int *) realloc(a, sizeof(int)*( (*qt)+1 ));
		}
	}
	return a;
}

int main()
{
	int *v = (int *) malloc(sizeof(int));
	int n, i=0, size=0;

	while(scanf("%d", &n) != EOF)
	{
		v[i] = n;
		i++;
		v = (int *) realloc(v, sizeof(int)*(i+1));
	}
	int *a = filter(div_2, v, i, &size);

	for (i = 0; i < size; ++i)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}
