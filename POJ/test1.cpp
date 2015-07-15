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
// Created Time  : 2015年06月30日 星期二 23时54分56秒
// File Name     : test1.cpp

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

int ans[1000];
int N;

void insert(int a,int b,int N)
{
	for(int i=N+1;i>a+1;--i)
		ans[i]=ans[i-1];

	ans[a+1]=b;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out2.txt","w",stdout);

	while(cin>>N)
	{
		int a,b;

		for(int i=1;i<=N;++i)
		{
			cin>>a>>b;
			insert(a,b,i-1);
		}

		cout<<ans[1];
		for(int i=2;i<=N;++i)
			cout<<' '<<ans[i];
		cout<<endl;
	}
	
	return 0;
}
