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

int dp[210][10000];
int rem[210][10000];
int pre[210][10000];
int n,m;
int D[210],P[210];
int Ds,Ps,anscou,ansnum[210],ans;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas=1;
	int temp;

	while(~scanf("%d %d",&n,&m) && n+m)
	{
		for(int i=1;i<=n;++i)
		{
			scanf("%d %d",&D[i],&P[i]);

			for(int j=0;j<10000;++j)
				dp[i][j]=dp[0][j]=INF;
		}
		memset(pre[1],0,sizeof(pre[1]));
		dp[1][20+D[1]-P[1]]=1;
		rem[1][20+D[1]-P[1]]=D[1]+P[1];
		pre[1][20+D[1]-P[1]]=1;

		for(int i=2;i<=n;++i)
			for(int j=-4000;j<=4000;++j)
			{
				temp=D[i]-P[i];

				if(j+4000-temp<0 || j+4000-temp>8000)
					continue;

				if(dp[i-1][j]>dp[i-1][j+4000-temp]+1)
				{
					dp[i][j]=dp[i-1][j+4000-temp]+1;
					rem[i][j]=rem[i-1][j+4000-temp]+D[i]+P[i];
					pre[i][j]=1;
				}
				else if(dp[i-1][j]<dp[i-1][j+4000-temp]+1)
				{
					dp[i][j]=dp[i-1][j];
					rem[i][j]=rem[i-1][j]+D[i]+P[i];
					pre[i][j]=0;
				}
				else
				{
					dp[i][j]=dp[i-1][j];

					if(rem[i-1][j]>rem[i-1][j+4000-temp])
					{
						rem[i][j]=rem[i-1][j]+D[i]+P[i];
						pre[i][j]=0;
					}
					else
					{
						rem[i][j]=rem[i-1][j+4000-temp]+D[i]+P[i];
						pre[i][j]=1;
					}
				}
			}

		Ds=0;
		Ps=0;
		anscou=0;
		int remans;

		for(int i=0;i<=4000;++i)
			if(dp[n][4000+i]==m || dp[n][4000-i]==m)
			{
				ans=i;

				if(dp[n][4000+i]==m && dp[n][4000-i]==m)
				{
					if(rem[n][4000+i]>rem[n][4000-i])
						remans=4000+i;
					else
						remans=4000-i;
				}
				else if(dp[n][4000+i]==m)
					remans=4000+i;
				else
					remans=4000-i;
			}

		for(int i=n;i>=1;--i)
			if(pre[i][remans])
			{
				ansnum[anscou++]=i;
				Ds+=D[i];
				Ps+=P[i];

				remans=remans-(D[i]-P[i]);
			}

		printf("Jury #%d\n",cas++);
		printf("Best jury has value %d for prosecution and value %d for defence: \n",Ds,Ps);
		
		for(int i=anscou-1;i>=0;--i)
			printf(" %d",ansnum[i]);
		printf("\n\n");
	}
	
	return 0;
}
