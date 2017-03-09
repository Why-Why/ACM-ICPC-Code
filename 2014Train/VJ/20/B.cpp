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

const int MaxN=1010;

long long D[MaxN],S[MaxN];
long long dp[MaxN][MaxN];
int que[MaxN];
int first,last;
int N,M;

bool judge(int m,int a,int b,int k)
{
	return S[a]*S[a]+dp[m][a]-D[a]-(S[b]*S[b]+dp[m][b]-D[b])<k*(S[a]-S[b]);
}

bool judge(int m,int a,int b,int c,int d)
{
	return (S[a]*S[a]+dp[m][a]-D[a]-(S[b]*S[b]+dp[m][b]-D[b]))*(S[c]-S[d])<(S[c]*S[c]+dp[m][c]-D[c]-(S[d]*S[d]+dp[m][d]-D[d]))*(S[a]-S[b]);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;

	while(~scanf("%d %d",&N,&M) && N+M)
	{
		S[0]=0;
		first=last=0;
		dp[0][0]=0;
		D[0]=0;

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&a);
			S[i]=S[i-1]+a;
			D[i]=D[i-1]+a*S[i-1];
		}

		for(int i=1;i<=N;++i)
			dp[0][i]=D[i];

		for(int m=1;m<=M;++m)
		{
			dp[m][0]=0;
			first=last=0;
			que[last++]=0;

			for(int i=1;i<=N;++i)
			{
				while(last-first>1 && judge(m-1,que[first+1],que[first],S[i]))
					++first;

				int j=que[first];
				dp[m][i]=S[j]*S[j]+dp[m-1][j]-D[j]+D[i]-S[i]*S[j];

				while(last-first>1 && judge(m-1,i,que[last-1],que[last-1],que[last-2]))
					--last;

				que[last++]=i;
			}
		}

		printf("%I64d\n",dp[M][N]);
	}
	
	return 0;
}
