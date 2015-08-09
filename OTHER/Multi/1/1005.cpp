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
// Created Time  : 2015年07月21日 星期二 15时33分57秒
// File Name     : 1005.cpp

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

int map1[30];

int change(char c)
{
	switch(c)
	{
		case 'g':
			return 1;
		case 'y':
			return 2;
		case 'o':
			return 3;
		case 'w':
			return 4;
		case 'r':
			return 5;
		case 'b':
			return 6;
	}

	return 0;
}

int rem[10][10];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	char s[10];

	scanf("%d",&T);

	while(T--)
	{
		for(int i=1;i<=24;++i)
		{
			scanf("%s",s);
			map1[i]=change(s[0]);
		}
	}
	
	return 0;
}
