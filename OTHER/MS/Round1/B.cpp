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

const int MaxM=1000006;
const int MaxN=1000006;

struct Edge
{
	int to,next;
};

Edge E[MaxM*2];
int head[MaxN],Ecou;

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];

	head[u]=Ecou++;
}

int belong[MaxN];
int num[MaxN];
int N,K,M;
int vis[MaxN];
int flag=1;
int coulian;
int needshan;
int que[MaxN];
int first,last;

long long bfs(int u,int cou)
{
	int rem=u;
	int coubian=0,coudian=1;
	int temp;

	first=last=0;

	que[last++]=u;
	vis[u]=flag;
	belong[u]=cou;

	while(last-first)
	{
		temp=que[first++];

		for(int i=head[temp];i!=-1;i=E[i].next)
		{
			++coubian;

			if(vis[E[i].to]!=flag)
			{
				++coudian;
				vis[E[i].to]=flag;
				que[last++]=E[i].to;
				
				if(num[rem]>num[E[i].to])
				{
					rem=E[i].to;
				}

				belong[E[i].to]=cou;
			}
		}
	}

	coubian/=2;

	needshan+=(coubian-coudian+1);

	long long ret=num[rem];
	num[rem]=-1;

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,b,c;
	long long ans;

	scanf("%d",&T);

	while(T--)
	{
		init();
		coulian=0;
		++flag;
		needshan=0;
		ans=0;

		scanf("%d %d %d",&N,&M,&K);

		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		sort(num+1,num+N+1);

		while(M--)
		{
			scanf("%d %d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}

		for(int i=1;i<=N;++i)
			if(vis[i]<flag)
				ans+=bfs(i,++coulian);


		K-=needshan;


		if(K>0)
		{
			for(int i=1;i<=N;++i)
				if(num[i]>=0)
				{
					ans+=num[i];
					--K;

					if(K==0)
						break;
				}
		}

		printf("Case #%d: %lld\n",cas++,ans);

	}
	
	return 0;
}
