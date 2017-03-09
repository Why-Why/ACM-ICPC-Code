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

int dp[1010];
int N,num[1010];

int find(int x,int R)
{
	int L=1,M;

	while(R>L+1)
	{
		M=(L+R)/2;

		if(dp[M]>=x)
			R=M-1;
		else
			L=M;
	}

	if(dp[R]<x)
		return R;

	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int maxn;
	int temp;

	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		memset(dp,0,sizeof(dp));
		dp[1]=num[1];
		maxn=1;

		for(int i=2;i<=N;++i)
			if(num[i]<=dp[1])
				dp[1]=num[i];
			else if(num[i]>dp[maxn])
				dp[++maxn]=num[i];
			else
			{
				temp=find(num[i],maxn);
				dp[temp+1]=min(dp[temp+1],num[i]);
			}

		printf("%d\n",maxn);
	}
	
	return 0;
}
