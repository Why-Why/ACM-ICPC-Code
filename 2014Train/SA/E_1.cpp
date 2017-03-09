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
// Created Time  : 2015年10月14日 星期三 17时27分00秒
// File Name     : E_1.cpp

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

const int MaxN=1000006;

void EKMP_pre(int m,char s[],int next[])
{
	int p=0,a=1,L;

	next[0]=m;

	while(p+1<m && s[p]==s[p+1])
		++p;
	next[1]=p;

	for(int k=2;k<m;++k)
	{
		L=next[k-a];
		p=next[a]+a-(next[a]!=0);			/////

		if(k+L-1<p)
			next[k]=L;
		else
		{
			++p;
			while(p<m && s[p]==s[p-k])
				++p;

			next[k]=p-k;
			a=k;
		}
	}
}

int N;
char s[MaxN];
int next1[MaxN];

void getans()
{
	for(int i=1;i<N;++i)
		if(N%i==0 && next1[i]+i==N)
		{
			printf("%d\n",N/i);
			return;
		}
	puts("1");
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%s",s) && (s[0]!='.' || s[1]))
	{
		N=strlen(s);
		EKMP_pre(N,s,next1);
		getans();
	}
	
	return 0;
}
