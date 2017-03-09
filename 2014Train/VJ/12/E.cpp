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

long long num[1010];
int N;
long long dp[1010];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int maxn;

	while(~scanf("%d",&N) && N)
	{
		for(int i=1;i<=N;++i)
			scanf("%I64d",&num[i]);
		num[0]=0;

		for(int i=N;i>=0;--i)
		{
			maxn=0;

			for(int j=i+1;j<=N;++j)
				if(num[j]>num[i] && dp[j]>maxn)
					maxn=dp[j];

			dp[i]=num[i]+maxn;
		}

		printf("%I64d\n",dp[0]);
	}
	
	return 0;
}
