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
// Created Time  : 2015年10月28日 星期三 11时03分47秒
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

const int MaxN=200005;

int wa[MaxN],wb[MaxN],wv[MaxN],ts[MaxN];
int sa[MaxN];

bool cmp(int r[],int a,int b,int l)
{
	return r[a]==r[b] && r[a+l]==r[b+l];
}

void DA(int *s,int n,int m)
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
		for(k ? k-- : 0 , j=sa[rank[i]-1];s[i+k]==s[j+k];++k);
}

int rank[MaxN],height[MaxN];
int N;
char s[MaxN];
int M;

int wei[MaxN];

int cou;
int ans[MaxN];

bool judge(int len)
{
	int vis[110]={0};
	int cou=0;
	int flag=1;
	int t=(M/2)+1;

	for(int i=1;i<=N;++i)
		if(height[i]<len)
		{
			if(cou>=t) return 1;
			++flag;
			cou=0;
			if(wei[sa[i]] && vis[wei[sa[i]]]!=flag)
			{
				cou=1;
				vis[wei[sa[i]]]=flag;
			}
		}
		else if(wei[sa[i]] && vis[wei[sa[i]]]!=flag)
		{
			++cou;
			vis[wei[sa[i]]]=flag;
		}

	if(cou>=t) return 1;
	return 0;
}

void show(int len)
{
	set <int> sta;
	char temp;

	for(int i=1;i<=N;++i)
		if(height[i]<len)
		{
			if(sta.size()>=(M/2)+1)
			{
				temp=s[sa[i-1]+len];
				s[sa[i-1]+len]=0;
				puts(&s[sa[i-1]]);
				s[sa[i-1]+len]=temp;
			}
			sta.clear();
			if(wei[sa[i]]) sta.insert(wei[sa[i]]);
		}
		else if(wei[sa[i]]) sta.insert(wei[sa[i]]);

	if(sta.size()>=(M/2+1))
	{
		s[sa[N]+len]=0;
		puts(&s[sa[N]]);
	}
}

void getans()
{
	int L=0,R=N,Mid;

	while(R>L)
	{
		Mid=(L+R+1)>>1;
		if(judge(Mid)) L=Mid;
		else R=Mid-1;
	}

	if(L==0) puts("?");
	else show(L);
}

int tc[110];
int num[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	bool first=1;

	for(int i=1;i<110;++i)
		if(i<'a') tc[i]=i;
		else tc[i]='z'+i-'a'+1;

	while(~scanf("%d",&M) && M)
	{
		N=0;
		for(int i=1;i<=M;++i)
		{
			scanf("%s",s+N);
			for(;s[N];++N) wei[N]=i,num[N]=s[N];
			wei[N]=0;
			num[N]=tc[i];
			s[N++]=tc[i];
		}
		s[N]=0;
		num[N]=0;

		if(!first) puts("");
		else first=0;

		if(M==1)
		{
			s[N-1]=0;
			puts(s);
			continue;
		}

		DA(num,N+1,158);
		getHeight(num,N,rank,height);

		getans();
	}
	
	return 0;
}
