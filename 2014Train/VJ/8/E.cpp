#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

////////////////////////////////////////////////////////////

// couEdge=0;!!!

const int INF=10e8;
const int MaxN=110;
const int MaxM=10010;

struct Edge
{
	int u,v;
	double cost;
};

Edge E[MaxM];
int couEdge;
int fa[MaxN],id[MaxN],vis[MaxN];
double in[MaxN];

double ZhuLiu(int n,int root)
{
	double ret=0.0;
	int u,v;
	int m=couEdge;
	int couC;			// count the number of circle

	while(1)
	{
		for(int i=1;i<=n;++i)
			in[i]=INF;

		for(int i=0;i<m;++i)
			if(E[i].u != E[i].v && E[i].cost<in[E[i].v])			// care for self-circle
			{
				in[E[i].v]=E[i].cost;
				fa[E[i].v]=E[i].u;
			}

		for(int i=1;i<=n;++i)
			if(i!=root && in[i]==INF)
				return -1;					// no Directed-MST

		couC=0;		//
											// find circle
		for(int i=1;i<=n;++i)
			id[i]=vis[i]=-1;
		in[root]=0;

		for(int i=1;i<=n;++i)
		{
			ret+=in[i];
			v=i;

			while(vis[v]!=i && id[v]==-1 && v!=root)
			{
				vis[v]=i;
				v=fa[v];
			}

			if(v!=root && id[v]==-1)
			{
				++couC;
				
				for(u=fa[v];u!=v;u=fa[u])
					id[u]=couC;
				
				id[v]=couC;
			}
		}

		if(couC==0)
			break;

		for(int i=1;i<=n;++i)
			if(id[i]==-1)
				id[i]=++couC;

		for(int i=0;i<m;)		//
		{
			v=E[i].v;

			E[i].v=id[E[i].v];
			E[i].u=id[E[i].u];

			if(E[i].v!=E[i].u)
				E[i++].cost-=in[v];
			else
				swap(E[i],E[--m]);
		}

		n=couC;
		root=id[root];
	}

	return ret;
}

void addEdge(int u,int v,double cost)
{
	E[couEdge].u=u;
	E[couEdge].v=v;
	E[couEdge].cost=cost;
	++couEdge;
}

////////////////////////////////////////////////////////////

int X[MaxN],Y[MaxN];

int main()
{
	int n,m;
	int a,b;

	while(~scanf("%d %d",&n,&m))
	{
		couEdge=0;

		for(int i=1;i<=n;++i)
			scanf("%d %d",&X[i],&Y[i]);

		for(int i=0;i<m;++i)
		{
			scanf("%d %d",&a,&b);

			addEdge(a,b,sqrt(double(X[a]-X[b])*(X[a]-X[b])+double(Y[a]-Y[b])*(Y[a]-Y[b])));
		}

		double ans=ZhuLiu(n,1);

		if(fabs(ans+1.0)<0.0000001)
			printf("poor snoopy\n");
		else
			printf("%.2f\n",ans);
	}

	return 0;
}
