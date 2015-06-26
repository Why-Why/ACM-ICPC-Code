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
// Created Time  : 2015年05月08日 星期五 10时48分42秒
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

long long dp[600][600];
int n,m,b,mod;
int a[600];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d %d",&n,&m,&b,&mod);

	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);

	int cou=1;

	for(int i=0;i<=b;++i)
		dp[0][i]=1;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			for(int k=a[i];k<=b;++k)
			{
				dp[j][k]+=dp[j-1][k-a[i]];
				dp[j][k]%=mod;
			}

	cout<<dp[m][b]%mod<<endl;
	
	return 0;
}
