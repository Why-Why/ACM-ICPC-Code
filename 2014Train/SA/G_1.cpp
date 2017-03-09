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
// Created Time  : 2015年10月28日 星期三 09时27分00秒
// File Name     : G_1.cpp

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

int sa[MaxN],rank[MaxN],height[MaxN];
int wa[MaxN],wb[MaxN],wv[MaxN],ts[MaxN];

bool cmp(int r[],int a,int b,int l)
{
	return r[a]==r[b] && r[a+l]==r[b+l];
}

void DA(char s[],int n,int m)
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

int logN[MaxN];
int dp[MaxN][20];

void getHeight(char s[],int n)
{
	int k=0,i,j;

	for(i=1;i<=n;++i) rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
		for(k ? k-- : 0, j=sa[rank[i]-1];s[i+k]==s[j+k];++k);

	logN[0]=-1;
	for(i=1;i<=n;++i)
	{
		logN[i]=logN[i-1]+((i&(i-1)) ? 0 : 1);
		dp[i][0]=height[i];
	}

	for(j=1;j<=logN[n];++j)
		for(i=1;i+(1<<j)-1<=n;++i)
			dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int query(int a,int b)
{
	a=rank[a];
	b=rank[b];
	if(a>b) swap(a,b);
	++a;

	int k=logN[b-a+1];
	return min(dp[a][k],dp[b-(1<<k)+1][k]);
}

char s[MaxN];
int N;

int rlen[MaxN],rcou;

int getans()
{
	int rt=-1;
	rcou=0;

	int t,r,tans;

	for(int L=1;L<=N;++L)
		for(int i=0;i+L<N;i+=L)
		{
			t=query(i,i+L);
			tans=(t+L)/L;
			r=t%L;
			if(r && i-(L-r)>=0) tans=max(tans,(query(i-(L-r),i+r)+L)/L);

			if(tans>rt)
			{
				rt=tans;
				rcou=1;
				rlen[0]=L;
			}
			else if(tans==rt)
				rlen[rcou++]=L;
		}

	for(int i=1;i<=N;++i)
		for(int j=0;j<rcou;++j)
			if(sa[i]+rlen[j]<N && query(sa[i],sa[i]+rlen[j])>=rlen[j]*(rt-1))
			{
				s[sa[i]+rlen[j]*rt]=0;
				return sa[i];
			}

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int cas=1;

	while(~scanf("%s",s) && (s[0]!='#' || s[1]))
	{
		N=strlen(s);
		DA(s,N+1,128);
		getHeight(s,N);
		printf("Case %d: %s\n",cas++,s+getans());
	}
	
	return 0;
}
