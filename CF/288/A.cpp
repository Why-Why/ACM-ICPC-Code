// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年06月03日 星期三 20时04分54秒
// File Name     : A.cpp

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

int n,m,k;

int map1[1010][1010];

bool judge(int x,int y)
{
	if(map1[x-1][y-1]+map1[x-1][y]+map1[x][y-1]+map1[x][y]==4)
		return 1;

	if(map1[x][y-1]+map1[x][y]+map1[x+1][y-1]+map1[x+1][y]==4)
		return 1;

	if(map1[x-1][y+1]+map1[x-1][y]+map1[x][y+1]+map1[x][y]==4)
		return 1;

	if(map1[x][y+1]+map1[x][y]+map1[x+1][y+1]+map1[x+1][y]==4)
		return 1;

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d %d %d",&n,&m,&k);

	for(int i=1;i<=k;++i)
	{
		scanf("%d %d",&a,&b);

		map1[a][b]=1;

		if(judge(a,b))
		{
			printf("%d\n",i);
			return 0;
		}
	}

	printf("0\n");
	
	return 0;
}
