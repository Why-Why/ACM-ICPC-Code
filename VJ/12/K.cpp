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
	int d,p;
};

int N,M;
state dp[210][30];
state num[210];
bool fa[210][30];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t1,t2,t3,t4;
	int cas=1;
	int ans[30],cou;

	while(~scanf("%d %d",&N,&M) && N+M)
	{
		for(int i=1;i<=N;++i)
			scanf("%d %d",&num[i].d,&num[i].p);

		memset(dp,0,sizeof(dp));

		dp[1][1].d=num[1].d;
		dp[1][1].p=num[1].p;
		fa[1][1]=1;
		for(int i=2;i<=N;++i)
			for(int j=1;j<=M && j<=i;++j)
			{
				t1=abs(dp[i-1][j].d-dp[i-1][j].p);
				t2=abs(dp[i-1][j-1].d+num[i].d-dp[i-1][j-1].p-num[i].p);
				t3=dp[i-1][j].d+dp[i-1][j].p;
				t4=dp[i-1][j-1].d+dp[i-1][j-1].p+num[i].d+num[i].p;

				if(j<=i-1 && (t1<t2 || (t1==t2 && t3>=t4)))
				{
					dp[i][j].d=dp[i-1][j].d;
					dp[i][j].p=dp[i-1][j].p;
					fa[i][j]=0;
				}
				else
				{
					dp[i][j].d=dp[i-1][j-1].d+num[i].d;
					dp[i][j].p=dp[i-1][j-1].p+num[i].p;
					fa[i][j]=1;
				}
			}

		printf("Jury #%d\n",cas++);
		printf("Best jury has value %d for prosecution and value %d for defence: \n",dp[N][M].d,dp[N][M].p);
		
		cou=0;
		t1=N;
		t2=M;
		while(cou<M)
		{
			if(fa[t1][t2])
			{
				ans[cou++]=t1;
				--t2;
			}
			
			--t1;
		}

		for(int i=cou-1;i>=0;--i)
			printf(" %d",ans[i]);
		printf("\n\n");

		for(int i=1;i<=N;++i,cout<<endl)
			for(int j=1;j<=i && j<=M;++j)
				cout<<dp[i][j].d<<'|'<<dp[i][j].p<<' ';
	}
	
	return 0;
}
