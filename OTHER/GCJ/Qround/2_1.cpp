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

int D,P[2000];

bool judge(int *num,int n)
{
//	cout<<n<<endl;
	for(int i=1;i<=n;++i)
		if(num[i])
			return 0;
	return 1;
}

int getans(int type)
{
	int tD=D;
	int ans=0;
	int tP[2010];
	bool ok;
	int maxn;
	int temp;

	for(int i=1;i<=tD;++i)
		tP[i]=P[i];
	for(int k=0;k<5000;++k)
	{
		if(judge(tP,tD))
			break;


		++ans;
		if((type&1)==0)
		{
			for(int i=1;i<=tD;++i)
				if(tP[i])
					--tP[i];
		}
		else
		{
			maxn=1;

			for(int i=1;i<=tD;++i)
				if(tP[i]>tP[maxn])
					maxn=i;

			if(tP[maxn]<=1)
				break;

			temp=tP[maxn];
			tP[maxn]=temp/2;
			tP[tD+1]=temp-temp/2;
			++tD;
		}

		type>>=1;
	}

	if(!judge(tP,tD))
		ans=1010;

//	cout<<endl;
//cout<<ans<<' ';
	return ans;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out1.txt","w",stdout);

	int T,cas=1;
	int ans;
	int maxn;
	int temp;
	int id;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&D);
		maxn=0;

		for(int i=1;i<=D;++i)
		{
			scanf("%d",&P[i]);
			maxn=max(maxn,P[i]);
		}

		ans=1010;

		for(int i=0;i<5000;++i)
		{
			temp=getans(i);

			if(ans>temp)
			{
				ans=temp;
				id=i;
			}
		}

		printf("Case #%d: ",cas++);
		printf("%d\n",ans);
	}
	
	return 0;
}
