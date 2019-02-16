#include <bits/stdc++.h>
#define MAX 101
const int inf = 1e9;

using namespace std;

vector<pair<int, int> > graph[MAX];
int cost[MAX];

int dijkstra(int source, int target)
{
	for (int i = 1; i < MAX; ++i) cost[i] = inf;
	priority_queue<pair<int, int> > pq; //nom default, vector<pair<int, int>>, greater<pair<int, int>>>;
	cost[source] = 0; pq.push({source, cost[source]});
	
	while(!pq.empty())
	{
		int u = pq.top().first; pq.pop();
		for (auto j : graph[u])
		{
			if(cost[u] + j.second < cost[j.first])
			{
				cost[j.first] = cost[u] + j.second;
				pq.push({j.first, cost[j.first]});
			}
		}
	}
	return cost[target];
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	int u, v, c;

	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &u,&v,&c);
		graph[u].push_back({v, c});
		graph[v].push_back({u, c});
	}
	printf("%d\n" ,dijkstra(1, n));

	return 0;
}
