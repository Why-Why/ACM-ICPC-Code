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

int T,K;
int dp[300][10];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ans=0;

	for(int i=1;i<=200;++i)
		dp[i][1]=1;

	for(int i=1;i<=200;++i)
		for(int j=2;j<=6;++j)
		{
			for(int k=1;k<=i && i-k-(k-1)*(j-1)>=1;++k)
				dp[i][j]+=dp[i-(k-1)*(j-1)-k][j-1];
		}

	

	while(~scanf("%d %d",&T,&K))
	{
		printf("%d\n",dp[T][K]);
	}
	
	return 0;
}
