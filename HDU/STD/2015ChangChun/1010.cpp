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
// Created Time  : 2015年11月01日 星期日 13时25分58秒
// File Name     : 1010.cpp

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

const int MaxN=1010;

int N;
long long num[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--)
	{
		long long maxn=0;
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%I64d",num+i);
		for(int i=1;i<=N;++i)
			for(int j=i+1;j<=N;++j)
				for(int k=j+1;k<=N;++k)
					maxn=max(maxn,max(num[i]^(num[j]+num[k]),max(num[j]^(num[i]+num[k]),num[k]^(num[i]+num[j]))));
		printf("%I64d\n",maxn);
	}
	
	return 0;
}
