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

const int INF=10e8;

struct state
{
	char name[110];
	int dead,cost;
};

state sta[20];
int dp[40000];
int N;
int rem[40000],cost[40000];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int remi,remj,ans[20],cou;
	int past;
	int point;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
			scanf("%s %d %d",sta[i].name,&sta[i].dead,&sta[i].cost);

		cost[0]=0;
		rem[0]=0;
		dp[0]=0;

		for(int i=1;i<(1<<N);++i)
		{
			dp[i]=INF;

			for(int j=N;j>=1;--j)
				if((1<<(j-1)) & i)
				{
					past=i^(1<<(j-1));

					point=cost[past]+sta[j].cost-sta[j].dead;

					if(point<0)
						point=0;

					if(dp[past]+point<dp[i])
					{
						dp[i]=dp[past]+point;
						cost[i]=cost[past]+sta[j].cost;
						rem[i]=j;
					}
				}
		}

		printf("%d\n",dp[(1<<N)-1]);
		
		remj=(1<<N)-1;

		cou=0;
		while(remj)
		{
			ans[cou++]=rem[remj];

			remj=remj^(1<<(rem[remj]-1));
		}

		for(int i=cou-1;i>=0;--i)
			printf("%s\n",sta[ans[i]].name);
	}
	
	return 0;
}
