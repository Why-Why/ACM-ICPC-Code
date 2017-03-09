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
// Created Time  : 2015年10月28日 星期三 11时40分51秒
// File Name     : K.cpp

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

// DA算法求后缀数组，复杂度 O(nlogn)。
// 输入：处理后的s，长度n，字符种类数m。
// 输出：sa，height和rank(使用getHeight函数获得)。
// 注意：
// s为原字符串，sa为后缀数组，n为元素个数，m为元素最大值。
// rank[i]表示 s[i~n] 在所有后缀的排名，rank最小值为1，从0到n-1。
// sa[i]表示排名为i的后缀所在的位置，sa[0]是最后补的0，从0到n。
// height[i]表示排名为i和i-1的最长公共前缀，从1到n。
// s从0开始，s[n]=0，0为小于前面所有的一个数，且其余字符均大于0。
// 调用函数为 DA(s,n+1,m);其中m大于最大的那个，getHeight(s,n,rank,height);
// 使用RMQ询问时，需要把后缀通过rank变换，然后再交换为小的在前，然后再把小的加一，两个相等要特判，另外注意是min。

const int MaxN=200005;

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

int rank[MaxN],height[MaxN];
int N,M;
char s[MaxN];
int wei[MaxN];

int minn[11],maxn[11];

const int INF=0x3f3f3f3f;

inline void clear()
{
	for(int i=1;i<=M;++i)
		minn[i]=INF,maxn[i]=-INF;
}

inline bool judge1(int len)
{
	for(int i=1;i<=M;++i)
		if(maxn[i]<=minn[i] || maxn[i]-minn[i]<len)
			return 0;
	return 1;
}

bool judge(int len)
{
	clear();

	for(int i=1;i<=N;++i)
		if(height[i]<len)
		{
			if(judge1(len)) return 1;
			clear();
			if(wei[sa[i]]) minn[wei[sa[i]]]=min(minn[wei[sa[i]]],sa[i]),maxn[wei[sa[i]]]=max(maxn[wei[sa[i]]],sa[i]);
		}
		else if(wei[sa[i]])
			minn[wei[sa[i]]]=min(minn[wei[sa[i]]],sa[i]),maxn[wei[sa[i]]]=max(maxn[wei[sa[i]]],sa[i]);

	return judge1(len);
}

int getans()
{
	int L=0,R=N,Mid;

	while(R>L)
	{
		Mid=(L+R+1)>>1;
		if(judge(Mid)) L=Mid;
		else R=Mid-1;
	}

	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&M);
		N=0;
		for(int i=1;i<=M;++i)
		{
			scanf("%s",s+N);
			for(;s[N];++N) wei[N]=i;
			wei[N]=0;
			s[N++]='#'+i-1;
		}
		s[N]=0;

		DA(s,N+1,128);
		getHeight(s,N,rank,height);

		printf("%d\n",getans());
	}
	
	return 0;
}
