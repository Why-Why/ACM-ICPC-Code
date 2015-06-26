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

const int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int dp[110][110];
int map1[110][110];
int N,K;

bool judge(int x,int y,int base)
{
	if(x<1 || y<1 || x>N || y>N)
		return 0;

	if(map1[x][y]<=base)
		return 0;

	return 1;
}

int dfs(int x,int y)
{
	if(dp[x][y])
		return dp[x][y];

	int maxn=0;

	for(int i=1;i<=K;++i)
		for(int j=0;j<4;++j)
			if(judge(x+step[j][0]*i,y+step[j][1]*i,map1[x][y]))
				maxn=max(dfs(x+step[j][0]*i,y+step[j][1]*i),maxn);

	dp[x][y]=maxn+map1[x][y];

	return dp[x][y];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&N,&K) && (N!=-1 || K!=-1))
	{
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
			{
				scanf("%d",&map1[i][j]);
				dp[i][j]=0;
			}

		printf("%d\n",dfs(1,1));
	}
	
	return 0;
}
