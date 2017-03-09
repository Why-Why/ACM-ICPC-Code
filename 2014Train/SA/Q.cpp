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
// Created Time  : 2015年10月30日 星期五 09时28分25秒
// File Name     : Q.cpp

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

const int MAXN = 50300;

#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)

int wa[MAXN*3],wb[MAXN*3],wv[MAXN*3],wss[MAXN*3];

int c0(int *r,int a,int b)
{
	return r[a] == r[b] && r[a+1] == r[b+1] && r[a+2] == r[b+2];
}

int c12(int k,int *r,int a,int b)
{
	if(k == 2) return r[a] < r[b] || ( r[a] == r[b] && c12(1,r,a+1,b+1) );
	else return r[a] < r[b] || ( r[a] == r[b] && wv[a+1] < wv[b+1] );
}

void sort(int *r,int *a,int *b,int n,int m)
{
	int i;
	for(i = 0;i < n;i++)wv[i] = r[a[i]];
	for(i = 0;i < m;i++)wss[i] = 0;
	for(i = 0;i < n;i++)wss[wv[i]]++;
	for(i = 1;i < m;i++)wss[i] += wss[i-1];
	for(i = n-1;i >= 0;i--)
	b[--wss[wv[i]]] = a[i];
}

void dc3(int *r,int *sa,int n,int m)
{
	int i, j, *rn = r + n;
	int *san = sa + n, ta = 0, tb = (n+1)/3, tbc = 0, p;
	
	r[n] = r[n+1] = 0;
	for(i = 0;i < n;i++) if(i %3 != 0) wa[tbc++] = i;
	sort(r + 2, wa, wb, tbc, m);
	sort(r + 1, wb, wa, tbc, m);
	sort(r, wa, wb, tbc, m);
	for(p = 1, rn[F(wb[0])] = 0, i = 1;i < tbc;i++)
		rn[F(wb[i])] = c0(r, wb[i-1], wb[i]) ? p - 1 : p++;
	if(p < tbc) dc3(rn,san,tbc,p);
	else for(i = 0;i < tbc;i++) san[rn[i]] = i;
	for(i = 0;i < tbc;i++) if(san[i] < tb) wb[ta++] = san[i] * 3;
	if(n % 3 == 1) wb[ta++] = n - 1;
	sort(r, wb, wa, ta, m);
	for(i = 0;i < tbc;i++) wv[wb[i] = G(san[i])] = i;
	for(i = 0, j = 0, p = 0;i < ta && j < tbc;p++)
		sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
	for(;i < ta;p++) sa[p] = wa[i++];
	for(;j < tbc;p++) sa[p] = wb[j++];
}

int dp[MAXN][20];
int logN[MAXN];

//str和sa也要三倍
void da(int str[],int sa[],int rank[],int height[],int n,int m)
{
	for(int i = n;i < n*3;i++) str[i] = 0;
	dc3(str, sa, n+1, m);
	int i,j,k = 0;
	for(i = 0;i <= n;i++) rank[sa[i]] = i;
	for(i = 0;i < n; i++)
	{
		if(k) k--;
		j = sa[rank[i]-1];
		while(str[i+k] == str[j+k]) k++;
		height[rank[i]] = k;
	}

	logN[0]=-1;
	for(int i=1;i<=n;++i)
	{
		dp[i][0]=height[i];
		logN[i]=logN[i-1]+(((i&(i-1))) ? 0 : 1);
	}
	for(int j=1;j<=logN[n];++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int sa[MAXN*3],rank[MAXN*3],height[MAXN*3];

int query(int a,int b)
{
	a=rank[a];
	b=rank[b];
	if(a>b) swap(a,b);
	++a;
	int k=logN[b-a+1];
	return min(dp[a][k],dp[b-(1<<k)+1][k]);
}

char s[MAXN];
int N;
int str[MAXN*3];
int wei[MAXN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%s",s);
	int M;
	char ts[5];
	int a,b;
	bool change=1;
	scanf("%d",&M);

	N=0;
	for(int i=0;s[i];++i,++N) str[N]=s[i],wei[N]=i;
	str[N]=0;

	while(M--)
	{
		scanf("%s",ts);
		if(ts[0]=='Q')
		{
			if(change) da(str,sa,rank,height,N,128),change=0;

			scanf("%d %d",&a,&b);
			a=lower_bound(wei,wei+N,a-1)-wei;
			b=lower_bound(wei,wei+N,b-1)-wei;
			if(a==b) printf("%d\n",N-a);
			else printf("%d\n",query(a,b));
		}
		else
		{
			scanf("%s %d",ts,&a);
			change=1;
			if(a>N) a=N+1;
			--a;
			for(int i=N;i>a;--i) str[i]=str[i-1],wei[i]=wei[i-1];
			str[a]=ts[0];
			if(a) wei[a]=wei[a-1];
			else --wei[a];
			str[++N]=0;
		}
	}
	
	return 0;
}
