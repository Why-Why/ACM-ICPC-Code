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

int dp[1010][1010];
int n;
char s[1010];

void pre()
{
	int N=n;

	memset(dp,0,sizeof(dp));

	for(int l=1;l<=N;++l)
	{
		for(int i=0;i+l-1<N;++i)
			if(s[i]!=s[i+l-1])
				dp[i][i+l-1]=dp[i+1][i+l-2];
			else
				dp[i][i+l-1]=min(dp[i+1][i+l-1],dp[i][i+l-2])+1;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %s",&n,s);

		pre();

		printf("%d\n",dp[0][n-1]);
	}
	
	return 0;
}
