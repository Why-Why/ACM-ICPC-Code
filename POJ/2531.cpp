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
// Created Time  : 2015年05月27日 星期三 11时34分06秒
// File Name     : 2531.cpp

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

int n;
int map1[30][30];
int ans;

int getans(int x)
{
	int ret=0;
	int A[30],acou=0,B[30],bcou=0;

	A[acou++]=n;

	for(int i=0;i<(n-1);++i)
		if((1<<i) & x)
			A[acou++]=i+1;
		else
			B[bcou++]=i+1;

	for(int i=0;i<acou;++i)
		for(int j=0;j<bcou;++j)
			ret+=map1[A[i]][B[j]];

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&n))
	{
		ans=0;

		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",&map1[i][j]);

		for(int i=0;i<(1<<(n-1));++i)
			ans=max(ans,getans(i));

		printf("%d\n",ans);
	}
	
	return 0;
}
