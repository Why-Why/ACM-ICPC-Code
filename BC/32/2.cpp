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

struct state
{
	long long s;
	int id;

	bool operator < (const state &a) const
	{
		return s<a.s;
	}
};

state sta[1000006];

inline long long getK(long long K,int d)
{
	if(d%2)
		return K;
	else
		return -K;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;
	int n;
	int t;
	int p1,p2;
	long long flag;
	int K1;
	long long K;
	bool ok;

	cin>>T;

	for(int cas=1;cas<=T;++cas)
	{
		scanf("%d %d",&n,&K1);
		K=K1;
		sta[0].s=0;
		flag=1;

		for(int i=1;i<=n;++i)
		{
			scanf("%d",&t);
			sta[i].s=sta[i-1].s+flag*t;
			sta[i].id=i;
			flag=-flag;
		}

		sort(sta+1,sta+n+1);


		p2=2;
		ok=0;
		for(p1=1;p1<=n;++p1)
		{
			if(sta[p1].s==K)
			{
				ok=1;
				break;
			}
			while(p2<=n && sta[p2].s-sta[p1].s<K)
				++p2;
			if(p2==p1)
				++p2;
			if(p2>n)
				continue;
			if((sta[p2].s-sta[p1].s==K && min(sta[p2].id,sta[p1].id)%2==0) || sta[p1].s==K || sta[p2].s==K)
			{
				ok=1;
				break;
			}
		}

		if(!ok)
		{
			p2=n-1;
			for(p1=n;p1>=1;--p1)
			{
				while(p2>=1 && sta[p2].s-sta[p1].s>-K)
					--p2;
				if(p2==p1)
					--p2;
				if(p2<1)
					continue;
				if((sta[p2].s-sta[p1].s==-K && min(sta[p2].id,sta[p1].id)%2==0))
				{
					ok=1;
					break;
				}
			}
		}

		printf("Case #%d: ",cas);
		if(ok)
			printf("Yes.\n");
		else
			printf("No.\n");
	}

	return 0;
}
