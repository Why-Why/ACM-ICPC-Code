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
// Created Time  : 2015年05月12日 星期二 22时39分47秒
// File Name     : 1015.cpp

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

int dp[30][1000];
int mid=500;
int n,m;
int D[300],P[300];
vector <int> rem[30][1000];

void showans(int d)
{
	int sum1=0,sum2=0;
	int ans[30];

	for(int i=m-1;i>=0;--i)
	{
		ans[i]=rem[m][mid+d][i];
		sum1+=D[ans[i]];
		sum2+=P[ans[i]];
	}

	printf("Best jury has value %d for prosecution and value %d for defence: \n",sum1,sum2);

	for(int i=0;i<m;++i)
		printf(" %d",ans[i]);
	puts("");
	puts("");
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas=1;

	while(~scanf("%d %d",&n,&m) && n+m)
	{
		memset(dp,-1,sizeof(dp));

		for(int i=0;i<30;++i)
			for(int j=0;j<1000;++j)
				rem[i][j].clear();

		for(int i=1;i<=n;++i)
			scanf("%d %d",&D[i],&P[i]);

		dp[0][mid]=0;

		for(int i=1;i<=n;++i)
			for(int j=m;j>=1;--j)
				for(int d=-400;d<=400;++d)
					if(d-D[i]+P[i]>=-400 && d-D[i]+P[i]<=400 && dp[j-1][d+mid-D[i]+P[i]]!=-1 && dp[j-1][d+mid-D[i]+P[i]]+D[i]+P[i]>dp[j][d+mid])
					{
						dp[j][d+mid]=dp[j-1][d+mid-D[i]+P[i]]+D[i]+P[i];
						rem[j][d+mid]=rem[j-1][d+mid-D[i]+P[i]];
						rem[j][d+mid].push_back(i);
					}

		printf("Jury #%d\n",cas++);

		for(int i=0;i<=400;++i)
			if(dp[m][mid+i]!=-1 || dp[m][mid-i]!=-1)
			{
				if(dp[m][mid+i]>=dp[m][mid-i])
					showans(i);
				else
					showans(-i);

				break;
			}
	}

	return 0;
}
