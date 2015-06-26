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

int dp[30][1000];
vector<int> pre[30][1000];
int N,M;
int D[210],P[210];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas=1;
	int Ds,Ps,anscou,ansnum[30];
	int ans;

	while(~scanf("%d %d",&N,&M) && N+M)
	{
		for(int i=0;i<30;++i)
			for(int j=0;j<=800;++j)
				pre[i][j].clear();

		for(int i=1;i<=N;++i)
			scanf("%d %d",&D[i],&P[i]);
		memset(dp,-1,sizeof(dp));
		
		dp[0][400]=0;

		for(int k=1;k<=N;++k)
			for(int i=M;i>=1;--i)
				for(int j=0;j<=800;++j)
					if(j-D[k]+P[k]<=800 && j-D[k]+P[k]>=0 && dp[i-1][j-(D[k]-P[k])]!=-1)
						if(dp[i][j]<=dp[i-1][j-D[k]+P[k]]+D[k]+P[k])
						{
							dp[i][j]=dp[i-1][j-D[k]+P[k]]+D[k]+P[k];
							pre[i][j]=pre[i-1][j-D[k]+P[k]];
							pre[i][j].push_back(k);
						}

	//	for(int i=1;i<=M;++i,cout<<endl)
	//		for(int j=340;j<=460;++j)
	//			cout<<pre[i][j]<<' ';

		Ds=Ps=0;
		anscou=0;
		ans=0;

		for(int i=0;i<=400;++i)
			if(dp[M][400+i]!=-1 || dp[M][400-i]!=-1)
			{
				ans=i;
				break;
			}

		if(dp[M][400+ans]>dp[M][400-ans])			//!!!!!
			ans=400+ans;
		else
			ans=400-ans;

		int len=pre[M][ans].size();

		for(int i=0;i<len;++i)
		{
//			ansnum[anscou++]=pre[M][ans][i];
			Ds+=D[pre[M][ans][i]];
			Ps+=P[pre[M][ans][i]];
			
//			ans=ans-D[pre[i][ans]]+P[pre[i][ans]];
		}

/*		int i;
		for(i=0;dp[M][400+i]==-1 && dp[M][400-i]==-1;++i);

		int temp=(dp[M][400+i]>dp[M][400-i] ? i : -i);
		Ds=(dp[M][400+temp]+temp)/2;
		Ps=(dp[M][400+temp]-temp)/2;
*/
		printf("Jury #%d\n",cas++);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",Ds,Ps);
		anscou=pre[M][ans].size();
		for(int i=0;i<anscou;++i)
			printf(" %d",pre[M][ans][i]);
		printf("\n\n");
	}
	
	return 0;
}
