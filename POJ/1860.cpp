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

const int MaxN=1100;
const int MaxM=2100;

struct Edge
{
	int next,to;
	double R,C;
};

Edge E[MaxN];
int head[MaxN],Ecou;

void init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v,double r,double c)
{
	E[Ecou].to=v;
	E[Ecou].R=r;
	E[Ecou].C=c;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int que[200000];
int first,last;
bool vis[MaxN];
int couNode[MaxN];

bool SPFA(double lowcost[],int N,int start,double S)
{
	int temp;
	double r,c;
	int v;

	first=last=0;

	memset(couNode,0,sizeof(couNode));
	memset(vis,0,sizeof(vis));
	memset(lowcost,0,sizeof(lowcost));

	lowcost[start]=S;
	que[last++]=start;
	vis[start]=1;
	couNode[start]=1;

	while(last-first)
	{
		temp=que[first++];

		vis[temp]=0;

		for(int i=head[temp];i!=-1;i=E[i].next)
		{
			v=E[i].to;
			r=E[i].R;
			c=E[i].C;

			if(lowcost[temp]>=c && (lowcost[temp]-c)*r>lowcost[v])
			{
				lowcost[v]=(lowcost[temp]-c)*r;

				if(vis[v]==0)
				{
					vis[v]=1;
					que[last++]=v;

					++couNode[v];

					if(couNode[v]>N)
						return 0;
				}
			}
		}
	}

	return 1;
}

double lowcost[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,M,start;
	double S;
	int a,b;
	double c,d,e,f;

	while(~scanf("%d %d %d %lf",&N,&M,&start,&S))
	{
		init();

		while(M--)
		{
			scanf("%d %d %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f);

			addEdge(a,b,c,d);
			addEdge(b,a,e,f);
		}

		if(!SPFA(lowcost,N,start,S))
			puts("YES");
		else
			puts("NO");
	}
	
	return 0;
}
