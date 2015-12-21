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
// Created Time  : 2015年10月15日 星期四 00时21分32秒
// File Name     : K.cpp

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

const int MaxN=100005;
const double PI=atan2(1.0,1.0)*4.0;
const double eps=1e-10;

inline int sgn(double x)
{
	return x<-eps ? -1 : x>eps;
}

struct Squ
{
	double xia,shang;
	double s;

	bool operator < (const Squ &y) const
	{
		return xia<y.xia;
	}

}sq[MaxN];

struct Ball
{
	double z;
	double r;
	double v;

	bool operator < (const Ball &y) const
	{
		return z<y.z;
	}

}ba[MaxN];

int N,M;
double w,l,v;

inline double getvalue(double r,double h)
{
	return PI*h*h*(r-h/3.0);
}

bool judge(double H)
{
	double sum=0;

	for(int i=1;i<=N;++i)
		if(sq[i].xia>=H) break;
		else sum+=sq[i].s*(min(sq[i].shang,H)-sq[i].xia);

	for(int i=1;i<=M;++i)
		if(ba[i].z-ba[i].r>=H) break;
		else if(H<=ba[i].z+ba[i].r) sum+=getvalue(ba[i].r,H-(ba[i].z-ba[i].r));
		else sum+=ba[i].v;

	return sgn(w*l*H-sum-v)>=0;
}

double getans()
{
	double L=0,R=10e20,M;

	while(R-L>1e-7)
	{
		M=(L+R)/2.0;
		if(judge(M)) R=M;
		else L=M;
	}
	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	double z,c,a,b;
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%lf %lf %lf %d %d",&w,&l,&v,&N,&M);
		for(int i=1;i<=N;++i)
		{
			scanf("%lf %lf %lf %lf",&z,&a,&b,&c);
			sq[i].s=a*b;
			sq[i].xia=z-c/2.0;
			sq[i].shang=z+c/2.0;
		}
		for(int i=1;i<=M;++i)
		{
			scanf("%lf %lf",&ba[i].z,&ba[i].r);
			ba[i].v=4.0*PI*ba[i].r*ba[i].r*ba[i].r/3.0;
		}

		sort(sq+1,sq+N+1);
		sort(ba+1,ba+M+1);

		printf("%.6f\n",getans());
	}
	
	return 0;
}
