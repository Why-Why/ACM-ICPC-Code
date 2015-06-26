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

inline int abs1(int x)
{
	return x<0 ? -x : x;
}

int N,num[10004];
int dp[10004][5][5][2];

void slove()
{
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			dp[0][i][j][0]=dp[0][i][j][1]=i+j;

	for(int k=1;k<=N;++k)
	{
		for(int i=0;i<5;++i)
			for(int j=0;j<5;++j)
			{
				dp[k][i][j][0]=min(dp[k-1][num[k]][j][0]+abs1(i-num[k]),dp[k-1][num[k]][j][1]+abs1(i-num[k]));
				dp[k][i][j][1]=min(dp[k-1][i][num[k]][0]+abs1(j-num[k]),dp[k-1][i][num[k]][1]+abs1(j-num[k]));
			}
	}

	int ans=100000000;

	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			ans=min(ans,min(dp[N][i][j][0],dp[N][i][j][1]));

	printf("%d\n",ans);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;++i)
		{
			scanf("%d",&num[i]);
		}

		slove();
	}

	return 0;
}
