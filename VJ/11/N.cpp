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

const int MaxN=2010;
const int MaxM=50000;
const int INF=10e8;

struct Edge
{
	int to,next,cap,flow;
};

Edge E[MaxM];
int Ecou;
int head[MaxN];
int gap[MaxN],dis[MaxN],pre[MaxN],cur[MaxN];
int S,T;

void init(int N,int _S,int _T)
{
	S=_S;
	T=_T;
	Ecou=0;

	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		gap[i]=dis[i]=0;
	}
}

void addEdge(int u,int v,int c,int rc=0)		// 单向边三个参数，双向边四个。
{
	//cout<<u<<' '<<v<<' '<<c<<endl;
	E[Ecou].to=v;
	E[Ecou].cap=c;
	E[Ecou].flow=0;
	E[Ecou].next=head[u];
	head[u]=Ecou++;

	E[Ecou].to=u;
	E[Ecou].cap=rc;
	E[Ecou].flow=0;
	E[Ecou].next=head[v];
	head[v]=Ecou++;
}

void update(int remm)
{
	int u=T;

	while(u!=S)
	{
		E[pre[u]].flow+=remm;
		E[pre[u]^1].flow-=remm;

		u=E[pre[u]^1].to;
	}
}

int SAP(int N)
{
	for(int i=1;i<=N;++i)
		cur[i]=head[i];				/////

	int u,v,ret=0,remm=INF,mindis;
	
	u=S;
	pre[S]=-1;
	gap[0]=N;

	while(dis[S]<N)
	{
		loop:
		for(int i=cur[u];i!=-1;i=E[i].next)
		{
			v=E[i].to;

			if(E[i].cap-E[i].flow && dis[u]==dis[v]+1)	//!!!
			{
				pre[v]=i;
				cur[u]=i;
				u=v;

				if(u==T)
				{
					for(int i=pre[u];i!=-1;i=pre[E[i^1].to])
						remm=min(remm,E[i].cap-E[i].flow);
					ret+=remm;
					update(remm);
					u=S;				// ???
					remm=INF;
				}

				goto loop;
			}
		}

		mindis=N-1;

		for(int i=head[u];i!=-1;i=E[i].next)
			if(E[i].cap-E[i].flow && mindis>dis[E[i].to])
			{
				cur[u]=i;
				mindis=dis[E[i].to];
			}
		
		if(--gap[dis[u]]==0)
			break;

		dis[u]=mindis+1;
		++gap[dis[u]];

		if(u!=S)
			u=E[pre[u]^1].to;
	}

	return ret;
}

void init1(int N,int mid)
{
	for(int i=1;i<=N;++i)
		dis[i]=gap[i]=0;
	gap[0]=N;

	for(int u=1;u<=N;++u)
		for(int i=head[u];i!=-1;i=E[i].next)
			E[i].flow=0;

	for(int i=head[S];i!=-1;i=E[i].next)
		E[i].cap=mid;

	for(int i=head[T];i!=-1;i=E[i].next)
		E[i^1].cap=mid;
}

vector <int> jilu[MaxN];
int fa[MaxN];
bool map1[MaxN][MaxN];

int find(int x)
{
	if(fa[x]==-1)
		return x;

	fa[x]=find(fa[x]);

	return fa[x];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int n,m,f;
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d",&n,&m,&f);

		init(2*n+2,2*n+1,2*n+2);

		memset(map1,0,sizeof(map1));

		for(int i=1;i<=n;++i)
		{
			addEdge(2*n+1,i,1);
			addEdge(n+i,2*n+2,INF);
		}

		for(int i=1;i<=n;++i)
		{
			jilu[i].clear();
			fa[i]=-1;
		}

		while(m--)
		{
			scanf("%d %d",&a,&b);

			jilu[a].push_back(b);
		}

		while(f--)
		{
			scanf("%d %d",&a,&b);

			if(find(a)!=find(b))
				fa[find(a)]=find(b);
		}

		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				if(find(i)==find(j))
				{
					a=jilu[j].size();

					for(int k=0;k<a;++k)
						if(map1[i][jilu[j][k]]==0)
						{
							addEdge(i,n+jilu[j][k],1);
							map1[i][jilu[j][k]]=1;
						}
				}
		}

		int L=0,R=n,mid;

		while(R>L)
		{
			mid=(L+R)/2+1;

			init1(2*n+2,mid);

			a=SAP(2*n+2);

			if(a==mid*n)
				L=mid;
			else
				R=mid-1;
		}

	//	if(ans>n)
	//		while(1)
	//			printf("asfsaf");

		printf("%d\n",L);
	}
	
	return 0;
}
