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
// Created Time  : 2015年09月23日 星期三 20时41分00秒
// File Name     : F.cpp

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
#include <bitset>

using namespace std;

const int MaxN=1010;

int m,f;
int a[MaxN];
int n;
char s[MaxN];
bitset <1005> rem[MaxN],que;

bool vis[MaxN]={0};
int ans=0;

inline int change(char c)
{
	if(c>='0' && c<='9') return c-'0';
	return c-'a'+10;
}

void zhuan(long long q)
{
	for(int i=1;i<=f;++i)
		que.set((q*a[i])%m);
}

int main()
{
	freopen("filter.in","r",stdin);
	freopen("filter.out","w",stdout);

	scanf("%d %d",&m,&f);
	for(int i=1;i<=f;++i)
		scanf("%d",a+i);
	
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%s",s);
		for(int j=strlen(s)-1;j>=0;--j)
		{
			rem[i]<<=4;
			rem[i]|=change(s[j]);
		}
	}

	int Q;
	long long q;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%lld",&q);
		que.reset();
		zhuan(q);

		for(int i=0;i<n;++i)
			if(vis[i]==0)
				if((que & rem[i]) == que)
					vis[i]=1,++ans;
	}

	printf("%d",ans);
	for(int i=0;i<n;++i)
		if(vis[i]) printf(" %d",i);
	puts("");
	
	return 0;
}
