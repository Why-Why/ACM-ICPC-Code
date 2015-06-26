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

int N,M,A[10004];

bool judge(int X)
{
	
}

void slove()
{
	int L=0,R=100000000,Mid;

	while(R>L)
	{
		Mid=(L+R)/2;

		if(judge(Mid))
			R=Mid;
		else
			L=Mid+1;
	}

	printf("%d\n",L);
}

int sum;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int ans;

	scanf("%d",&T);

	while(T--)
	{
		sum=0;
		int maxn=-1;

		scanf("%d %d",&N,&M);

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&A[i]);
			sum+=A[i];

			if(A[i]>maxn)
				maxn=A[i];
		}

		if(sum%M==0)
			ans=max(sum/M,maxn);
		else
			ans=max(sum/M+1,maxn);

		printf("%d\n",ans);
	}

	return 0;
}
