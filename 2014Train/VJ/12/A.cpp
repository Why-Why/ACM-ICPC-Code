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

int num[1000006];
long long dp[1000006];
int n,m;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long maxn;
	long long temp;

	while(~scanf("%d %d",&m,&n))
	{
		for(int i=1;i<=n;++i)
			scanf("%d",&num[i]);

		dp[0]=dp[1]=0;

		for(int i=1;i<=m;++i)
		{
			maxn=max(dp[i],dp[i-1]);
			dp[i]=dp[i-1]+num[i];

			for(int j=i+1;j<=n;++j)
			{
				temp=(i==1 ? 0 : dp[j]);
				dp[j]=max(maxn,dp[j-1])+num[j];
				maxn=max(maxn,temp);
			}
		}

		maxn=dp[m];

		for(int i=m+1;i<=n;++i)
			if(maxn<dp[i])
				maxn=dp[i];

		printf("%I64d\n",maxn);
	}
	
	return 0;
}
