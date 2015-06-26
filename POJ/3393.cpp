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
// Created Time  : 2015年06月18日 星期四 20时46分30秒
// File Name     : 3393.cpp

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

int rem[10004][14];
int y1,m1,y2,m2;

void getans()
{
	int ans1=0,ans2=0;

	for(int i=y1+1;i<y2;++i)
		for(int j=1;j<=12;++j)
		{
			if(rem[i][j]==1 || rem[i][j]==3)
				++ans1;
			if(rem[i][j]==2 || rem[i][j]==3)
				++ans2;
		}

	for(int i=m1;i<=12;++i)
	{
		if(rem[y1][i]==1 || rem[y1][j]==3)
			++ans1;
		if(rem[y1][i]==2 || rem[y1][i]==3)
			++ans2;
	}

	for(int i=1;i<=m2;++i)
	{
		if(rem[y2][i]==1 || rem[y2][i]==3)
			++ans1;
		if(rem[y2][i]==2 || rem[y2][i]==3)
			++ans2;
	}

	printf("%d %d\n",ans1,ans2);
}

void init()
{
	for(int i
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	init();

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d %d",&y1,&m1,&y2,&m2);
		getans();
	}
	
	return 0;
}
