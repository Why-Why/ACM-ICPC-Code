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

int num[2000];
int N;
long long ans1,ans2;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T,cas=1;
	long long d;
	long long maxn;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		ans1=ans2=0;
		maxn=0;

		for(int i=2;i<=N;++i)
		{
			if(num[i]<num[i-1])
			{
				ans1+=num[i-1]-num[i];

				d=num[i-1]-num[i];

				maxn=max(maxn,d);
			}
		}

		for(int i=1;i<N;++i)
		{
			ans2+=min((long long)num[i],maxn);
		}

		printf("Case #%d: ",cas++);
		cout<<ans1<<' '<<ans2<<endl;
	}
	
	return 0;
}
