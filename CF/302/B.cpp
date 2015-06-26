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
// Created Time  : 2015年06月04日 星期四 23时09分01秒
// File Name     : B.cpp

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

int n,k;
bool map1[110][110];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>n>>k;

	if(k>(n*n+1)/2)
	{
		puts("NO");
		return 0;
	}

	int x=1,y=1;
	bool type=1;

	while(k--)
	{
		map1[x][y]=1;

		x+=2;

		if(x>n)
		{
			if(type)
				x=2;
			else
				x=1;

			type=!type;
			++y;
		}
	}

	for(int i=1;i<=n;++i,printf("\n"))
		for(int j=1;j<=n;++j)
			printf("%c",map1[i][j] ? 'L' : 'S');
	
	return 0;
}
