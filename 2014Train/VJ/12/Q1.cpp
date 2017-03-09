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

int dp[1010][1010];
char map1[1010][1010];
int N;

int getans(int x,int y)
{
	int i;

	for(i=1;x-i>0 && y+i<=N;++i)
		if(map1[x-i][y]!=map1[x][y+i])
			return i;

	return i;
}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int temp;
	int ans;

	while(~scanf("%d",&N) && N)
	{
		ans=1;

		for(int i=1;i<=N;++i)
		{
			scanf("%s",map1[i]+1);
			dp[1][i]=1;
		}

		for(int i=2;i<=N;++i)
			for(int j=1;j<=N;++j)
			{
				temp=getans(i,j);

				if(temp>dp[i-1][j+1])
					dp[i][j]=dp[i-1][j+1]+1;
				else
					dp[i][j]=temp;

				if(dp[i][j]>ans)
					ans=dp[i][j];
			}

		printf("%d\n",ans);
	}
	
	return 0;
}
