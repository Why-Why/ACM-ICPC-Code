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
// Created Time  : 2015年10月01日 星期四 09时56分40秒
// File Name     : C.cpp

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

const int MaxN=5000006;

char s[MaxN];
char b[MaxN];

int next[MaxN];

int srem[MaxN];
char sc[MaxN];
int top=0;

void KMP_pre(int m,char s[])
{
	int i=0,j=-1;

	next[0]=-1;

	while(i<m)
	{
		while(j!=-1 && s[i]!=s[j])
			j=next[j];

		++i;
		++j;

		next[i]=j;
	}
}

int KMP(int n,char s1[],int m,char s2[])
{
	int i=0,j=0;

	KMP_pre(m,s2);

	while(i<n)
	{
		while(j!=-1 && s1[i]!=s2[j])
			j=next[j];

		sc[top]=s[i];
		srem[top++]=j;

		++i;
		++j;

		if(j>=m)
		{
			top-=m;
			j=srem[top-1]+1;
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%s %s",b,s))
	{
		top=0;
		KMP(strlen(s),s,strlen(b),b);
		sc[top]=0;
		printf("%s\n",sc);
	}
	
	return 0;
}
