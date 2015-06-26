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
// Created Time  : 2015年05月28日 星期四 23时14分48秒
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
#include <climits>

using namespace std;

const int MaxN=200005;

struct state
{
	int wei,val;
};

typedef pair <int,int> pii;
state sta[MaxN];
int num[MaxN],temp[MaxN];
map <int,int> tmap;
map <int,int> ::iterator p,p1;
int N,cou;

long long getans1(int a,int b)
{
	if(num[1]>=b)
		return 0;

	if(num[cou]<a)
		return 0;

	int L=1,R=cou,M;
	long long ret;

	while(R>L)
	{
		M=(L+R)>>1;

		if(num[M]<a)
			L=M+1;
		else
			R=M;
	}

	ret=L;

	L=1;
	R=cou;

	while(R>L)
	{
		M=(L+R+1)>>1;

		if(num[M]>=b)
			R=M-1;
		else
			L=M;
	}

	return L-ret+1;
}

long long getans2(int a,int b)
{
	if(num[1]>b)
		return 0;

	if(num[cou]<=a)
		return 0;

	int L=1,R=cou,M;
	long long ret;

	while(R>L)
	{
		M=(L+R)>>1;

		if(num[M]<=a)
			L=M+1;
		else
			R=M;
	}

	ret=L;

	L=1;
	R=cou;

	while(R>L)
	{
		M=(L+R+1)>>1;

		if(num[M]>b)
			R=M-1;
		else
			L=M;
	}

	return L-ret+1;
}


long long getans(int L,int R)
{
	if(L>=R)
		return 0;

	int M=(L+R)>>1;
	long long ret=0;

	ret+=getans(L,M);
	ret+=getans(M+1,R);

	int cou=0;
	int p=M+1;

	for(int i=L;i<=M;++i)
	{
		while(p<=R && num[p]<num[i])
		{
			temp[cou++]=num[p];
			++p;
		}

		temp[cou++]=num[i];
		ret+=p-M-1;
	}

	for(int i=0;i<cou;++i)
		num[L+i]=temp[i];

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
	{
		scanf("%d %d",&a,&b);
		
		tmap.insert(pii(a,a));
		tmap.insert(pii(b,b));

		p=tmap.find(a);
		p1=tmap.find(b);
		swap((*p).second,(*p1).second);
	}

	for(p=tmap.begin();p!=tmap.end();++p)
	{
		++cou;
		sta[cou].wei=(*p).first;
		sta[cou].val=(*p).second;
		num[cou]=sta[cou].val;
	}

	long long ans=0;

	ans+=getans(1,cou);

	for(int i=1;i<=cou;++i)
		if(sta[i].val>sta[i].wei)
		{
			ans+=sta[i].val-sta[i].wei;
			ans-=getans1(sta[i].wei,sta[i].val);
		}
		else
		{
			ans+=sta[i].wei-sta[i].val;
			ans-=getans2(sta[i].val,sta[i].wei);
		}

	cout<<ans<<endl;
	
	return 0;
}
