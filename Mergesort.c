#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int *v, int in, int fn, int mid)
{
	int n1, n2, i, j, k;    
	n1 = (mid - in)+1;
	n2 = (fn - mid);

	int L[n1+1], R[n2+1];
	for (i = 0; i < n1; ++i)
	{
		L[i] = v[in + i];
	}
	for (i = 0; i < n2; ++i)
	{
		R[i] = v[mid + i + 1];
	} 
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	for (i=j=0, k=in; k <= fn; k++)
	{
	  	if(L[i] <= R[j])
	  	{
	  		v[k] = L[i];
	  		i++;
	  	}
	  	else
	  	{
	  		v[k] = R[j];
	  		j++;
	  	}
	}  
}

void mergesort(int *v, int in , int fn)
{
	if(in < fn)
	{
	    int mid = in+(fn-in)/2;
	    mergesort(v, in , mid);
	    mergesort(v, mid+1, fn);
	    merge(v, in, fn, mid);
	}	
}

int main()
{
	int *v = (int *) malloc(sizeof(int));
	int n, i=0;
	
	while(scanf("%d", &n) != EOF)
	{		
		v[i] = n;
		v = (int *) realloc(v, sizeof(int)*(i+2));
		i++;
		
	}
	int size = i;
	mergesort(v, 0, size-1);

	for (i = 0; i < size; ++i)
	{
		(i==size-1) ? printf("%d\n", v[i]) : printf("%d ", v[i]);
	}
	return 0;
}
