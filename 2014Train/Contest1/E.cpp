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
// Created Time  : 2015年09月25日 星期五 10时25分47秒
// File Name     : E.cpp

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
const int mod=1000000007;

int N,M;
char p[MaxN];
int len;

int getans(long long a,long long b)
{
	long long base=a;
	long long ret=1;
	
	while(b)
	{
		if(b&1) (ret*=base)%=mod;
		(base*=base)%=mod;
		b>>=1;
	}

	return (int)ret;
}

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

int next1[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int pre,now;

	scanf("%d %d",&N,&M);
	scanf("%s",p+1);
	len=strlen(p+1);

	if(M==0)
	{
		printf("%d\n",getans(26,N));
		return 0;
	}

	--M;
	scanf("%d",&pre);
	long long sum=len;
	bool ok=1;

	EKMP_pre(len,p+1,next1+1);

	while(M--)
	{
		scanf("%d",&now);
		if(now-pre>=len) sum+=len;
		else
		{
			if(next1[now-pre+1]!=pre+len-now) ok=0;
			else sum+=now-pre;
		}
		pre=now;
	}

	if(ok) printf("%d\n",getans(26,N-sum));
	else puts("0");
	
	return 0;
}
