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

int dp[10][10];
int num[10];

int dfs(int dep,int pre,bool e)
{
	if(dep==-1)
		return 1;

	if(!e && dp[dep][pre]!=-1)
		return dp[dep][pre];

	int ret=0;
	int u=e ? num[dep] : 9;

	for(int i=0;i<=u;++i)
		if(i!=4 && (pre!=6 || i!=2))
			ret+=dfs(dep-1,i,i==u && e);

	if(!e)
		dp[dep][pre]=ret;

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n,m;
	int cou;

	while(~scanf("%d %d",&n,&m) && n+m)
	{
		--n;

		memset(dp,-1,sizeof(dp));

		for(int i=0;i<6;++i)
		{
			num[i]=n%10;
			n/=10;
		}

		int b=dfs(5,0,1);

		memset(dp,-1,sizeof(dp));

		for(int i=0;i<6;++i)
		{
			num[i]=m%10;
			m/=10;
		}

		int a=dfs(5,0,1);

		printf("%d\n",a-b);
	}
	
	return 0;
}
