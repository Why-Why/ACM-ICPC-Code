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
// Created Time  : 2015年06月19日 星期五 00时56分20秒
// File Name     : C.cpp

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

long long w,m;

bool getans(int d,long long w,long long m)
{
	if(m%w && (m+1)%w && (m-1)%w)
		return 0;

	if(d>100)
		return m==0;

	if(m==0)
		return 1;

	if(m%w==0)
		return getans(d+1,w,m/w);

	if((m+1)%w==0)
		return getans(d+1,w,(m+1)/w);

	if((m-1)%w==0)
		return getans(d+1,w,(m-1)/w);

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>w>>m;

	if(w==2)
	{
		puts("YES");
		return 0;
	}

	if(getans(0,w,m))
		puts("YES");
	else
		puts("NO");
	
	return 0;
}
