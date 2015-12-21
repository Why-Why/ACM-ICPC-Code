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
// Created Time  : 2015年08月13日 星期四 12时13分57秒
// File Name     : 1008.cpp

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

struct NUM
{
	long long S,X;

	NUM(long long a=0,long long b=1)
	{
		S=a;
		X=b;
		jian();
	}

	long long gcd(long long a,long long b)
	{
		if(!a) return b;
		return gcd(b%a,a);
	}

	void jian()
	{
		long long t=gcd(S,X);
		if(t)
		{
			S/=t;
			X/=t;
		}
	}

	NUM operator + (const NUM &b) const
	{
		NUM ret;
		ret.X=X*b.X;
		ret.S=S*b.X;
		ret.S+=X*b.S;

		ret.jian();
		return ret;
	}

	NUM operator - (const NUM &b) const
	{
		NUM ret;
		ret.X=X*b.X;
		ret.S=S*b.X;

		if(X*b.S>=ret.S)
			ret.S=X*b.S-ret.S;
		else
			ret.S-=X*b.S;

		ret.jian();

	//	ret.dis();
	//	cerr<<"aqwer";

		while(ret.X*360<=ret.S)
			ret.S-=360*ret.X;
		if(ret.X*180<=ret.S)
			ret.S=360*ret.X-ret.S;
		ret.jian();
		return ret;
	}

	void dis()
	{
		if(X==1 || S==0)
			printf("%I64d",S);
		else
			printf("%I64d/%I64d",S,X);
	}
};


//NUM H[25][62][62],M[25][62][62],S[25][62][62];

NUM chuH(int h,int m,int s)
{
	if(h>=12) h-=12;
	NUM ret;
	ret=ret+NUM(30*h,1);
	ret=ret+NUM(m,2);
	ret=ret+NUM(s,120);

	return ret;
}

NUM chuM(int h,int m,int s)
{
	NUM ret;
	ret=ret+NUM(6*m,1);
	ret=ret+NUM(s,10);

	return ret;
}

NUM chuS(int h,int m,int s)
{
	NUM ret;
	ret=ret+NUM(6*s,1);

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int h,m,s;
	int T;
	NUM d1,d2,d3;

	//init();
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d:%d:%d",&h,&m,&s);
		//(H[h][m][s]-M[h][m][s]).dis();
		//(H[h][m][s]-s[h][m][s]).dis();
		//

		d1=chuH(h,m,s);
		d2=chuM(h,m,s);
		d3=chuS(h,m,s);

		(d1-d2).dis();
		printf(" ");
		(d1-d3).dis();
		printf(" ");
		(d2-d3).dis();
		printf(" \n");
	}
	
	return 0;
}
