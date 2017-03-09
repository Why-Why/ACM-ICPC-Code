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

int N;
int dp[2010][2010];
int sum[2010];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;

	scanf("%d",&N);

	sum[0]=0;
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=N;++i)
	{
		scanf("%d",&a);
		sum[i]=sum[i-1]+a;
	}

	for(int i=1;i<=N;++i)
		dp[1][i]=sum[i]-sum[i-1];

	for(int i=2;i<=N;++i)
		for(int j=1;j+i-1<=N;++j)
			dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+sum[j+i-1]-sum[j-1];

	printf("%d\n",dp[N][1]);

	return 0;
}
