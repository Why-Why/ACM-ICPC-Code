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

int num[1010];
int N;
char map1[1010][1010];
int dp[1010];

void pre()
{
	int j=0;

	for(int i=1;i<=N;++i)
	{
		for(j=1;j<i;++j)
			if(map1[N+1-i][i-j]!=map1[N+1-i+j][i])
				break;

		num[i]=j;
	}
}

int getans(int x)
{
	int i;

	for(i=1;x+i-1<=N;++i)
		if(num[x+i-1]<i)
			break;

	return i-1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[1010];

	while(~scanf("%d",&N) && N)
	{
		for(int i=1;i<=N;++i)
		{
			scanf("%s",s);

			for(int j=1;j<=N;++j)
				map1[i][j]=s[j-1];
		}

		pre();

		dp[N]=1;
		for(int i=N-1;i>=1;--i)
			dp[i]=max(dp[i+1],getans(i));

		printf("%d\n",dp[1]);
	}
	
	return 0;
}
