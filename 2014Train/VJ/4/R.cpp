#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
	
using namespace std;

const int MaxN=400;
const int INF=10e8;

void Dijkstra(int cost[][MaxN],int lowcost[],int N,int start)
{
	priority_queue <int> que;
	int t;

	for(int i=1;i<=N;++i)
		lowcost[i]=INF;

	que.push(start);

	while(!que.empty())
	{
		t=que.top();
		que.pop();

		for(int i=1;i<=N;++i)
			if(i!=t)
				if(lowcost[t]==INF || lowcost[i]>lowcost[t]+cost[t][i])
				{
					lowcost[i]=(lowcost[t]==INF ? 0 : lowcost[t])+cost[t][i];
					que.push(i);
				}
	}
}

int map1[MaxN][MaxN];
int ans[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	int t1,t2;

	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				scanf("%d",&map1[i][j]);

		Dijkstra(map1,ans,N,1);
		t1=ans[N];
		t2=ans[1];

		Dijkstra(map1,ans,N,N);
		t2+=ans[N];

		printf("%d\n",min(t1,t2));
	}
	
	return 0;
}
