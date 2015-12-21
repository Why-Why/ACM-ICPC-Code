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
// Created Time  : 2015年11月01日 星期日 15时01分31秒
// File Name     : 1005.cpp

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

const double eps=1e-8;
const double PI=acos(-1.0);

inline int sgn(double x)
{
	return x<-eps ? -1 : x>eps;
}

double dist(double dx,double dy)
{
	return sqrt(dx*dx+dy*dy);
}

const int MaxN=10004;

int N;
double d[MaxN];
double x[MaxN],y[MaxN];

double r[MaxN];

void getansji()
{
	d[N]=0;
	double sum=0;
	for(int i=0;i<N;i+=2) sum+=d[i]-d[i+1];
	if(sgn(sum)<0)
	{
		puts("IMPOSSIBLE");
		return;
	}
	r[0]=sum/2.0;
	double ans=r[0]*r[0];

	for(int i=1;i<N;++i)
	{
		r[i]=d[i-1]-r[i-1];
		ans+=r[i]*r[i];
		if(sgn(r[i])<0)
		{
			puts("IMPOSSIBLE");
			return;
		}
	}

	printf("%.2f\n",PI*ans);
	for(int i=0;i<N;++i)
		printf("%.2f\n",r[i]);
}

double getnum(double r)
{
	double ret=0;

	for(int i=0;i<N;++i)
	{
		ret+=r*r;
		r=d[i]-r;
	}

	return ret;
}

bool judge(double r)
{
	for(int i=0;i<N;++i)
	{
		if(sgn(r)<0) return 0;
		r=d[i]-r;
	}
	return 1;
}

void getansou()
{
	double sum=0;
	for(int i=0;i<N;i+=2) sum+=d[i]-d[i+1];
	if(sgn(sum))
	{
		puts("IMPOSSIBLE");
		return;
	}

	double minn=0,maxn=d[0];
	sum=0;

	for(int i=0;i<N;++i)
		if(i&1)
		{
			sum-=d[i];
			minn=max(minn,sum);
		}
		else
		{
			sum+=d[i];
			maxn=min(maxn,sum);
		}

	if(sgn(maxn-minn)<0)
	{
		puts("IMPOSSIBLE");
		return;
	}

	double R=maxn,L=minn,M1,M2;
	double t1,t2;

	while(R-L>1e-4)
	{
		M1=(R+2.0*L)/3.0;
		M2=(2.0*R+L)/3.0;

		t1=getnum(M1);
		t2=getnum(M2);
		if(t1>t2) L=M1;
		else R=M2;
	}

	t1=getnum(L);

	printf("%.2f\n",t1*PI);
	for(int i=0;i<N;++i)
	{
		if(sgn(L)==0) L=0;
		printf("%.2f\n",L);
		L=d[i]-L;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;++i) scanf("%lf %lf",x+i,y+i);
		x[N]=x[0];
		y[N]=y[0];
		for(int i=0;i<N;++i) d[i]=dist(x[i+1]-x[i],y[i+1]-y[i]);

		if(N&1) getansji();
		else getansou();
	}
	
	return 0;
}
