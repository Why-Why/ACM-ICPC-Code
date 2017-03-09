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
// Created Time  : 2015年10月14日 星期三 16时59分15秒
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

int sa[MaxN];
int wa[MaxN],wb[MaxN],wv[MaxN],ts[MaxN];

bool cmp(int r[],int a,int b,int l)
{
	return r[a]==r[b] && r[a+l]==r[b+l];
}

void DA(int s[],int n,int m)
{
	int i,j,p,*x=wa,*y=wb;

	for(i=0;i<m;++i) ts[i]=0;
	for(i=0;i<n;++i) ++ts[x[i]=s[i]];
	for(i=1;i<m;++i) ts[i]+=ts[i-1];
	for(i=n-1;i>=0;--i) sa[--ts[x[i]]]=i;

	for(j=1,p=1;p<n;j<<=1,m=p)
	{
		for(i=n-j,p=0;i<n;++i) y[p++]=i;
		for(i=0;i<n;++i) if(sa[i]>=j) y[p++]=sa[i]-j;

		for(i=0;i<n;++i) wv[i]=x[y[i]];
		for(i=0;i<m;++i) ts[i]=0;
		for(i=0;i<n;++i) ++ts[wv[i]];
		for(i=1;i<m;++i) ts[i]+=ts[i-1];
		for(i=n-1;i>=0;--i) sa[--ts[wv[i]]]=y[i];

		for(swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;++i)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j) ? p-1 : p++;
	}
}

void getHeight(int s[],int n,int rank[],int height[])
{
	int i,j,k=0;

	for(i=1;i<=n;++i) rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
		for(k ? k-- : 0, j=sa[rank[i]-1];s[i+k]==s[j+k];++k);
}

int N;
int num[MaxN];
int rank[MaxN],height[MaxN];
char s[MaxN];

const int INF=0x3f3f3f3f;

int getans()
{
	int t=rank[0];
	int minn;
	int ans=N;

	minn=INF;
	for(int i=t-1;i>=1;--i)
	{
		minn=min(minn,height[i+1]);
		if(minn+sa[i]==N && N%sa[i]==0)
			ans=min(ans,sa[i]);
	}

	minn=INF;
	for(int i=t+1;i<=N;++i)
	{
		minn=min(minn,height[i]);
		if(minn+sa[i]==N && N%sa[i]==0)
			ans=min(ans,sa[i]);
	}

	return N/ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%s",s) && (s[0]!='.' || s[1]))
	{
		for(N=0;s[N];++N) num[N]=s[N];
		num[N]=0;

		DA(num,N+1,128);
		getHeight(num,N,rank,height);

		printf("%d\n",getans());
	}
	
	return 0;
}
