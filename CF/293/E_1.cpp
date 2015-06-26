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
// Created Time  : 2015年06月02日 星期二 00时20分01秒
// File Name     : E_1.cpp

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

const long long INF=10000000000000000LL;

int n,k;
long long num[100005];
long long rem[100005];
char s[1000];

inline bool chuli(int a,int b,long long x,long long y)
{
	if(y-x<b-a)
		return 0;

	if(x>=0)
		for(int i=a;i<=b;++i)
			rem[i]=x++;
	else if(y<=0)
		for(int i=b;i>=a;--i)
			rem[i]=y--;
	else
	{
		long long xia,shang;

		xia=max(x,-(b-a+1)/2LL);
		xia=min(xia,y-(b-a));

		shang=b-a+1+xia-1;

		while(xia<1)
			rem[a++]=xia++;

		while(shang)
			rem[b--]=shang--;
	}

	return 1;
}

inline bool chuli(int N)
{
	long long last=-INF;

	rem[++N]=INF-1;

	for(int i=1;i<=N;++i)
	{
		if(rem[i]!=INF)
		{
			if(rem[i]<=last)
				return 0;

			last=rem[i];
		}
		else
		{
			int t=i;

			while(rem[t]==INF)
				++t;

			if(!chuli(i,t-1,last+1,rem[t]-1))
				return 0;

			i=t-1;
			last=rem[i];
		}
	}

	return 1;
}

bool getans()
{
	int cou;

	for(int i=1;i<=k;++i)
	{
		cou=0;

		for(int j=i;j<=n;j+=k)
			rem[++cou]=num[j];

		if(!chuli(cou))
			return 0;

		for(int j=i,x=1;x<=cou;++x,j+=k)
			num[j]=rem[x];
	}

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);

	int t;

	cin>>n>>k;

	for(int i=1;i<=n;++i)
	{
		cin>>s;

		if(s[0]=='?')
			num[i]=INF;
		else
		{
			sscanf(s,"%d",&t);
			num[i]=t;
		}
	}

	if(getans())
	{
		for(int i=1;i<=n;++i)
			cout<<num[i]<<' ';
		cout<<endl;
	}
	else
		cout<<"Incorrect sequence"<<endl;

	return 0;
}
