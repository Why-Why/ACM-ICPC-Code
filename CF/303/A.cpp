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
// Created Time  : 2015年05月21日 星期四 19时47分05秒
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

int map1[110][110];
int n;

bool judge(int hang)
{
	for(int i=1;i<=n;++i)
		if(map1[hang][i]==1 || map1[hang][i]==3)
			return 0;

	for(int i=1;i<=n;++i)
		if(map1[i][hang]==2 || map1[i][hang]==3)
			return 0;

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&n);

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&map1[i][j]);

	int cou=0;
	int ans[110];

	for(int i=1;i<=n;++i)
		if(judge(i))
			ans[cou++]=i;

	printf("%d\n",cou);

	if(!cou)
		return 0;

	for(int i=0;i<cou;++i)
		printf("%d ",ans[i]);

	puts("");
	
	return 0;
}
