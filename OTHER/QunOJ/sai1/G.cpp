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

bool vis[100004];
int num[20];
int tsum,sum;

bool getans()
{
	if(sum%2)
		return 0;

	sum/=2;

	int maxn=0;
	int tmax;

	for(int i=1;i<=10;++i)
		if(num[i])
		{
			tmax=maxn;
			for(int j=0;j<=tmax;++j)
				if(vis[j])
				{
					for(int k=1;k<=num[i] && k*i+j<=sum;++k)
					{
						if(k*i+j>maxn)
							maxn=k*i+j;

						if(k*i+j==sum)
							return 1;

						vis[k*i+j]=1;
					}
				}
		}

	return vis[sum];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int cas=1;
	int t;

	while(1)
	{
		tsum=0;
		sum=0;
		memset(vis,0,sizeof(vis));
		vis[0]=1;
		for(int i=1;i<=10;++i)
		{
			scanf("%d",&t);
			tsum+=t;
			sum+=i*t;
			num[i]=t;
		}

		if(tsum==0)
			break;


		if(cas!=1)
			printf("\n");
		
		printf("#%d:",cas++);
		if(getans())
			printf("Can be divided.\n");
		else
			printf("Can't be divided.\n");


	}

	return 0;
}
