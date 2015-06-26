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

int mod[1000006];
int N,K;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;
	long long sum;
	int T;
	long long ans;
	long long temp;

	scanf("%d\n",&T);

	while(T--)
	{
		ans=0;
		scanf("%d %d",&N,&K);
		mod[0]=0;
		sum=0;

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&a);
			sum+=a;
			mod[i]=sum%K;

			if(mod[i]<0)
				mod[i]+=K;
		}

		sort(mod,mod+N+1);

		mod[N+1]=-1;
		temp=1;
		for(int i=1;i<=N+1;++i)
			if(mod[i]!=mod[i-1])
			{
				ans+=((long long)temp)*((long long)(temp-1))/2;
				temp=1;
			}
			else
				++temp;

		cout<<ans<<endl;
	}

	return 0;
}
