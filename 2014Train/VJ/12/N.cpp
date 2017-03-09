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

int num[1010];
int N;
int dp[1010];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int maxn;

	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		dp[1]=1;
	
		for(int i=2;i<=N;++i)
		{
			maxn=0;
			
			for(int j=1;j<i;++j)
				if(num[j]<num[i] && dp[j]>maxn)
					maxn=dp[j];

			dp[i]=maxn+1;
		}

		maxn=0;

		for(int i=1;i<=N;++i)
			if(dp[i]>maxn)
				maxn=dp[i];

		printf("%d\n",maxn);
	}
	
	return 0;
}
