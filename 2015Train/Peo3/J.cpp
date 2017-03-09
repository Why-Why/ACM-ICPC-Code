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
// Created Time  : 2015年09月23日 星期三 19时58分26秒
// File Name     : J.cpp

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

const int MaxN=200;

char s[MaxN];
int N;

void getN()
{
	int len=strlen(s);
	int sum=0,t=1;

	while(sum!=len)
	{
		if(t<10) ++sum;
		else sum+=2;
		++t;
	}

	N=t-1;
}

bool vis[MaxN];
int ans[MaxN];

bool getans(int p,int d)
{
	if(s[p]==0 || d>N)
	{
		if(s[p] || d<=N) return 0;

		int t=0;
		for(int i=1;i<=N;++i)
		{
			if(i!=1) printf(" ");
			if(ans[i]==1) printf("%c",s[t]);
			else printf("%c%c",s[t],s[t+1]);

			t+=ans[i];
		}
		puts("");
		
		return 1;
	}

	int t=(s[p]-'0')*10+s[p+1]-'0';
	if(s[p]!='0' && s[p+1] && t<=N && vis[t]==0)
	{
		vis[t]=1;
		ans[d]=2;
		if(getans(p+2,d+1)) return 1;
		vis[t]=0;
	}

	if(s[p]=='0') return 0;
	t=s[p]-'0';
	if(vis[t]) return 0;
	vis[t]=1;
	ans[d]=1;
	if(getans(p+1,d+1)) return 1;
	vis[t]=0;

	return 0;
}

int main()
{
	freopen("joke.in","r",stdin);
	freopen("joke.out","w",stdout);

	scanf("%s",s);
	getN();

	getans(0,1);
	
	return 0;
}
