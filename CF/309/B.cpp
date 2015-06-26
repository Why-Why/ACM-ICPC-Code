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
// Created Time  : 2015年06月25日 星期四 01时36分52秒
// File Name     : B.cpp

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

long long N,K;
long long F[100];
long long ZONG[100];

inline long long f(int x,int y)
{
	if(x==y && x==1)
		return 1;

	if(x==1)
		return 0;

	return F[y-1];
}

void init()
{
	F[1]=1;

	for(int i=2;;++i)
	{
		if(1e18/(i-1.0)<(double)F[i-1])
			break;

		F[i]=F[i-1]*(i-1);
	}

	ZONG[0]=1;
	ZONG[1]=1;

	for(int i=2;i<=51;++i)
	{
		ZONG[i]=0;

		for(int l=1;l<=i;++l)
			ZONG[i]+=ZONG[i-l]*F[l];
	}
}

int remx[100],remy[100];
int cou=0;
int rem[100];

void jiejue(int x,int y,int N,int &K)
{

}

void shuchu(int d,int len)
{
	for(int i=0;i<len;++i)
		cout<<rem[len]+d<<' ';
}

void getans(int N,int K)
{
	if(K==0)
		return;

	long long sum=0;

	int x,y;

	for(x=1;x<=N;++x)
		for(y=x;y<=N;++y)
		{
			if(N-y>=23 || sum>=K-f(x,y)*ZONG[N-y])
				goto end;

			sum+=f(x,y)*ZONG[N-y];
		}

	return;
end:

	jiejue(x,y,N,K);

	getans(N-y,K);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>N>>K;
	init();
	getans(N,K);

	return 0;
}
