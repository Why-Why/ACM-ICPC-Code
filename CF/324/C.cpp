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
// Created Time  : 2015年10月07日 星期三 00时54分43秒
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

const int MaxN=100005;

int N,T;
char s1[MaxN],s2[MaxN],s3[MaxN];

inline char other(char c1,char c2)
{
	for(char c='a';c<='z';++c)
		if(c!=c1 && c!=c2)
			return c;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&T);
	scanf("%s %s",s1,s2);

	int L=0,C=0;

	for(int i=0;i<N;++i)
		if(s1[i]==s2[i]) ++C;
		else ++L;

	int t=T;
	int L1=max(0,T-L),R1=floor((2*t-L)/2.0);

	if(R1<L1)
	{
		puts("-1");
		return 0;
	}

	if(L1>C || R1<0)
	{
		puts("-1");
		return 0;
	}
	
	int b=max(0,L1);
	int x=L-t+b,z=2*t-2*b-L;
	int y=x;

	for(int i=0;i<N;++i)
		if(s1[i]==s2[i])
		{
			if(b)
			{
				printf("%c",other(s1[i],s2[i]));
				--b;
			}
			else printf("%c",s1[i]);
		}
		else
		{
			if(x)
			{
				printf("%c",s1[i]);
				--x;
			}
			else
			{
				if(y)
				{
					printf("%c",s2[i]);
					--y;
				}
				else
					printf("%c",other(s1[i],s2[i]));
			}
		}
	puts("");
	
	return 0;
}
