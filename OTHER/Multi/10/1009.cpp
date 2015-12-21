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
// Created Time  : 2015年08月20日 星期四 13时44分31秒
// File Name     : 1009.cpp

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

const int MaxN=100005;

char s[MaxN],t[MaxN];

int diyi()
{
	if(s[0]!=t[0]) return 0;

	int ret=0;
	for(ret=1;s[ret] && t[ret];++ret)
		if(s[ret]!=s[ret-1] || t[ret]!=t[ret-1])
			break;

	if(t[ret]!=t[ret-1]) return ret;
	return 0;
}

bool judge()
{
	int p1=0;

	p1=diyi();
	if(!p1) return 0;

	if(!s[p1])
		return 1;

	for(int i=p1;t[i];++i)
	{
		if(t[i]==s[p1])
			++p1;
		if(!s[p1])
			return 1;
	}
	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%s %s",s,t);

		if(judge())
			puts("Yes");
		else
			puts("No");
	}
	
	return 0;
}
