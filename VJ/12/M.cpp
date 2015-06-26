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

const int INF=20000*40000+10000;;

struct state
{
	int X1,X2,H;

	bool operator < (const state & a) const
	{
		return H<a.H;
	}
};

int N,X,Y,MAX;
state sta[1010];
int dp[1010][2];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int maxn1,maxn2,rem1,rem2;
	int maxn,rem;

	scanf("%d",&T);

	while(T--)
	{
		maxn=0;
		rem=0;

		scanf("%d %d %d %d",&N,&X,&Y,&MAX);

		for(int i=1;i<=N;++i)
			scanf("%d %d %d",&sta[i].X1,&sta[i].X2,&sta[i].H);

		sort(sta+1,sta+1+N);
		memset(dp,0,sizeof(dp));

		for(int i=1;i<=N;++i)
		{
			maxn1=maxn2=0;
			rem1=rem2=0;

			for(int j=1;j<i;++j)
				if(sta[j].H<sta[i].H)
				{
					if(sta[j].X1<=sta[i].X1 && sta[j].X2>=sta[i].X1 && sta[j].H>maxn1)
					{
						maxn1=sta[j].H;
						rem1=j;
					}

					if(sta[j].X1<=sta[i].X2 && sta[j].X2>=sta[i].X2 && sta[j].H>maxn2)
					{
						maxn2=sta[j].H;
						rem2=j;
					}
				}

			if(sta[i].H-maxn1>MAX)
				dp[i][0]=INF;
			else if(rem1)
				dp[i][0]=min(dp[rem1][0]+sta[i].X1-sta[rem1].X1,dp[rem1][1]+sta[rem1].X2-sta[i].X1)+sta[i].H-maxn1;
			else
				dp[i][0]=sta[i].H;

			if(sta[i].H-maxn2>MAX)
				dp[i][1]=INF;
			else if(rem2)
				dp[i][1]=min(dp[rem2][0]+sta[i].X2-sta[rem2].X1,dp[rem2][1]+sta[rem2].X2-sta[i].X2)+sta[i].H-maxn2;
			else
				dp[i][1]=sta[i].H;
		}

		for(int i=1;i<=N;++i)
			if(sta[i].H>maxn && sta[i].X1<=X && sta[i].X2>=X)
			{
				maxn=sta[i].H;
				rem=i;
			}

		if(rem)
			printf("%d\n",Y-maxn+min(dp[rem][0]+X-sta[rem].X1,dp[rem][1]+sta[rem].X2-X));
		else
			printf("%d\n",Y);
	}
	
	return 0;
}
