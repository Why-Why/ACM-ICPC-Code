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
// Created Time  : 2015年06月27日 星期六 22时19分06秒
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

int cou[100005];
int num[100005];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,K;
	int m,t;
	bool first;
	long long ans;

	scanf("%d %d",&N,&K);

	ans=0;
	first=0;

	for(int i=1;i<=K;++i)
	{
		scanf("%d",&m);
		ans+=m-1;

		for(int j=1;j<=m;++j)
		{
			scanf("%d",&t);

			if(first==0 && t==1)
				first=1;
			else if(first && t==j)
				ans-=2;
		}

		first=0;
	}

	ans+=N-1;

	cout<<ans<<endl;
	
	return 0;
}
