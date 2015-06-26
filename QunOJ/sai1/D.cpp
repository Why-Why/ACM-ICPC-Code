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

bool an[15];
int S,T;
int vis[200];
int step[]={0,1,2,3,0,4,5,6,0,7,8,9,0,0};

int bfs()
{
	queue <int> que;
	int t,t1;

	vis[S]=1;
	que.push(S);

	while(!que.empty())
	{
		t=que.front();
		que.pop();

		if(t==T)
			return vis[t]-1;

		for(int i=1;i<=13;++i)
		{
			if(an[i]==0)
				continue;

			if(i==12)
				continue;

			if(i==4)
			{
				t1=t+1;
				if(t1==100)
					t1=0;
			}
			else if(i==8)
			{
				t1=t-1;
				if(t1==-1)
					t1=99;
			}
			else
				t1=step[i];

			if(!vis[t1])
			{
				vis[t1]=vis[t]+1;
				que.push(t1);
			}
		}

		if(an[12])
		{
			for(int i=1;i<=13;++i)
			{
				if(an[i]==0)
					continue;
				if(i==12 || i==4 || i==8)
					continue;
				if(i==13)
					continue;

				for(int j=1;j<=13;++j)
				{
					if(an[j]==0)
						continue;
					if(j==12 || j==4 || j==8)
						continue;

					t1=step[i]*10+step[j];

					if(!vis[t1])
					{
						vis[t1]=vis[t]+3;
						que.push(t1);
					}
				}
			}
		}
	}

	return -1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas;
	int t;

	scanf("%d",&cas);

	while(cas--)
	{
		for(int i=1;i<=13;++i)
		{
			scanf("%d",&t);
			an[i]=t;
		}

		scanf("%d %d",&S,&T);

		memset(vis,0,sizeof(vis));

		printf("%d\n",bfs());
	}
	
	return 0;
}
