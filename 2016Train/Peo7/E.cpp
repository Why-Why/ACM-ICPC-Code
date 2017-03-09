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
// Created Time  : 2016年05月01日 星期日 16时25分25秒
// File Name     : E.cpp

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

const int MaxN=1000005;

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
int next1[MaxN];
int len;

int getans() {
	int p=len/3+1;
	int maxn=-1;
	for(int i=len/3;i>=1;--i) {
		while(p+i-1<=len-i) maxn=max(maxn,next1[p]),++p;
		maxn=max(maxn,next1[i+1]);
		if(next1[len-i+1]>=i && maxn>=i) return i;
	}
	return 0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%s",s+1);
		len=strlen(s+1);

		EKMP_pre(len,s+1,next1+1);

		printf("%d\n",getans());
	}
	
	return 0;
}
