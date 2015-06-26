#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int INF=10e8;
const int MaxN=110;
const int MaxM=MaxN*MaxN;

struct Edge
{
	int u,v,cost;

	bool operator < (const Edge &a) const
	{
		return cost<a.cost;
	}
};

Edge E[MaxM];			// !!!
int couEdge;
int fa[MaxN];

int find(int x)
{
	if(fa[x]==-1)			// !!!
		return x;

	fa[x]=find(fa[x]);

	return fa[x];
}

int Kruskal(int n)
{
	int ans=0;
	int cou=0;
	int u,v,cost,t1,t2;

	memset(fa,-1,sizeof(fa));
	sort(E,E+couEdge);

	for(int i=0;i<couEdge;++i)
	{
		u=E[i].u;
		v=E[i].v;
		cost=E[i].cost;

		t1=find(u);
		t2=find(v);

		if(t1!=t2)
		{
			ans+=cost;
			fa[t1]=t2;
			++cou;
		}

		if(cou==n-1)
			break;
	}

	if(cou<n-1)
		return -1;

	return ans;
}

void addEdge(int u,int v,int c)
{
	E[couEdge].u=u;
	E[couEdge].v=v;
	E[couEdge++].cost=c;
}

int main()
{
	int c,N;

	while(~scanf("%d",&N))
	{
		couEdge=0;

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
			{
				scanf("%d",&c);
				
				if(i!=j)
					addEdge(i,j,c);
			}

		printf("%d\n",Kruskal(N));
	}

	return 0;
}
