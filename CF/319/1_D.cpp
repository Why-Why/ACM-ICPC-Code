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
// Created Time  : 2015年09月30日 星期三 22时03分41秒
// File Name     : 1_D.cpp

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

#include <bitset>

using namespace std;

const int MaxN=160;

int N;

struct Mat
{
	bitset <MaxN> num[MaxN];

	Mat operator * (const Mat & b) const
	{
		Mat ret;
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				if(num[i][j])
					ret.num[i]|=b.num[j];
		return ret;
	}
};

int M;

struct Edge
{
	int u,v,d;

	bool operator < (const Edge & b) const
	{
		return d<b.d;
	}
};

Edge E[MaxN];
Mat ans,map1;

Mat _pow(Mat base,int n)
{
	Mat ret;
	for(int i=1;i<=N;++i) ret.num[i][i]=1;

	while(n)
	{
		if(n&1) ret=ret*base;
		base=base*base;
		n>>=1;
	}
	return ret;
}

int getans(int R)
{
	int L=1,M;
	Mat temp=ans*_pow(map1,R);

	if(temp.num[1][N]==0)
	{
		ans=temp;
		return 0;
	}

	while(R>L)
	{
		M=(L+R)>>1;
		temp=ans*_pow(map1,M);
		if(temp.num[1][N]) R=M;
		else L=M+1;
	}
	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);
	for(int i=1;i<=M;++i)
		scanf("%d %d %d",&E[i].u,&E[i].v,&E[i].d);
	sort(E+1,E+M+1);
	++M;
	E[M].d=1000000000+1000;
	E[M].u=E[M].v=0;

	if(E[1].d)
	{
		puts("Impossible");
		return 0;
	}
	
	int t;

	map1.num[N][N]=1;
	for(int i=1;i<=N;++i) ans.num[i][i]=1;
	
	map1.num[E[1].u][E[1].v]=1;
	for(int i=2;i<=M;++i)
		if(E[i].d!=E[i-1].d)
		{
			if(t=getans(E[i].d-E[i-1].d))
			{
				printf("%d\n",E[i-1].d+t);
				return 0;
			}
			map1.num[E[i].u][E[i].v]=1;
		}
		else
			map1.num[E[i].u][E[i].v]=1;

	puts("Impossible");
	
	return 0;
}
