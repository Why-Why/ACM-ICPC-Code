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
// Created Time  : 2016年04月23日 星期六 15时17分35秒
// File Name     : t.cpp

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

const int MaxN=1000000;

void EKMP_pre(int m,int s[],int next[])
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

int num[MaxN];
int next1[MaxN];
int cou;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(cin>>num[cou++]);
	--cou;
	EKMP_pre(cou,num,next1);

	for(int i=1;i<cou;++i)
		if(next1[i]==cou-i) { cout<<i<<endl; break; }

	int sum=0;
	for(int i=0;i<56;++i) sum+=num[i];
	cout<<sum<<endl;
	
	return 0;
}
