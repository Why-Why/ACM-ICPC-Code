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
// Created Time  : 2015年06月03日 星期三 14时56分56秒
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

int n,m;
bool man[110],nv[110];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d %d",&n,&m);

	scanf("%d",&a);
	
	while(a--)
	{
		scanf("%d",&b);
		man[b]=1;
	}

	scanf("%d",&a);

	while(a--)
	{
		scanf("%d",&b);
		nv[b]=1;
	}

	for(int i=0;i<=n*m+16;++i)
		if(man[i%n] || nv[i%m])
			man[i%n]=nv[i%m]=1;

	bool ok=1;

	for(int i=0;i<n;++i)
		if(!man[i])
			ok=0;

	for(int i=0;i<m;++i)
		if(!nv[i])
			ok=0;

	if(ok)
		puts("Yes");
	else puts("No");
	
	return 0;
}
