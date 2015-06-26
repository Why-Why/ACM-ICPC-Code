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
// Created Time  : 2015年05月06日 星期三 23时01分12秒
// File Name     : 3274.cpp

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

const int HASH=100007;
const int MaxN=100005;

struct HashMap
{
	int head[HASH],next[MaxN],Hcou;
	unsigned long long key[MaxN];
	int rem[MaxN];

	void init()
	{
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	int insert(unsigned long long val,int id)
	{
		int h=val % HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==val)
				return rem[i];

		rem[Hcou]=id;
		key[Hcou]=val;
		next[Hcou]=head[h];
		head[h]=Hcou++;

		return 0;
	}

	unsigned long long hash(int num[],int n)
	{
		unsigned long long ret=0;
		unsigned long long seed=13131313;

		for(int i=0;i<n;++i)
			ret=ret*seed+num[i];

		return ret;
	}
};

HashMap sta;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,K;
	int ans=0;
	unsigned int temp;
	int t;
	int num[40]={0};
	int flag=0;
	
	sta.init();

	scanf("%d %d",&N,&K);

	sta.insert(sta.hash(num,K-1),1);

	for(int id=2;id<=N+1;++id)
	{
		scanf("%u",&temp);

		if(temp & (1<<(K-1)))
			flag=1;
		else
			flag=0;

		for(int i=0;i<K-1;++i)
		{
			if(temp & 1)
				++num[i];
			num[i]-=flag;

			temp>>=1;
		}

		t=sta.insert(sta.hash(num,K-1),id);
		
		if(t)
			ans=max(ans,id-t);
	}

	printf("%d\n",ans);
	
	return 0;
}
