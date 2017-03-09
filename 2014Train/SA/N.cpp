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
// Created Time  : 2015年10月29日 星期四 19时15分38秒
// File Name     : N.cpp

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

const int MaxN=400105;

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

int N;
int num[MaxN];
int hnum[MaxN],hcou;

int rank[MaxN],height[MaxN];

inline int hash(int x)
{
	return lower_bound(hnum,hnum+hcou,x)-hnum;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	hcou=0;
	for(int i=0;i<N;++i)
	{
		scanf("%d",num+i);
		hnum[hcou++]=num[i];
	}
	reverse(num,num+N);
	sort(hnum,hnum+hcou);
	hcou=unique(hnum,hnum+hcou)-hnum;

	for(int i=0;i<N;++i)
		num[i]=hash(num[i])+1;
	num[N]=0;

	int M=N+1;

	DA(num,N+1,M+1);
	int a;
	for(int i=1;i<=N;++i)
		if(sa[i]>=2)
		{
			a=sa[i];
			break;
		}
	for(int i=a;i<N;++i) printf("%d\n",hnum[num[i]-1]);

	N=a;
	for(int i=0;i<a;++i,++N) num[N]=num[i];
	num[N]=0;
	DA(num,N+1,M+1);

	int b;
	for(int i=1;i<=N;++i)
		if(sa[i]>=1 && sa[i]<a)
		{
			b=sa[i];
			break;
		}
	for(int i=b;i<a;++i) printf("%d\n",hnum[num[i]-1]);
	for(int i=0;i<b;++i) printf("%d\n",hnum[num[i]-1]);
	
	return 0;
}
