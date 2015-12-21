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
// Created Time  : 2015年10月20日 星期二 19时21分28秒
// File Name     : I.cpp

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
const int INF=0x3f3f3f3f;

int wa[MaxN],wb[MaxN],wv[MaxN],ts[MaxN];
int sa[MaxN];

bool cmp(int r[],int a,int b,int l)
{
	return r[a]==r[b] && r[a+l]==r[b+l];
}

void DA(char *s,int n,int m)
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

void getHeight(char s[],int n,int rank[],int height[])
{
	int k=0,i,j;

	for(i=1;i<=n;++i) rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
		for(k ? k-- : 0 , j=sa[rank[i]-1];s[i+k]==s[j+k];++k);
}

char s[MaxN];
int N,K,M;
int rank[MaxN],height[MaxN];

int sh[MaxN],sp[MaxN],top;
long long sa1[MaxN],sa2[MaxN];
int cou1[MaxN],cou2[MaxN];

long long getans()
{
	int t;
	long long ans=0,tans=0;
	top=0;

	cou1[0]=cou2[0]=0;
	height[M+1]=0;
	for(int i=1;i<=M;++i)
		if(height[i]<K)
		{
			top=0;
			cou1[i]=cou2[i]=0;
			if(sa[i]<N) ++cou1[i];
			else if(sa[i]>N) ++cou2[i];
		}
		else
		{
			tans=0;
			while(top && sh[top-1]>=height[i]) --top;

			if(top) tans=sa2[top-1]+(cou1[i-1]-cou1[sp[top-1]-1])*(height[i]-K+1);
			else tans=cou1[i-1]*(height[i]-K+1);
			sa2[top]=tans;

			if(top) tans=sa1[top-1]+(cou2[i-1]-cou2[sp[top-1]-1])*(height[i]-K+1);
			else tans=cou2[i-1]*(height[i]-K+1);
			sa1[top]=tans;

			if(sa[i]>N) ans+=sa2[top];
			else if(sa[i]<N) ans+=sa1[top];

			sh[top]=height[i];
			sp[top]=i;
			++top;

			cou1[i]=cou1[i-1]+(sa[i]<N);
			cou2[i]=cou2[i-1]+(sa[i]>N);
		}

	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&K) && K)
	{
		scanf("%s",s);
		N=strlen(s);
		s[N]='#';
		scanf("%s",s+N+1);
		M=N+strlen(s+N+1)+1;

		DA(s,M+1,128);
		getHeight(s,M,rank,height);

		printf("%lld\n",getans());
	}
	
	return 0;
}
