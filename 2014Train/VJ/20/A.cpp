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

const int MaxN=500005;

long long x[MaxN],y[MaxN],dp[MaxN];
int que[MaxN];
int first,last;
int N,M;
long long s[MaxN];

long long getmin(long long k)
{
	int temp1,temp2;

	while(last-first>1)
	{
		temp1=que[first];
		temp2=que[first+1];

		if(y[temp2]-y[temp1]>=k*(x[temp2]-x[temp1]))
			break;
		else
			++first;
	}

	return y[que[first]]-k*x[que[first]];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;

	while(~scanf("%d %d",&N,&M))
	{
		dp[0]=0;
		s[0]=0;
		first=last=0;

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&a);
			s[i]=s[i-1]+a;
			x[i]=s[i];
		}

		x[0]=y[0]=0;
		que[last++]=0;

		for(int i=1;i<=N;++i)
		{
			dp[i]=getmin(2*s[i])+s[i]*s[i]+M;
			y[i]=s[i]*s[i]+dp[i];
			
			while(last-first>1)
			{
				if((y[i]-y[que[last-1]])*(x[que[last-1]]-x[que[last-2]])>(y[que[last-1]]-y[que[last-2]])*(x[i]-x[que[last-1]]))
					break;
				else
					--last;
			}

			que[last++]=i;
		}

		printf("%I64d\n",dp[N]);
	}
	
	return 0;
}
