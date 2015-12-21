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
// Created Time  : 2015年09月25日 星期五 20时59分02秒
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

const int MaxN=510;
const int MaxM=MaxN;

// 扩展KMP，复杂度 O(n+m)。
// 输入：s1及其长度n，s2及其长度m。
// 输出：extend(extend[i]表示s1[i...n-1]与s2[0...m-1]的最长公共前缀)，next(s2[i...m-1]与s2[0...m-1]的最长公共前缀)。
// 注意：字符串从0开始。
// 原理：KMP的next数组跳转的原理，记录最远位置p。

void EKMP_pre(int m,char s[],int next[])
{
	int p=0,a=1,L;

	next[0]=m;

	while(p+1<m && s[p]==s[p+1])
		++p;
	next[1]=p;

	for(int k=2;k<m;++k)
	{
		L=next[k-a];
		p=next[a]+a-(next[a]!=0);			/////

		if(k+L-1<p)
			next[k]=L;
		else
		{
			++p;
			while(p<m && s[p]==s[p-k])
				++p;

			next[k]=p-k;
			a=k;
		}
	}
}

char s[MaxN];
int next1[MaxN][MaxN];
int len;

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[MaxN<<2];
bool COL[MaxN<<2];

void pushUP(int po)
{
	BIT[po]=BIT[lc]+BIT[rc];
}

void pushDown(int po)
{
	if(COL[po])
	{
		COL[po]=0;
		COL[lc]=COL[rc]=1;
		BIT[lc]=BIT[rc]=0;
	}
}

void update(int ul,int ur,int L,int R,int po)
{
	if(ul<=L && ur>=R)
	{
		BIT[po]=0;
		COL[po]=1;
		return;
	}

	pushDown(po);
	int M=(L+R)>>1;

	if(ul<=M) update(ul,ur,lson);
	if(ur>M) update(ul,ur,rson);

	pushUP(po);
}

void update_1(int up,int ut,int L,int R,int po)
{
	if(L==R)
	{
		BIT[po]+=ut;
		COL[po]=0;
		return;
	}

	pushDown(po);
	int M=(L+R)>>1;

	if(up<=M) update_1(up,ut,lson);
	else update_1(up,ut,rson);
	
	pushUP(po);
}

void build(int L,int R,int po)
{
	BIT[po]=R-L+1;
	COL[po]=0;
	if(L==R) return;
	int M=(L+R)>>1;
	build(lson);
	build(rson);
}

int query(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return BIT[po];
	pushDown(po);
	int M=(L+R)>>1;
	int ret=0;
	if(ql<=M) ret+=query(ql,qr,lson);
	if(qr>M) ret+=query(ql,qr,rson);
	return ret;
}

int query(int qp,int L,int R,int po)
{
	if(L==R) return BIT[po];
	pushDown(po);
	int M=(L+R)>>1;
	if(qp<=M) return query(qp,lson);
	else return query(qp,rson);
}

int getlen(int x)
{
	int ret=0;
	while(x)
	{
		++ret;
		x/=10;
	}
	return ret;
}

void judge(int a,int b)
{
	int t=next1[a][b];
	if(t==0) return;
	if(t%(b-a)) return;
	int d=t/(b-a)+1,l=b-a;
	if(d<=1) return;
	if(d==2 && l==2) return;
	if(query(a+1,1,len,1)==0 || query(b+1,1,len,1)==0) return;

	//int ttt=query(a+1,b,1,len,1);
	//if(ttt==1) ttt=b-a;
	update(b+1,b+t,1,len,1);
	update_1(a+1,getlen(d)+(l==1 ? 0 : 2),1,len,1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas=1;
	int t;

	while(~scanf("%s",s) && s[0]!='0')
	{
		len=strlen(s);
		for(int i=0;i<len;++i) EKMP_pre(len-i,s+i,next1[i]+i);
		build(1,len,1);

		for(int i=0;i<len;++i)
			for(int j=i+1;j<len;++j)
				judge(i,j);

		printf("Case %d: %d\n",cas++,BIT[1]);
	}
	
	return 0;
}
