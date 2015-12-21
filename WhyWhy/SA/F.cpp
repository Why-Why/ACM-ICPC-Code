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
// Created Time  : 2015年10月15日 星期四 23时59分58秒
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

using namespace std;

const int MaxN=50004;

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

int dp[MaxN][20];
int logN[MaxN];
int height[MaxN],rank[MaxN];

void getHeight(int s[],int n,int rank[],int height[])
{
	int k=0,i,j;

	for(i=1;i<=n;++i) rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
		for(k ? k-- : 0 , j=sa[rank[i]-1];s[i+k]==s[j+k];++k);

	logN[0]=-1;

	for(int i=1;i<=n;++i)
	{
		dp[i][0]=height[i];
		logN[i]=((i&(i-1))==0) ? logN[i-1]+1 : logN[i-1];
	}

	for(int j=1;j<=logN[n];++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int query(int x,int y)
{
	x=rank[x];
	y=rank[y];
	if(x>y) swap(x,y);
	++x;
	int k=logN[y-x+1];
	return min(dp[x][k],dp[y-(1<<k)+1][k]);
}

int N;
int num[MaxN];

int getans()
{
	int ans=1;
	int t,r,b;

	for(int L=1;L<=N;++L)
		for(int i=0;i+L<N;i+=L)
		{
			t=query(i,i+L);
			if(t<L) continue;
			r=t%L;
			ans=max(ans,(t+L)/L);
			if(i-L+r>=0)
			{
				b=query(i-L+r,i+r);
				ans=max(ans,(b+L)/L);
			}
		}

	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	char c;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		getchar();
		for(int i=0;i<N;++i)
		{
			c=getchar();
			getchar();
			num[i]=c-'a'+1;
		}
		num[N]=0;

		DA(num,N+1,3);
		getHeight(num,N,rank,height);

		printf("%d\n",getans());
	}
	
	return 0;
}
