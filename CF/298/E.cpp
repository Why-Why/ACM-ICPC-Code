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

int pi=0;
int num[1200006];
int n;
int m;
int cou[300005];
int dis[300005];
int dis1[1200005];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&n);

	int temp,temp1;

	scanf("%d",&temp);

	for(int i=2;i<=n;++i)
	{
		scanf("%d",&temp1);
		dis[i]=temp1-temp;
		temp=temp1;
	}

	scanf("%d",&m);

	for(int i=1;i<=m;++i)
	{
		scanf("%d",&temp);

		if(cou[temp]==0)
			++pi;

		++cou[temp];
	}

	int base,last;
	int k=100000/(2*n-2);

	long long remdis=0;

	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<k;++j)
		{
			num[j*(n+n-2)+i]=i;
			dis1[j*(n+n-2)+i]=dis[i];

			if(i==1)
				dis1[j*(n+n-2)+i]=dis[2];
		}
	}

	for(int i=1;i<n-1;++i)
	{
		for(int j=0;j<k;++j)
		{
			num[n+j*(n+n-2)+i]=n-i;
			dis1[n+j*(n+n-2)+i]=dis[n-i+1];
		}
	}

	int len=k*(n+n-2);

	dis1[1]=0;

	for(int i=1;i<=m;++i)
	{
		temp=num[i];

		--cou[temp];
		
		if(cou[temp]==0)
			--pi;
		if(cou[temp]==-1)
			++pi;

		remdis+=dis1[i];
	}


	bool ok=0;
	long long ans=0;

	for(int i=m+1;i<len;++i)
	{
		if(pi==0)
		{
			if(ok && remdis!=ans)
			{
				printf("-1\n");
				return 0;
			}

			ok=1;
			ans=remdis;
		}

		remdis+=dis1[i];
		remdis-=dis1[i-m+1];

		--cou[num[i]];

		if(cou[num[i]]==0)
			--pi;
		if(cou[num[i]]==-1)
			++pi;

		++cou[num[i-m]];

		if(cou[num[i-m]]==0)
			--pi;
		if(cou[num[i-m]]==1)
			++pi;
	}

	cout<<ans<<endl;
	
	return 0;
}
