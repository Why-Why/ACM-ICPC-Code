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
// Created Time  : 2015年10月19日 星期一 21时12分57秒
// File Name     : G.cpp

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

int sa[MaxN];
int wa[MaxN],wb[MaxN],wv[MaxN],ts[MaxN];

bool cmp(int r[],int a,int b,int l)
{
	return r[a]==r[b] && r[a+l]==r[b+l];
}

void DA(int num[],int n,int m)
{
	int i,j,p,*x=wa,*y=wb;

	for(i=0;i<m;++i) ts[i]=0;
	for(i=0;i<n;++i) ++ts[x[i]=num[i]];
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
		for(k ? --k : 0, j=sa[rank[i]-1];s[i+k]==s[j+k];++k);

	logN[0]=-1;
	for(int i=1;i<=n;++i)
	{
		logN[i]=logN[i-1]+((i&(i-1))==0) ? 1 : 0;
		dp[i][0]=height[i];
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
char s[MaxN];
int num[MaxN];

bool judge(int p1,int l1,int p2,int l2)
{
	if(p1==p2) return l1>l2;
	int t=query(p1,p2);

	if(t>=min(l1,l2)) return l1>l2;
	return rank[p1]>rank[p2];
}

void getans()
{
	int ans=1,rp=0,rl=N;
	int t,r,tt,tp;

	for(int L=1;L<N;++L)
		for(int i=0;i+L<N;i+=L)
		{
			t=query(i,i+L);
			tt=(t+L)/L;
			r=t%L;
			tp=i;
			if(r && i-L+r>=0 && (t=(query(i-L+r,i+r)+L)/L)>tt)
			{
				tt=t;
				tp=i-L+r;
			}

			if(tt>ans) { ans=tt; rp=tp; rl=L; }
			else if(tt==ans && judge(rp,rl*ans,i,L*ans)) { rp=tp; rl=L; }

			cout<<ans<<' '<<rp<<' '<<rl<<endl;
		}

	s[rp+rl*ans]=0;
	printf("%s\n",s+rp);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas=1;

	while(~scanf("%s",s) && (s[0]!='#' || s[1]))
	{
		N=strlen(s);
		for(int i=0;i<=N;++i) num[i]=s[i];
		DA(num,N+1,128);
		getHeight(num,N,rank,height);

		printf("Case %d: ",cas++);
		getans();
	}
	
	return 0;
}
