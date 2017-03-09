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
	int id,val;

	bool operator < (const state &b) const
	{
		return val<b.val;
	}
};

state sta[2010];
int N;
int num[2010];
long long dp[2010],dp1[2010];

inline int getdis(int x,int y)
{
	int ret=sta[x].val-sta[y].val;

	return ret<0 ? -ret : ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;
	long long minn;
	long long ans;

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
	{
		scanf("%d",&a);
		sta[i].val=a;
		sta[i].id=i;
	}

	sort(sta+1,sta+1+N);

	for(int i=1;i<=N;++i)
	{
		num[sta[i].id]=i;
		dp[i]=getdis(num[1],i);
		dp1[i]=getdis(num[1],i);
	}

	for(int i=2;i<=N;++i)
	{
		minn=dp[1];
		for(int j=1;j<=N;++j)
		{
			minn=min(minn,dp[j]);
			dp[j]=minn+getdis(num[i],j);
		}

		minn=dp1[N];
		for(int j=N;j>=1;--j)
		{
			minn=min(minn,dp1[j]);
			dp1[j]=minn+getdis(num[i],j);
		}
	}

	ans=min(dp[1],dp1[1]);
	for(int i=2;i<=N;++i)
		ans=min(ans,min(dp1[i],dp[i]));

	printf("%lld\n",ans);
	
	return 0;
}
