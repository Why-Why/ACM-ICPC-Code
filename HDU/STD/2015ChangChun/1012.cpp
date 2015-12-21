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
// Created Time  : 2015年11月01日 星期日 14时46分10秒
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

int N,M;
int map1[55][55];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);
		memset(map1,0,sizeof(map1));
		for(int i=1;i<=N;++i) for(int j=1;j<=M;++j) scanf("%d",&map1[i][j]);

		int ans=0;
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
				if(map1[i][j])
				{
					++ans;
					ans+=max(0,map1[i][j]-map1[i][j-1]);
					ans+=max(0,map1[i][j]-map1[i][j+1]);
					ans+=max(0,map1[i][j]-map1[i-1][j]);
					ans+=max(0,map1[i][j]-map1[i+1][j]);
				}
		printf("%d\n",ans);
	}
	
	return 0;
}
