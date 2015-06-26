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
// Created Time  : 2015年06月03日 星期三 09时37分21秒
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

int N;
int num[100005];
int rem[100005],rem1[100005];
int t1[100005],t2[100005];

bool judge(int a,int b)
{
	int cou=0;

	memset(rem,0,sizeof(rem));

	for(int i=a;i<=b;++i)
	{
		++rem[num[i]];
		++rem1[num[i]];
	}

	for(int i=1;i<=N;++i)
		if(rem[i] & 1)
			++cou;

	if(cou>1)
		return 0;

	return 1;
}

long long getnum1(int a,int b)
{
	long long minn=b;

	for(int i=b;i+i>=a+b;--i)
	{
		rem[num[i]]-=2;

		if(rem[num[i]]>=0)
			--minn;
		else
			break;
	}

	int p;

	for(p=(b+a)>>1;p>=a;--p)
		if(num[p]!=num[a+b-p])
			break;

	for(int i=a;i<=p;++i)
	{
		++t1[num[i]];
		--t1[num[a+b-i]];
	}

	bool ok=1;

	for(int i=1;i<=N;++i)
		if(t1[i])
			ok=0;

	if(ok)
		minn=p;

	return a*(N-minn+1LL);
}

long long getnum2(int a,int b)
{
	long long maxn=a;

	for(int i=a;i+i<=a+b;++i)
	{
		rem1[num[i]]-=2;

		if(rem1[num[i]]>=0)
			++maxn;
		else
			break;
	}

	int p;

	for(p=(b+a)>>1;p>=a;--p)
		if(num[p]!=num[a+b-p])
			break;

	p=a+b-p;

	for(int i=b;i>=p;--i)
	{
		++t2[num[i]];
		--t2[num[a+b-i]];
	}

	bool ok=1;

	for(int i=1;i<=N;++i)
		if(t2[i])
			ok=0;

	if(ok)
		maxn=p;

	return (N-b+1LL)*(maxn-a);
}

long long getans()
{
	for(int i=1;(i<<1)<=N;++i)
		if(num[i]!=num[N-i+1])
		{
			if(!judge(i,N-i+1))
				return 0;

			return getnum1(i,N-i+1)+getnum2(i,N-i+1);
		}

	return (long long)N+N*(N-1LL)/2;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
		scanf("%d",&num[i]);

	cout<<getans()<<endl;
	
	return 0;
}
