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

int num[14][100005];
int dp[14][100005];
int maxT;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	int a,b;
	int ans;

	while(~scanf("%d",&n) && n)
	{
		memset(num,0,sizeof(num));
		maxT=0;

		while(n--)
		{
			scanf("%d %d",&a,&b);

			++num[a+1][b];
			maxT=max(maxT,b);
		}

		for(int i=5;i<=7;++i)
			dp[i][1]=num[i][1];

		for(int i=2;i<=maxT;++i)
			for(int j=1;j<=11;++j)
				dp[j][i]=max(max(dp[j-1][i-1],dp[j][i-1]),dp[j+1][i-1])+num[j][i];

		ans=0;

		for(int i=1;i<=11;++i)
			ans=max(ans,dp[i][maxT]);

		printf("%d\n",ans);
	}
	
	return 0;
}
