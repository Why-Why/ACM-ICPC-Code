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

const int MaxN=100005;

int Mt[MaxN*2];
int Mp[MaxN*2];
int zlen;

int Manacher(int len,int s[])
{
	int Mx=0,id=0,l=0;
	int ret=0;

	Mt[l++]=-1;
	Mt[l++]=1;

	for(int i=0;i<len;++i)
	{
		Mt[l++]=s[i];
		Mt[l++]=1;
	}

	Mt[l++]=0;
	zlen=l;

	for(int i=1;i<l;++i)
	{
		if(Mx>i)
			Mp[i]=min(Mp[2*id-i],Mx-i);
		else
			Mp[i]=1;

		while(Mt[i+Mp[i]]==Mt[i-Mp[i]])
			++Mp[i];

		if(Mp[i]+i>Mx)
		{
			Mx=Mp[i]+i;
			id=i;
		}

		if(Mp[i]-1>ret)
			ret=Mp[i]-1;
	}

	return ret;
}

int dp[MaxN];
int num[MaxN];
int n;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int ans,temp;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&n);

		scanf("%d",&num[0]);
		dp[0]=1;

		for(int i=1;i<n;++i)
		{
			scanf("%d",&num[i]);

			if(num[i]>=num[i-1])
				dp[i]=dp[i-1]+1;
			else
				dp[i]=1;
		}

		Manacher(n,num);

		ans=0;

		for(int i=1;i<zlen;++i)
		{
			if(i&1)
				temp=min(Mp[i]-1,dp[i/2-1]*2);
			else
				temp=min(Mp[i]-1,dp[i/2-1]*2-1);

			ans=max(ans,temp);
		}

		printf("%d\n",ans);
	}
	
	return 0;
}
