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
// Created Time  : 2015年10月07日 星期三 11时00分27秒
// File Name     : C.cpp

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

long long getans(int N,int M,int a)
{
	int L=max(1,a-N),R=min(M,a-1);

	if(R<L) return 0;
	return R-L+1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int N,M;
	int Q,a;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);

		scanf("%d",&Q);
		printf("Case #%d:\n",cas++);
		while(Q--)
		{
			scanf("%d",&a);
			printf("%lld\n",getans(N,M,a));
		}
	}
	
	return 0;
}
