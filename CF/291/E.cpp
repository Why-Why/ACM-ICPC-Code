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
// Created Time  : 2015年06月04日 星期四 14时32分41秒
// File Name     : E.cpp

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

const int mod=1000000007;

struct Metrix
{
	long long num[105][105];
	int n;

	Metrix operator * (const Metrix & b) const
	{
		Metrix temp;
		long long sum;

		temp.n=n;

		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				sum=0;

				for(int x=1;x<=n;++x)
					(sum+=num[i][x]*b.num[x][j])%=mod;

				temp.num[i][j]=sum;
			}

		return temp;
	}

	Metrix operator ^ (int x) const
	{
		Metrix ret,base;

		ret.n=base.n=n;

		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				base.num[i][j]=num[i][j];
				ret.num[i][j]=0;
			}

		for(int i=1;i<=n;++i)
			ret.num[i][i]=1;

		while(x)
		{
			if(x&1)
				ret=ret*base;

			base=base*base;
			x>>=1;
		}

		return ret;
	}

	void display()
	{
		for(int i=1;i<=n;++i,cout<<endl)
			for(int j=1;j<=n;++j)
				cout<<num[i][j]<<' ';

		cout<<endl;
	}
};

int n,x;
int rem[110];
Metrix ans;
long long F[110];
long long zans[110];

long long getans()
{
	for(int i=1;i<=99;++i)
		F[i]=0;

	F[100]=1;
	F[101]=1;

	long long sum;

	for(int i=1;i<=101;++i)
	{
		sum=0;

		for(int x=1;x<=101;++x)
			(sum+=ans.num[i][x]*F[x])%=mod;

		zans[i]=sum;
	}

	return zans[101];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;

	scanf("%d %d",&n,&x);

	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a);
		++rem[a];
	}

	ans.n=101;

	memset(ans.num,0,sizeof(ans.num));

	for(int i=1;i<100;++i)
		ans.num[i][i+1]=1;

	for(int i=1;i<=100;++i)
	{
		ans.num[100][i]=rem[101-i];
		ans.num[101][i]=rem[101-i];
	}

	ans.num[101][101]=1;

	ans=ans^x;

	cout<<getans()<<endl;
	
	return 0;
}
