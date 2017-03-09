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

int dp[2010];
int K;
int num1[2010],num2[2010];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int h,m,s;
	
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&K);

		for(int i=1;i<=K;++i)
			scanf("%d",&num1[i]);
		for(int i=1;i<K;++i)
			scanf("%d",&num2[i]);

		memset(dp,0,sizeof(dp));

		dp[K]=num1[K];
		dp[K+1]=0;

		for(int i=K-1;i>=1;--i)
			dp[i]=min(dp[i+1]+num1[i],dp[i+2]+num2[i]);

		h=8+dp[1]/3600;
		m=(dp[1]%3600)/60;
		s=dp[1]%60;

		printf("%0*d:%0*d:%0*d ",2,(h>12 ? h-12 : h),2,m,2,s);
		
		if(h>12)
			printf("pm\n");
		else
			printf("am\n");
	}
	
	return 0;
}
