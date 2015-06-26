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
// Created Time  : 2015年05月07日 星期四 18时58分22秒
// File Name     : 2002.cpp

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

const int HASH=100003;
const int MaxN=1010;

struct HashMap
{
	int head[HASH],next[MaxN],Hcou;
	int key[MaxN];

	void init()
	{
		memset(head,-1,sizeof(head));
		Hcou=0;
	}

	void insert(int val)
	{
		int h=val % HASH;

		if(h<0)
			h+=HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==val)
				return;

		key[Hcou]=val;
		next[Hcou]=head[h];
		head[h]=Hcou++;
	}

	bool find(int val)
	{
		int h=val % HASH;

		if(h<0)
			h+=HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==val)
				return 1;

		return 0;
	}
}sta;

int N;
int x[1010],y[1010];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int x1,y1,x2,y2;
	long long ans;

	while(~scanf("%d",&N) && N)
	{
		ans=0;
		sta.init();
		
		for(int i=1;i<=N;++i)
		{
			scanf("%d %d",&x[i],&y[i]);
			sta.insert(x[i]*30000+y[i]);
		}

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				if(i!=j)
				{
					x1=x[i]+x[j]+y[j]-y[i];
					y1=x[i]+y[i]+y[j]-x[j];
					x2=x[i]+y[i]+x[j]-y[j];
					y2=y[i]+x[j]-x[i]+y[j];

					if(!(x1&1) && !(x2&1) && !(y1&1) && !(y2&1))
					{
						x1>>=1;
						x2>>=1;
						y1>>=1;
						y2>>=1;

						if(sta.find(x1*30000+y1) && sta.find(x2*30000+y2))
							++ans;
					}
				}

		ans>>=2;

		printf("%lld\n",ans);
	}
	
	return 0;
}
