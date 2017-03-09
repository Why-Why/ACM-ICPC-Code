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
// Created Time  : 2015年10月13日 星期二 22时10分19秒
// File Name     : B.cpp

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

const int MaxN=20004;

int wa[MaxN],wb[MaxN],wv[MaxN],ts[MaxN];
int sa[MaxN];

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
		for(p=0,i=n-j;i<n;++i) y[p++]=i;
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
	int k=0,i,j;

	for(i=1;i<=n;++i) rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
		for(k ? --k : 0 , j=sa[rank[i]-1];s[i+k]==s[j+k];++k);
}

int N,K;
int num[MaxN];
int rank[MaxN],height[MaxN];

int hnum[MaxN];
int hcou;

int hash(int x)
{
	return lower_bound(hnum,hnum+hcou,x)-hnum;
}

bool judge(int L)
{
	int cou=0;
	for(int i=1;i<=N;++i)
		if(height[i]>=L)
		{
			++cou;
			if(cou>=K-1) return 1;
		}
		else cou=0;
	return 0;
}

int getans()
{
	int L=0,R=N,M;
	
	while(R>L)
	{
		M=(L+R+1)>>1;
		if(judge(M)) L=M;
		else R=M-1;
	}
	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&N,&K))
	{
		hcou=0;
		for(int i=0;i<N;++i)
		{
			scanf("%d",num+i);
			hnum[hcou++]=num[i];
		}
		sort(hnum,hnum+hcou);
		hcou=unique(hnum,hnum+hcou)-hnum;

		for(int i=0;i<N;++i)
			num[i]=hash(num[i])+1;
		num[N]=0;

		DA(num,N+1,N+1);
		getHeight(num,N,rank,height);

		printf("%d\n",getans());
	}
	
	return 0;
}
