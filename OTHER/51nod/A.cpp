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
// Created Time  : 2015年07月03日 星期五 20时02分40秒
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

int N;
int num[1000];
int rem[1000];

bool getans()
{
	int p=1,cou=1;
	rem[1]=num[1];

	for(int i=2;i<=N;++i)
	{
		if(p<=cou && num[i]==rem[p])
			++p;
		else
			rem[++cou]=num[i];
	}

	cout<<cou<<endl;

	for(int i=1;i<=cou;++i)
		cout<<rem[i]<<' ';
	cout<<endl;

	return cou*2==N;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		if(getans())
			puts("Good job!!");
		else
			puts("What a pity!");
	}
	
	return 0;
}
