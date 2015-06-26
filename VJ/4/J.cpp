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

const int INF = 10e8;
const int MaxN = 1000010;
struct Edge
{
int v, cost,next;
};

Edge E1[MaxN],E2[MaxN],*E;
int head1[MaxN],head2[MaxN],Ecou1,Ecou2;
int *head;
bool vis[MaxN];
int couNode[MaxN];
bool SPFA(long long lowcost[], int n, int start,int type)
{
	if(type)
		E=E1,head=head1;
	else
		E=E2,head=head2;

queue <int> que;
int u, v, c;
int len;
for (int i = 1; i <= n; ++i) { lowcost[i] = INF; vis[i] = 0; couNode[i] = 0; }
vis[start] = 1; lowcost[start] = 0; couNode[start] = 1;
que.push(start);
while (!que.empty())
{
u = que.front(); que.pop();
vis[u] = 0;
for (int i = head[u]; i!=-1; i=E[i].next)
{
v = E[i].v; c = E[i].cost;
if (lowcost[v]>lowcost[u] + c)
{
lowcost[v] = lowcost[u] + c;
if (!vis[v])
{
vis[v] = 1; ++couNode[v]; que.push(v);
if (couNode[v]>n) return 0;
//这里应该是>=,也可能是>。
}
}
}
}
return 1;
}
inline void addEdge(int u, int v, int c,int type)
{
	int *Ecou;
	if(type)
	{
		E=E1,head=head1;
		Ecou=&Ecou1;
	}
	else
	{
		E=E2,head=head2;
		Ecou=&Ecou2;
	}

	E[*Ecou].v=v;
	E[*Ecou].cost=c;
	E[*Ecou].next=head[u];
	head[u]=(*Ecou)++;
}

void init(int N)
{
	Ecou1=Ecou2=0;

	for(int i=1;i<=N;++i)
		head1[i]=head2[i]=-1;
}

long long ans1[MaxN],ans2[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int N,M;
	int a,b,c;
	long long ans;

	cin>>T;

	while(T--)
	{
		scanf("%d %d",&N,&M);
		init(N);

		for(int i=1;i<=M;++i)
		{
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,c,1);
			addEdge(b,a,c,0);
		}

		SPFA(ans1,N,1,1);
		SPFA(ans2,N,1,0);

		ans=0;
		for(int i=2;i<=N;++i)
			ans+=ans1[i]+ans2[i];

		cout<<ans<<endl;
	}
	
	return 0;
}
