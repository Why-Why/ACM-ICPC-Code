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
// Created Time  : 2015年10月07日 星期三 19时45分15秒
// File Name     : D_1.cpp

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

const int MaxN=101000;

long long cou[MaxN];
int ans[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int a,x;
	int N;
	int maxn;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		memset(cou,0,sizeof(cou));
		memset(ans,0,sizeof(ans));
		maxn=0;
		while(N--)
		{
			scanf("%d %d",&a,&x);
			cou[a]+=x;
			maxn=max(maxn,a);
		}

		int last=-1;

		for(int i=maxn;i>=0;--i)
			if(last==-1)
			{
				if(cou[i] & 1)
				{
					last=0;
				}
			}
	}
	
	return 0;
}
