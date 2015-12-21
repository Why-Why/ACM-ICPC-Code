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
// Created Time  : 2015年10月29日 星期四 19时34分02秒
// File Name     : O.cpp

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

const int MaxN=1010;

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

char s[MaxN];
int N,M;
int num[MaxN],wei[MaxN];
int rank[MaxN],height[MaxN];

int vis[4010],flag=1;

bool judge(int len)
{
	++flag;
	int cou=0;

	for(int i=1;i<=N;++i)
		if(height[i]<len)
		{
			if(cou==M) return 1;
			++flag;
			cou=0;
			if(wei[sa[i]])
			{
				vis[wei[sa[i]]]=flag;
				cou=1;
			}
		}
		else if(wei[sa[i]] && vis[wei[sa[i]]]!=flag)
		{
			vis[wei[sa[i]]]=flag;
			++cou;
		}
	return cou==M;
}

void show(int len)
{
	int cou=0;
	++flag;

	for(int i=1;i<=N;++i)
		if(height[i]<len)
		{
			if(cou==M)
			{
				s[sa[i-1]+len]=0;
				puts(s+sa[i-1]);
				return;
			}
			++flag;
			cou=0;
			if(wei[sa[i]])
			{
				vis[wei[sa[i]]]=flag;
				cou=1;
			}
		}
		else if(wei[sa[i]] && vis[wei[sa[i]]]!=flag)
		{
			vis[wei[sa[i]]]=flag;
			++cou;
		}

	s[sa[N]+len]=0;
	puts(s+sa[N]);
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
	if(L>=3) show(L);
	else puts("no significant commonalities");
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
			for(;s[N];++N)
				num[N]=s[N],wei[N]=i;
			num[N]='Z'+i;
			s[N]='#';
			wei[N++]=0;
		}
		s[N]=0;
		num[N]=0;
		DA(num,N+1,128);
		getHeight(num,N,rank,height);
		getans();
	}
	
	return 0;
}
