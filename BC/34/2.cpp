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

long long sumr[51000],sumc[51000];
int N,W,H;

long long abs1(long long x)
{
	return x<0 ? -x : x;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;
	int i;
	long long ans;
	long long sum1;

	while(~scanf("%d %d %d",&N,&W,&H))
	{
		sumr[0]=0;
		sumc[0]=0;
		sum1=0;

		for(i=1;i<=N;++i)
		{
			scanf("%d",&a);

			if(H>a)
			{
				sumr[i]=sumr[i-1]+H-a;
				sumc[i]=sumc[i-1];
			}
			else
			{
				sumr[i]=sumr[i-1];
				sumc[i]=sumc[i-1]+a-H;
			}

			sum1+=a;
		}

		if(sum1<((long long)(W))*H)
		{
			printf("-1\n");
			continue;
		}

		ans=10000000000000000LL;
		for(i=0;i+W<=N;++i)
			ans=min(ans,max((sumr[i+W]-sumr[i]),(sumc[i+W]-sumc[i])));

		for(;i<=N;++i)
			ans=min(ans,max((sumr[N]-sumr[i]),(sumc[N]-sumc[i]))+((long long)H)*(i+W-N));

		for(i=0;i<W;++i)
			ans=min(ans,max(sumr[i],sumc[i])+((long long)H)*(W-i));

		cout<<ans<<endl;
	}
	
	return 0;
}
