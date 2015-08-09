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
// Created Time  : 2015年07月20日 星期一 09时57分41秒
// File Name     : 2029.cpp

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

int W,H;
int N;
int map1[110][110];
int S,T;

int sum(int x1,int y1,int x2,int y2)
{
	return map1[x2][y2]-map1[x1-1][y2]-map1[x2][y1-1]+map1[x1-1][y1-1];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	while(~scanf("%d",&N) && N)
	{
		memset(map1,0,sizeof(map1));
		scanf("%d %d",&W,&H);

		for(int i=1;i<=N;++i)
		{
			scanf("%d %d",&a,&b);
			map1[a][b]=1;
		}

		scanf("%d %d",&S,&T);

		for(int i=1;i<=W;++i)
			for(int j=1;j<=H;++j)
				map1[i][j]+=map1[i][j-1];

		for(int j=1;j<=H;++j)
			for(int i=1;i<=W;++i)
				map1[i][j]+=map1[i-1][j];

		int ans=0;

		for(int i=1;i+S-1<=W;++i)
			for(int j=1;j+T-1<=H;++j)
				ans=max(ans,sum(i,j,i+S-1,j+T-1));

		printf("%d\n",ans);
	}
	
	return 0;
}
