#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>

using namespace std;

const int INF=10e8;
const int MaxN=40;

struct Edge
{
	int v;
	double cost;

	Edge(int _v=0,double _cost=0):v(_v),cost(_cost) {}
};

vector <Edge> E[MaxN];
bool vis[MaxN];
int couNode[MaxN];

bool SPFA(double lowcost[],int n,int start)
{
	queue <int> que;
	int u,v;
	double c;
	int len;

	for(int i=1;i<=n;++i)
	{
		vis[i]=0;
		couNode[i]=0;
		lowcost[i]=0;
	}

	vis[start]=1;
	couNode[start]=1;
	lowcost[start]=1;

	que.push(start);

	while(!que.empty())
	{
		u=que.front();
		que.pop();

		vis[u]=0;
		len=E[u].size();

		for(int i=0;i<len;++i)
		{
			v=E[u][i].v;
			c=E[u][i].cost;

			if(lowcost[u]*c>lowcost[v])
			{
				lowcost[v]=lowcost[u]*c;

				if(!vis[v])
				{
					vis[v]=1;
					++couNode[v];
					que.push(v);

					if(couNode[v]>=n)
						return 0;
				}
			}
		}
	}

	return 1;
}

inline void addEdge(int u,int v,double c)
{
	E[u].push_back(Edge(v,c));
}

char ss[40][100];
double ans[MaxN];
int N;

int find(char *s)
{
	for(int i=1;i<=N;++i)
		if(strcmp(s,ss[i])==0)
			return i;
}

int main()
{
	int M;
	bool ok;
	char ts1[100],ts2[100];
	int t1,t2;
	double tr;
	int cas=1;

	for(scanf("%d",&N);N;scanf("%d",&N),++cas)
	{
		for(int i=1;i<=N;++i)
		{
			scanf("%s",ss[i]);
		
			E[i].clear();
		}

		scanf("%d",&M);

		for(int i=1;i<=M;++i)
		{
			scanf("%s %lf %s",ts1,&tr,ts2);
			t1=find(ts1);
			t2=find(ts2);

			addEdge(t1,t2,tr);
		}

		ok=0;

		for(int i=1;i<=N;++i)
			if(!SPFA(ans,N,i))
			{
				ok=1;
				break;
			}

		printf("Case %d: ",cas);

		if(ok)
			printf("Yes\n");
		else
			printf("No\n");

	}

	return 0;
}
