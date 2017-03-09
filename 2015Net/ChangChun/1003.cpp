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
// Created Time  : 2015年09月14日 星期一 19时29分01秒
// File Name     : 1003.cpp

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

const int MaxN=500000;
const int Mod=1000000007;

long long num[MaxN];
long long sum[MaxN];
long long mul[MaxN];
long long zhong[MaxN];

long long find(int x)
{
	int L=1,M,R=MaxN-1;

	while(R>L)
	{
		M=(L+R+1)>>1;
		if(sum[M]<x) L=M;
		else R=M-1;
	}

	return L;
}

long long getans(long long x)
{
	long long t=find(x);
	long long tx=sum[t]+1;
	long long y=mul[t]+(x-sum[t])*(t+1LL);
	long long cha=y-mul[t];
	long long ge=((cha-1)/(t+1));
	x=tx;
	long long hou=(ge*(2*x+ge-1)/2)%Mod*(t+1)%Mod+(x+ge)*(cha-(t+1)*ge)%Mod;
	hou%=Mod;

	return (zhong[t]+hou)%Mod;
}

long long getzhong(long long x,long long t)
{
	long long y=mul[t+1];
	long long cha=y-mul[t];
	long long ge=((cha-1)/(t+1));
	long long hou=(ge*(2*x+ge-1)/2)%Mod*(t+1)%Mod+(x+ge)*(cha-(t+1)*ge)%Mod;
	hou%=Mod;

	return (zhong[t]+hou)%Mod;
}

long long ttt(long long x)
{
	long long t=find(x);

	return mul[t]+(x-sum[t])*(t+1LL);
}

void init()
{
	int p=1;
	sum[1]=num[1]=1;
	num[2]=2;
	sum[2]=3;
	mul[1]=1;
	mul[2]=5;
	zhong[1]=1;
	zhong[2]=11;
	for(int i=3;i<MaxN;++i)
	{
		if(sum[p+1]<i) ++p;
		num[i]=p+1;
		sum[i]=sum[i-1]+num[i];
		mul[i]=mul[i-1]+i*num[i];

		zhong[i]=getzhong(sum[i-1]+1,i-1);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	init();

	int T,a;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&a);
		printf("%d\n",(int)getans(a));
	}
	
	return 0;
}
