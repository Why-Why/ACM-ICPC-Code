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
// Created Time  : 2015年10月01日 星期四 21时03分53秒
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
#include <climits>

using namespace std;

const int MaxN=100005;

int C1[MaxN],C2[MaxN];
int *C;
int N;
const int NN=10000;

inline int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int d)
{
	while(x<=NN)
	{
		C[x]=max(C[x],d);
		x+=lowbit(x);
	}
}

int find(int x)
{
	int ret=0;

	while(x>0)
	{
		ret=max(ret,C[x]);
		x-=lowbit(x);
	}
	return ret;
}

int A[MaxN<<1];

int rem[MaxN];

int getans(int A[])
{
	int ret=0;
	int t;

	for(int i=1;i<=10000;++i)
		C1[i]=C2[i]=0;
	C=C1;

	rem[0]=0;
	for(int i=1;i<=N;++i)
		if(A[i]==10000) rem[i]=rem[i-1];
		else
		{
			t=find(10000-A[i]);
			rem[i]=max(rem[i-1],t+A[i]);
			add(10000-A[i],t+A[i]);
		}

	C=C2;
	ret=rem[N];
	for(int i=N;i>=1;--i)
		if(A[i]==10000) continue;
		else
		{
			t=find(10000-A[i]);
			ret=max(ret,rem[i-1]+t+A[i]);
			add(10000-A[i],t+A[i]);
		}
	
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	srand(time(0));

	int ans;

	while(~scanf("%d",&N))
	{
		ans=0;
		for(int i=1;i<=N;++i)
		{
			scanf("%d",A+i);
			A[N+i]=A[i];
		}

		for(int i=1;i<=N;++i)
			if(A[i]==10000)
				ans=max(ans,getans(A+i));
		printf("%d\n",ans+10000);
	}
	
	return 0;
}
