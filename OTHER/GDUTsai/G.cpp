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

const int MaxN=1010;

vector <int> E[MaxN];
int fa[MaxN];
bool vis[MaxN];

void BFS(int s)
{
	memset(vis,0,sizeof(vis));

	int t,len;
	queue <int> que;

	que.push(s);
	vis[s]=1;
	fa[s]=-1;

	while(!que.empty())
	{
		t=que.front();
		que.pop();
		
		len=E[t].size();

		for(int i=0;i<len;++i)
			if(!vis[E[t][i]])
			{
				vis[E[t][i]]=1;
				que.push(E[t][i]);
				fa[E[t][i]]=t;
			}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopena("out.txt","w",stdout);
	
	int T;
	int S,N;
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&S);

		for(int i=1;i<=N;++i)
			E[i].clear();

		for(int i=1;i<=N-1;++i)
		{
			scanf("%d %d",&a,&b);
			E[a].push_back(b);
			E[b].push_back(a);
		}

		BFS(S);

		printf("%d",fa[1]);
		for(int i=2;i<=N;++i)
			printf(" %d",fa[i]);

		printf("\n");
	}

	return 0;
}
