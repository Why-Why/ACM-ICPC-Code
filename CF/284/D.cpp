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
// Created Time  : 2015年05月21日 星期四 21时00分29秒
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

int T,n;
double dp[5010][5010];
double pre[5010];
int p[5010],t[5010];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&n,&T);

	int cou;
	double temp;
	double ans=0;
	double tp;

	for(int i=1;i<=n;++i)
		scanf("%d %d",&p[i],&t[i]);

	for(int i=1;i<=n;++i)
	{
		pre[i]=1;
		tp=1.0-p[i]/100.0;

		for(int j=0;j<t[i];++j)
			pre[i]*=tp;
	}

	dp[0][0]=1;

	for(int i=1;i<=n;++i)
	{
		cou=1;
		tp=p[i]/100.0;
		temp=dp[i-1][i-1]*tp;

		for(int j=i;j<=T;++j)
		{
			dp[i][j]=temp;

			if(cou==t[i])
				dp[i][j]+=pre[i]*dp[i-1][j-t[i]];

			ans+=dp[i][j];

			++cou;
			temp*=1.0-tp;
			temp+=dp[i-1][j]*tp;

			if(cou>t[i])
			{
				temp-=dp[i-1][j-t[i]]*pre[i]*tp;
				--cou;
			}
		}
	}

	printf("%.10f\n",ans);
	
	return 0;
}
