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

char s1[1010],s2[1010];
int dp[1010][1010];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int len1,len2;

	while(~scanf("%s %s",s1,s2))
	{
		dp[0][0]=dp[0][1]=dp[1][0]=0;

		len1=strlen(s1);
		len2=strlen(s2);

		for(int i=1;i<=len1;++i)
			for(int j=1;j<=len2;++j)
				if(s1[i-1]==s2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

		printf("%d\n",dp[len1][len2]);
	}
	
	return 0;
}
