#include <stdio.h>

int prime(int x) // generic function
{
    int i, sqr = sqrt(x);
    
    if(x == 1 || x == 0) return 0;
    
	for(i=2; i<=sqr; i++)
	{
	    if(x%i == 0) return 0;
	}
	return 1;
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
	int *a = filter(prime, v, i, &size);

	for (i = 0; i < size; ++i)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}
