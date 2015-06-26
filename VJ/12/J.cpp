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

struct state
{
	int id,W,S;

	bool operator < (const state & a) const
	{
		if(a.W==W)
			return S>a.S;

		return W>a.W;
	}
};

state sta[1010];
int dp[1010];
int rem[1010];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int N=1;
	int maxn,k;

	while(~scanf("%d %d",&sta[N].W,&sta[N].S))
	{
		sta[N].id=N;
		++N;
	}
	--N;

	sort(sta+1,sta+N+1);

	dp[1]=1;
	rem[1]=-1;

	for(int i=2;i<=N;++i)
	{
		maxn=0;
		rem[i]=-1;

		for(int j=1;j<i;++j)
			if(sta[j].S<sta[i].S && dp[j]>maxn)
			{
				maxn=dp[j];
				rem[i]=j;
			}

		dp[i]=maxn+1;
	}

	maxn=0;

	for(int i=1;i<=N;++i)
		if(dp[i]>maxn)
		{
			maxn=dp[i];
			k=i;
		}

	printf("%d\n",maxn);

	for(int i=k;i!=-1;i=rem[i])
		printf("%d\n",sta[i].id);

	return 0;
}
