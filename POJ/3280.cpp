// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年07月19日 星期日 16时29分25秒
// File Name     : 3280.cpp

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

const int MaxN=2010;
const long long INF=1000000000000000LL;

int N,M;
char s[MaxN];
long long dp[MaxN][MaxN];
long long aC[MaxN],dC[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	char ts[10];
	long long sum1,sum2;

	while(~scanf("%d %d",&N,&M))
	{
		scanf("%s",s);
		memset(aC,0,sizeof(aC));
		memset(dC,0,sizeof(dC));

		for(int i=1;i<=N;++i)
		{
			scanf("%s %d %d",ts,&a,&b);
			aC[ts[0]-'a']=a;
			dC[ts[0]-'a']=b;
		}

		sum1=sum2=0;
		dp[0][M]=0;

		for(int j=M-1;j>=0;--j)
		{
			sum1+=aC[s[j]-'a'];
			sum2+=dC[s[j]-'a'];
			dp[0][j]=min(sum1,sum2);
		}

		sum1=sum2=0;
		
		for(int i=1;i<=M;++i)
		{
			sum1+=aC[s[i-1]-'a'];
			sum2+=dC[s[i-1]-'a'];
			dp[i][M]=min(sum1,sum2);
		}

		for(int i=1;i<=M;++i)
			for(int j=M-1;j>=i;--j)
				if(s[i-1]==s[j])
					dp[i][j]=dp[i-1][j+1];
				else
					dp[i][j]=min(dp[i-1][j]+min(aC[s[i-1]-'a'],dC[s[i-1]-'a']),dp[i][j+1]+min(aC[s[j]-'a'],dC[s[j]-'a']));

		long long minn=INF;

		for(int i=0;i<=M;++i)
			minn=min(minn,dp[i][i]);

		for(int i=0;i<M;++i)
			minn=min(minn,dp[i][i+1]);

		printf("%lld\n",minn);
	}
	
	return 0;
}
