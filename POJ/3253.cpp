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
// Created Time  : 2015年05月07日 星期四 19时47分19秒
// File Name     : 3253.cpp

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
long long ans;
priority_queue <long long,vector <long long>,greater<long long> > que;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long a,b;

	while(~scanf("%d",&N))
	{
		while(!que.empty())
			que.pop();

		ans=0;

		while(N--)
		{
			scanf("%lld",&a);
			que.push(a);
		}

		while(que.size()>1)
		{
			a=que.top();
			que.pop();
			b=que.top();
			que.pop();

			ans+=a+b;
			que.push(a+b);
		}

		printf("%lld\n",ans);
	}
	
	return 0;
}
