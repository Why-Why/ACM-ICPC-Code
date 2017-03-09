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

int We,N;
int P[510],W[510];
int dp[10010];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int E,F;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&E,&F);
		We=F-E;

		memset(dp,0,sizeof(dp));

		scanf("%d",&N);

		for(int i=1;i<=N;++i)
			scanf("%d %d",&P[i],&W[i]);

		for(int i=1;i<=N;++i)
		{
			if(dp[W[i]])
				dp[W[i]]=min(P[i],dp[W[i]]);
			else
				dp[W[i]]=P[i];

			for(int j=W[i]+1;j<=We;++j)
				if(dp[j-W[i]] && dp[j])
					dp[j]=min(dp[j],dp[j-W[i]]+P[i]);
				else if(dp[j-W[i]] && dp[j]==0)
					dp[j]=dp[j-W[i]]+P[i];
		}

		if(dp[We] || We==0)
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[We]);
		else
			printf("This is impossible.\n");
	}
	
	return 0;
}
