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
// Created Time  : 2016年07月21日 星期四 15时30分11秒
// File Name     : 1012.cpp

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

// 扩展KMP，复杂度 O(n+m)。
// 输入：s1及其长度n，s2及其长度m。
// 输出：extend(extend[i]表示s1[i...n-1]与s2[0...m-1]的最长公共前缀)，next(s2[i...m-1]与s2[0...m-1]的最长公共前缀)。
// 注意：字符串从0开始。
// 原理：KMP的next数组跳转的原理，记录最远位置p。

const int MaxN=100005;
const int MaxM=5005;

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

void EKMP(int n,char s1[],int m,char s2[],int extend[],int next[])
{
	int p=0,a=0,L;

	EKMP_pre(m,s2,next);

	while(p<n && p<m && s1[p]==s2[p])
		++p;

	extend[0]=p;

	for(int k=1;k<n;++k)
	{
		L=next[k-a];
		p=a+extend[a]-(extend[a]!=0);			/////

		if(k+L-1<p)
			extend[k]=L;
		else
		{
			++p;
			while(p<n && p-k<m && s1[p]==s2[p-k])
				++p;

			extend[k]=p-k;
			a=k;
		}
	}
}

int N,M;
int ext[MaxN],next1[MaxN];
char s1[MaxN],s2[MaxN];
char ans[MaxN];

inline bool judge(int p) {
	if(ext[p]==M) return 1;
	if(p+M-1>=N) return 0;

	for(int i=p+ext[p],j=ext[p];j<M;) {
		if(s1[i]==s2[j]) {
			++i;
			++j;
			continue;
		}
		if(j+1<M && s1[i]==s2[j+1] && s1[i+1]==s2[j]) {
			i+=2;
			j+=2;
			continue;
		}
		return 0;
	}
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&N,&M);
		scanf("%s %s",s1,s2);
		EKMP(N,s1,M,s2,ext,next1);

		for(int i=0;i<N;++i)
			if(judge(i)) ans[i]='1';
			else ans[i]='0';

		puts(ans);
	}

	return 0;
}
