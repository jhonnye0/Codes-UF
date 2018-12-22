// fib DP
#include <bits/stdc++.h>

#define MAX 1000000

using namespace std;

int n, dp[MAX];

int fib(int x)
{
	if(dp[x]!=-1) return dp[x];

	dp[x] = fib(x-1) + fib(x-2);

	return dp[x];
}

int main()
{
	while(cin >> n) // scaneio
    	{
    		memset(dp, -1, sizeof(dp)); //faço todos iguais a -1
    
    		dp[0] = 0; // caso base
    		dp[1] = 1;
    
    		cout << fib(n) << endl; // imprimo o valor
   	}
	return 0;
}
