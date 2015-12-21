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
// Created Time  : 2015年12月10日 星期四 00时06分11秒
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

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;
	int cou=0,qian=0;
	int x,y,z;

	scanf("%d %d %d",&a,&b,&c);
	scanf("%d %d %d",&x,&y,&z);

	if(a>=x) cou+=(a-x)/2;
	else qian+=x-a;
	if(b>=y) cou+=(b-y)/2;
	else qian+=y-b;
	if(c>=z) cou+=(c-z)/2;
	else qian+=z-c;

	if(cou>=qian) puts("Yes");
	else puts("No");
	
	return 0;
}
