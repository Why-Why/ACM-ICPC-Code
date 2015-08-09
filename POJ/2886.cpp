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
// Created Time  : 2015年07月01日 星期三 23时22分31秒
// File Name     : 2886.cpp

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

const int INF=0x3f3f3f3f;

const int remMax[36][2]={
    {1,1},{2,2},{4,3},{6,4},{12,6},
    {24,8},{36,9},{48,10},{60,12},
    {120,16},{180,18},{240,20},{360,24},
    {720,30},{840,32},{1260,36},{1680,40},
    {2520,48},{5040,60},{7560,64},{10080,72},
    {15120,80},{20160,84},{25200,90},{27720,96},
    {45360,100},{50400,108},{55440,120},{83160,128},
    {110880,144},{166320,160},{221760,168},{277200,180},
    {332640,192},{498960,200},{500001,200}};

int prime[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int best,ans,n;

void dfs(int dep,int temp,int num)
{
	if(dep>=16)
		return;

	if(num>best)
	{
		best=num;
		ans=temp;
	}

	if(num==best && ans>temp)
		ans=temp;

	for(int i=1;i<30;++i)
	{
		if(n/prime[dep]<temp)
			break;

		temp*=prime[dep];
		
		dfs(dep+1,temp,num*(i+1));
	}
}

int times,ans2;

void findM(int x)
{
	/*
    for(int i=0;i<35;++i)
        if(remMax[i][0]<=x&&remMax[i+1][0]>x)
            return i;
	*/

	best=0;
	ans=0;
	n=x;

	dfs(0,1,1);

	times=ans;
	ans2=best;
}

const int MaxN=500005;

int N;
int C[MaxN];

#define lowbit(x) (x&(-x))

void add(int x,int a)
{
	while(x<=N)
	{
		C[x]+=a;
		x+=lowbit(x);
	}
}

int sum(int x)
{
	int ret=0;

	while(x>0)
	{
		ret+=C[x];
		x-=lowbit(x);
	}

	return ret;
}

int find(int k)
{
	int ans=0,sum=0;

	for(int i=19;i>=0;--i)
	{
		ans+=(1<<i);

		if(ans>N || sum+C[ans]>=k)
			ans-=(1<<i);
		else
			sum+=C[ans];
	}

	return ans+1;
}

char name[MaxN][12];
int num[MaxN];
int K;

int getans(int nn,int cou)
{
	if(!cou)
		return K;

	if(nn<0)
		++nn;

	int p=sum(K)+nn;

	p=((p-1)%cou+cou)%cou+1;

	return find(p);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);


	while(~scanf("%d %d",&N,&K))
	{
		for(int i=1;i<=N;++i)
		{
			scanf("%s %d",name[i],&num[i]);
			C[i]=lowbit(i);
		}

		findM(N);

		for(int i=1;i<times;++i)
		{
			add(K,-1);
			K=getans(num[K],N-i);
		}

		printf("%s %d\n",name[K],ans2);
	}
	
	return 0;
}
