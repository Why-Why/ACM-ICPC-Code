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

struct state
{
	int h,w;
};

state num[1010];
state dp[1010][1010];

int getarea(int x,int y,int t)
{
	int ret=0;

	if(!t)
		return max(dp[x-1][y].h,num[x].h)*(dp[x-1][y].w+num[x].w);
	else
		return max(dp[x-1][y].h,num[x].w)*(dp[x-1][y].w+num[x].h);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);

	int temp1,temp2;

	for(int i=1;i<=N;++i)
		scanf("%d %d",&num[i].w,&num[i].h);

	if(N==1)
	{
		cout<<num[1].h*num[1].w<<endl;
		return 0;
	}

	dp[1][0]=num[1];
	dp[1][1].h=num[1].w;
	dp[1][1].w=num[1].h;

	for(int i=2;i<=N;++i)
	{
		dp[i][0].h=max(dp[i-1][0].h,num[i].h);
		dp[i][0].w=dp[i-1][0].w+num[i].w;

		for(int j=1;j<=N/2 && j<=i;++j)
		{
			temp1=getarea(i,j,0);
			temp2=getarea(i,j-1,1);

			if(temp1<=temp2)
			{
				dp[i][j].h=max(dp[i-1][j].h,num[i].h);
				dp[i][j].w=dp[i-1][j].w+num[i].w;
			}
			else
			{
				dp[i][j].h=max(dp[i-1][j-1].h,num[i].w);
				dp[i][j].w=dp[i-1][j-1].w+num[i].h;
			}
		}
	}

	int minn=1000000007;

	for(int i=0;i<=N/2;++i)
		minn=min(minn,dp[N][i].h*dp[N][i].w);

	cout<<minn<<endl;

	return 0;
}
