// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年07月21日 星期二 12时36分16秒
// File Name     : A.cpp

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

const int MaxN=10005;
const int MaxNode=100005;

int N;
int num[MaxNode];

int chu[MaxN][10];
int chuK[MaxN][10];
int cou[MaxN];

int prime[2000];
int pcou;
bool vis[MaxN];

void init()
{
	pcou=0;
	int t,tcou;

	for(int i=2;i<MaxN;++i)
		if(!vis[i])
		{
			prime[pcou++]=i;

			for(int j=i*2;j<MaxN;j+=i)
				vis[j]=1;
		}

	for(int i=1;i<=10000;++i)
	{
		if(vis[i]==0)
		{
			chu[i][0]=i;
			chuK[i][0]=1;
			cou[i]++;
		}
		else
		{
			for(int j=0;j<pcou && prime[j]<=i;++j)
				if(i%prime[j]==0)
				{
					t=i;
					tcou=0;
					chu[i][cou[i]]=prime[j];
    
					while(t%prime[j]==0)
					{
						t/=prime[j];
						tcou++;
					}
    
					chuK[i][cou[i]++]=tcou;
				}
		}
	}
}

int rem[MaxN];
long long RM[MaxNode],LM[MaxNode];
int trem;

const int mod=1000000000+7;

long long chuli1(int x,int d)
{
	if(d>=cou[trem])
		return rem[x];

	long long maxn=0;

	for(int i=0;i<=chuK[trem][d];++i)
	{
		maxn=max(chuli1(x,d+1),(long long)maxn);
		x/=chu[trem][d];
	}

	return maxn;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	init();

	while(~scanf("%d",&N))
	{
		if(N<1)
		{
			printf("1\n");
			continue;
		}

		memset(rem,0,sizeof(rem));

		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		for(int i=1;i<=N;++i)
		{
			trem=num[i];
			LM[i]=chuli1(num[i],0);
			rem[num[i]]=i;
		}

		memset(rem,0,sizeof(rem));
		reverse(num+1,num+N+1);

		for(int i=1;i<=N;++i)
		{
			trem=num[i];
			RM[N+1-i]=N+1-chuli1(num[i],0);
			rem[num[i]]=i;
		}

		long long ans=0;

		for(long long i=1;i<=N;++i)
			(ans+=(i-LM[i])*(RM[i]-i))%=mod;

		printf("%I64d\n",ans);
	}

	return 0;
}
