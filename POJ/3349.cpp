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
// Created Time  : 2015年05月06日 星期三 20时43分01秒
// File Name     : 3349.cpp

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
const int MaxN=400005;

struct HashMap
{
	int head[HASH],next[MaxN],Hcou;
	unsigned long long key[MaxN];			// 记录key值。
	int rem[MaxN];							// 维护key相同的值。

	void init()
	{
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	int insert(unsigned long long val,int id)		// id不能为0。
	{
		int h=val % HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(val==key[i])
			{
				int temp=rem[i];
				rem[i]=id;					// 可以更改。
				return temp;
			}

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

int MinRepre(int len,int s[])
{

//	for(int i=0;i<len;++i)		// 预处理。
//		s[len+i]=s[i];
//	s[len+len]=0;
	
	int i=0,j=1,k;
	
	while(i<len && j<len)
	{
		k=0;

		while(s[i+k]==s[j+k] && k<len)
			++k;

		if(k==len)
			return min(i,j);

		if(s[i+k]>s[j+k])
			i=max(j+1,i+k+1);
		else
			j=max(i+1,j+k+1);
	}

	return min(i,j);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	int num[30];
	bool ok;
	int wei;

	sta.init();

	scanf("%d",&N);
	ok=0;

	for(int id=1;id<=N;++id)
	{
		for(int i=0;i<6;++i)
			scanf("%d",&num[i]);

		for(int i=6;i<12;++i)
			num[i]=num[i-6];

		wei=MinRepre(6,num);

		if(sta.insert(sta.hash(num+wei,6),id))
			ok=1;

		for(int i=0;i<6;++i)
			swap(num[i],num[11-i]);

		wei=MinRepre(6,num);

		if(sta.insert(sta.hash(num+wei,6),id))
			ok=1;

/*		sort(num,num+6);

		if(sta.insert(sta.hash(num,6),id))
			ok=1;*/
	}

	if(ok)
		puts("Twin snowflakes found.");
	else
		puts("No two snowflakes are alike.");
	
	return 0;
}
