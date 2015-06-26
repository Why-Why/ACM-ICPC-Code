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
// Created Time  : 2015年05月23日 星期六 22时04分01秒
// File Name     : 1003.cpp

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

set <long long> sta;
int num[1010][4];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int n,m;
	int a,b,c,d;
	long long t;

	scanf("%d",&T);

	while(T--)
	{
		sta.clear();
		scanf("%d %d",&n,&m);

		for(int i=1;i<=n;++i)
			scanf("%d.%d.%d.%d",&num[i][0],&num[i][1],&num[i][2],&num[i][3]);

		printf("Case #%d:\n",cas++);

		while(m--)
		{
			scanf("%d.%d.%d.%d",&a,&b,&c,&d);
			sta.clear();
			
			for(int i=1;i<=n;++i)
			{
				t=((long long)(num[i][0]&a)<<24LL)+((long long)(num[i][1]&b)<<16LL)+((long long)(num[i][2]&c)<<8LL)+(long long)(num[i][3]&d);

				sta.insert(t);
			}

			printf("%d\n",(int)sta.size());
		}
	}
	
	return 0;
}
