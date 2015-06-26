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
// Created Time  : 2015年05月10日 星期日 20时57分20秒
// File Name     : 1837.cpp

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

const int Mid=8000;

long long dp[25][16000];
int C,G;
int gou[30],wei[30];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&C,&G))
	{
		for(int i=1;i<=C;++i)
			scanf("%d",&gou[i]);

		for(int i=1;i<=G;++i)
			scanf("%d",&wei[i]);

		dp[0][Mid]=1;

		for(int i=1;i<=G;++i)
			for(int j=0;j<16000;++j)
				for(int k=1;k<=C;++k)
					if(j-gou[k]*wei[i]>=0 && j-gou[k]*wei[i]<16000)
						dp[i][j]+=dp[i-1][j-gou[k]*wei[i]];

		printf("%lld\n",dp[G][Mid]);
	}
	
	return 0;
}
