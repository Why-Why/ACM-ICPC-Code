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
// Created Time  : 2015年09月26日 星期六 13时55分40秒
// File Name     : 1006.cpp

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

const int MaxN=105;
const long long INF=10000000000000000LL;

struct Point
{
	long long x,y;
	
	Point() {}
	Point(long long _x,long long _y):x(_x),y(_y) {}

	Point operator - (const Point &b) const
	{
		return Point(x-b.x,y-b.y);
	}

	long long operator ^ (const Point &b) const	// 叉乘。
	{
		return x*b.y-y*b.x;
	}

	long long operator * (const Point &b) const	// 点乘。
	{
		return x*b.x+y*b.y;
	}
};

long long CalcArea(Point P[],int n)
{
	long long ret=0;

	for(int i=0;i<n;++i)
		ret+=(P[i]^P[(i+1)%n]);

	return abs(ret);
}

Point list[MaxN];

long long dist(const Point &a,const Point &b)
{
	return (a-b)*(a-b);
}

bool _cmp(const Point &P1,const Point &P2)
{
	long long temp=(P1-list[0])^(P2-list[0]);

	if(temp>0)
		return 1;
	else if(temp==0 && (dist(P1,list[0])<dist(P2,list[0])))		// <= 会RE！！！
		return 1;
	else
		return 0;
}

void Graham(int Stack[],int &top,int n)
{
	Point P0=list[0];
	int k=0;

	for(int i=1;i<n;++i)
		if((P0.y-list[i].y)>0 || ((P0.y-list[i].y)==0 && (P0.x-list[i].x)>0))
		{
			P0=list[i];
			k=i;
		}

	swap(list[k],list[0]);
	sort(list+1,list+n,_cmp);

	if(n==1)
	{
		top=1;
		Stack[0]=0;

		return;
	}

	if(n==2)
	{
		top=2;
		Stack[0]=0;
		Stack[1]=1;
	}

	Stack[0]=0;
	Stack[1]=1;
	top=2;

	for(int i=2;i<n;++i)
	{
		while(top>1 && ((list[Stack[top-1]]-list[Stack[top-2]])^(list[i]-list[Stack[top-2]]))<=0)
			--top;

		Stack[top++]=i;
	}
}

int N,K;
int STACK[MaxN],top;
Point rem[MaxN];
long long area[MaxN][MaxN];
long long dp[MaxN][MaxN][MaxN];

void getarea()
{
	long long sum=CalcArea(rem,N);
	for(int i=0;i<N;++i) area[i][i]=0;
	for(int i=0;i<N;++i)
	{
		for(int j=i+1;j<N;++j)
			area[i][j]=CalcArea(rem+i,j-i+1);
		for(int j=0;j<i;++j)
			area[i][j]=sum-CalcArea(rem+j,i-j+1);
	}
}

long long getans()
{
	getarea();
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			for(int k=0;k<=K;++k)
				dp[i][j][k]=INF;
	for(int i=0;i<N;++i) dp[i][i][1]=0;

	long long minn;

	for(int i=0;i<N;++i)
	{
		for(int j=i+1;j<N;++j)
		{
			dp[i][j][2]=area[i][j];
			for(int k=3;k<=K;++k)
			{
				minn=INF;
				for(int t=i+1;t<j;++t)
					if(dp[i][t][k-1]!=INF)
						minn=min(minn,dp[i][t][k-1]+area[t][j]);
				dp[i][j][k]=minn;
			}
		}

		for(int j=0;j<i;++j)
		{
			dp[i][j][2]=area[i][j];
			for(int k=3;k<=K;++k)
			{
				minn=INF;
				for(int t=i+1;t<N;++t)
					if(dp[i][t][k-1]!=INF)
						minn=min(minn,dp[i][t][k-1]+area[t][j]);
				for(int t=0;t<j;++t)
					if(dp[i][t][k-1]!=INF)
						minn=min(minn,dp[i][t][k-1]+area[t][j]);
				dp[i][j][k]=minn;
			}
		}
	}

	long long ret=INF;
	long long sum=area[0][N-1];

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			ret=min(ret,dp[i][j][K]+area[j][i]);

	return sum-ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&K);
		for(int i=0;i<N;++i)
			scanf("%I64 %I64d",&list[i].x,&list[i].y);
		Graham(STACK,top,N);
		for(int i=0;i<top;++i)
			rem[i]=list[STACK[i]];
		N=top;

		printf("Case #%d: ",cas++);
		if(top<=K)
			printf("%I64d\n",CalcArea(rem,N));
		else
			printf("%I64d\n",getans());
	}
	
	return 0;
}
