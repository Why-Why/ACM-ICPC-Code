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

#pragma comment(linker, "/STACK:102400000,102400000")
	
using namespace std;

struct Edge
{
	int to,next;
};

Edge E[1000006];
int head[1000006],Ecou;
int N,M1,M2;

int ru[1000006];
int fa[1000006];

int find(int x)
{
	int t=x;
	int t1;

	while(fa[x]!=-1)
		x=fa[x];


	if(x==t)
		return x;

	while(fa[t]!=x)
	{
		t1=fa[t];
		fa[t]=x;
		t=t1;
	}

	return x;
}

void init(int N)
{
	Ecou=0;

	for(int i=1;i<=N;++i)
	{
		head[i]=-1;
		fa[i]=-1;
		ru[i]=0;
	}
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int que[3000006];
int first,last;

bool getans()
{
	int temp;
	int ttt;
	int cou=0;
	int zong=0;

	first=last=0;

	for(int i=1;i<=N;++i)
	{
		if(fa[i]==-1)
			++zong;

		if(fa[i]==-1 && ru[i]==0)
		{
			que[last++]=i;
			ru[i]=-1;
			++cou;
		}
	}

	while(last-first)
	{
		temp=que[first++];

		for(int i=head[temp];i!=-1;i=E[i].next)
		{
			ttt=find(E[i].to);
			--ru[ttt];

			if(ru[ttt]==0)
			{
				que[last++]=ttt;
				ru[ttt]=-1;
				++cou;
			}
		}
	}

	return cou<zong;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b;
	bool ok;

	scanf("%d",&T);

	while(T--)
	{
		ok=0;
		scanf("%d %d %d",&N,&M1,&M2);

		init(N);

		while(M1--)
		{
			scanf("%d %d",&a,&b);

			if(a==b)
				continue;

			if(find(a)==find(b))
				ok=1;
			else
				fa[find(a)]=find(b);
		}

		while(M2--)
		{
			scanf("%d %d",&a,&b);

			if(a==b)
				continue;

			addEdge(find(a),find(b));
			++ru[find(b)];
		}

		if(ok)
		{
			printf("YES\n");
			continue;
		}

		if(getans())
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
