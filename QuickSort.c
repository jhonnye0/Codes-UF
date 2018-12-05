#include <stdio.h>
#include <stdlib.h>

void quick(int *v, int in, int fn)
{
	if((fn-in)<=1) return;
	
	int a,b,pivot,aux;
	a = in;
	b = fn-1;
	pivot = v[(in + fn)/2];

	while(a<=b)
	{
		while(v[a] < pivot && a < fn) a++;
		while(v[b] > pivot && b > in) b--;

		if(a<=b)
		{
			int aux = v[a];
			v[a] = v[b];
			v[b] = aux;
			a++;
			b--;
		}
	}
	quick(v, in, b+1);
	quick(v, a, fn);
}

int main()
{
	int n=0, i;
	int *v = (int *) malloc(sizeof(int));

	scanf("%d", &n);
	for (i = 0; n != -1 ; ++i)
	{
		v[i] = n;
		v = (int *) realloc(v, sizeof(int)*(i+2));
		scanf("%d", &n);
	}
	int size = i;

	quick(v, 0, size);

	for (i = 0; i < size; ++i)
	{
		printf("%d\n", v[i]);
	}

	return 0;
}
