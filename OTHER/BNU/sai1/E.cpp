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
// Created Time  : 2015年10月01日 星期四 09时15分00秒
// File Name     : E.cpp

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

long long getb(int hang,int zong)
{
	return max(0LL,zong/2LL-hang);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n,m,k;

	while(~scanf("%d %d %d",&n,&m,&k))
	{
		long long ans=0;
		long long d;
		for(int i=1;i<=n;++i)
		{
			d=min((long long)m,getb(i,k));
			ans+=(n+1LL-i)*d*(2LL*m+1LL-d)/2;
		}

		printf("%lld\n",ans);
	}
	
	return 0;
}
