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
// Created Time  : 2015年05月21日 星期四 11时45分37秒
// File Name     : D_3.cpp

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

long long dp[1100][110][2];
int n,k,mod;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long base=10;
	long long t;

	cin>>n>>k>>mod;

	for(int i=1;i<10;++i)
		(++dp[1][i%k][(i%k==0)])%=mod;
	dp[1][0][0]=1;

	for(int i=1;i<n;++i)
	{
		for(int j=0;j<k;++j)
			for(int r=0;r<10;++r)
			{
				if(i==n-1 && r==0)
					continue;

				t=(j+r*base)%k;
				(dp[i+1][t][1]+=dp[i][j][1])%=mod;

				if(t==0 && r)
					(dp[i+1][0][1]+=dp[i][j][0])%=mod;
				else
					(dp[i+1][t][0]+=dp[i][j][0])%=mod;
			}

		(base*=10)%=k;
	}

	long long ans=0;

	for(int i=0;i<k;++i)
		(ans+=dp[n][i][1])%=mod;

	cout<<ans<<endl;
	
	return 0;
}
