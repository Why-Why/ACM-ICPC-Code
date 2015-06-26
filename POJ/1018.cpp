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

const double eps=1e-8;

struct state
{
	int B,P;

	bool operator < (const state &b) const
	{
		return B<b.B;
	}
};

struct remm
{
	int val,id;

	bool operator < (const remm &b) const
	{
		return val<b.val;
	}
};

remm znum[10010];
int N,M[110];
int minn[110][110];
state num[110][110];

int find(int x,int n)
{
	int L=1,R=M[x],Mid;

	while(R>L)
	{
		Mid=(L+R)/2;

		if(num[x][Mid].B<n)
			L=Mid+1;
		else
			R=Mid;
	}

	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		int cou=0;

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&M[i]);

			for(int j=1;j<=M[i];++j)
				scanf("%d %d",&num[i][j].B,&num[i][j].P);

			sort(num[i]+1,num[i]+M[i]+1);

			for(int j=1;j<=M[i];++j)
			{
				znum[cou].val=num[i][j].B;
				znum[cou++].id=i*1000+j;
			}
		}

		sort(znum,znum+cou);

		for(int i=1;i<=N;++i)
		{
			minn[i][M[i]]=num[i][M[i]].P;

			for(int j=M[i]-1;j>=1;--j)
				minn[i][j]=min(minn[i][j+1],num[i][j].P);
		}

		double ans=0;
		long long sum=0;

		for(int i=0;i<cou;++i)
		{
			sum=num[znum[i].id/1000][znum[i].id%1000].P;

			for(int j=1;j<=N;++j)
			{
				if(j==znum[i].id/1000)
					continue;

				if(num[j][M[j]].B<znum[i].val)
					goto End;
				sum+=minn[j][find(j,znum[i].val)];
			}

			ans=max(ans,((double)znum[i].val)/sum);
		}

End:
		printf("%.3lf\n",ans+eps);
	}
	
	return 0;
}
