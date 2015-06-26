// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年05月08日 星期五 22时34分29秒
// File Name     : 3126.cpp

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

bool vis[10010];

void init()
{
	for(int i=2;i<=10000;++i)
		if(vis[i]==0)
			for(int j=i*2;j<=10000;j+=i)
				vis[j]=1;
}

int que[10010];
int first,last;
int rem[10010];

int bfs(int a,int b)
{
	first=last=0;
	memset(rem,0,sizeof(rem));

	int t;
	int b1,b2;

	que[last++]=a;
	rem[a]=1;

	while(last-first)
	{
		a=que[first++];

		if(a==b)
			return rem[a]-1;

		for(int i=1;i<=9;++i)
		{
			t=a%1000+i*1000;

			if(vis[t]==0 && rem[t]==0)
			{
				rem[t]=rem[a]+1;
				que[last++]=t;
			}
		}

		b1=100;
		b2=1000;

		for(int k=0;k<3;++k)
		{
			for(int i=0;i<=9;++i)
			{
				t=(a%b1)+b1*i+(a/b2)*b2;

				if(vis[t]==0 && rem[t]==0)
				{
					rem[t]=rem[a]+1;
					que[last++]=t;
				}
			}

			b1/=10;
			b2/=10;
		}
	}

	return -1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	int T;
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&a,&b);

		a=bfs(a,b);

		if(a==-1)
			puts("Impossible");
		else
			printf("%d\n",a);
	}
	
	return 0;
}
