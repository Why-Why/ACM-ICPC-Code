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
// Created Time  : 2015年05月18日 星期一 09时03分03秒
// File Name     : C_1.cpp

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

const long long MOD=100000000007;
const long long HASH=100003;
const int MaxN=300005;

struct HashMap
{
	int head[HASH],next[MaxN],Hcou;
	long long key[MaxN];
	
	void init()
	{
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	void insert(long long val)
	{
		int h=val % HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(val==key[i])
				return;

		key[Hcou]=val;
		next[Hcou]=head[h];
		head[h]=Hcou++;
	}

	long long hash(char s[])
	{
		long long ret=0;
		long long seed=13131313;

		for(int i=0;s[i];++i)
			ret=(ret*seed+s[i]-'a')%MOD;

		return ret;
	}

	bool match(long long val)
	{
		int h=val % HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(val==key[i])
				return 1;

		return 0;
	}
};

HashMap myh;

char s[700005];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n,m;
	long long val;
	int len;
	long long seed=13131313;
	long long base=1;
	bool ok;

	myh.init();

	scanf("%d %d",&n,&m);

	while(n--)
	{
		scanf("%s",s);
		myh.insert(myh.hash(s));
	}

	while(m--)
	{
		base=1;
		ok=0;
		scanf("%s",s);
		val=myh.hash(s);
		len=strlen(s);

		for(int i=len-1;i>=0;--i)
		{
			for(int j=0;j<3;++j)
				if(j!=s[i]-'a')
					if(myh.match(((val+base*(j-(s[i]-'a'))%MOD+MOD)%MOD)))
					{
						ok=1;
						break;
					}

			if(ok)
				break;

			base=(base*seed)%MOD;
		}

		if(ok)
			puts("YES");
		else
			puts("NO");
	}
	
	return 0;
}
