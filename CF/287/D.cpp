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
// Created Time  : 2015年05月19日 星期二 16时47分35秒
// File Name     : D.cpp

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

int n,k,m;
long long dp[1010][110];
long long sum[1010];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&n,&k,&m);

	for(int i=1;i<10;++i)
		dp[1][i%k]=(dp[1][i%k]+1)%m;

	for(int i=2;i<=n;++i)
		for(int j=0;j<10;++j)
		{
			++dp[i][j%k];
			dp[i][j%k]%=m;

			for(int y=0;y<k;++y)
				if(((y+11*k-j)%k)%(10%k)==0)
					dp[i][y]=(dp[i][y]+dp[i-1][((y+11*k-j)%k)/(10%k)])%m;
		}

	for(int i=1;i<=n;++i,cout<<endl)
		for(int j=0;j<k;++j)
			cout<<dp[i][j]<<' ';

	cout<<dp[n][0]%m<<endl;
	
	return 0;
}
