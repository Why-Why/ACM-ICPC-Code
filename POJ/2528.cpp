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
// Created Time  : 2015年06月25日 星期四 00时02分13秒
// File Name     : 2528.cpp

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

#define lc po*2
#define rc po*2+1
#define lson L,M,lc
#define rson M+1,R,rc

const int MaxN=20005;

int BIT[MaxN<<2];
int COL[MaxN<<2];

void pushUP(int po)
{
	BIT[po]=BIT[lc]+BIT[rc];
}

void pushDown(int po,int len)
{
	if(COL[po])
	{
		COL[lc]=COL[rc]=1;
		BIT[lc]=(len+1)/2;
		BIT[rc]=len-BIT[lc];
		COL[po]=0;
	}
}

void build_tree(int L,int R,int po)
{
	if(L==R)
	{
		BIT[po]
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	return 0;
}
