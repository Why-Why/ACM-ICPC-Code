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
	int x,y,h;

	bool operator < (const state & a) const
	{
		if(x==a.x)
			return y>a.y;

		return x<a.x;
	}
};

state sta[1100];
int ans[1100];
int N;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;
	int cou;
	int cas=0;
	int maxn;
	int lastans;

	while(~scanf("%d",&N) && N)
	{
		lastans=0;
		++cas;
		cou=1;
		ans[0]=0;

		for(int i=0;i<N;++i)
		{
			scanf("%d %d %d",&a,&b,&c);

			sta[cou].x=a;
			sta[cou].y=b;
			sta[cou++].h=c;

			sta[cou].x=b;
			sta[cou].y=a;
			sta[cou++].h=c;

			sta[cou].x=b;
			sta[cou].y=c;
			sta[cou++].h=a;

			sta[cou].x=c;
			sta[cou].y=b;
			sta[cou++].h=a;
			
			sta[cou].x=c;
			sta[cou].y=a;
			sta[cou++].h=b;

			sta[cou].x=a;
			sta[cou].y=c;
			sta[cou++].h=b;
		}
		--cou;

		sort(sta+1,sta+cou+1);

		for(int i=1;i<=cou;++i)
		{
			maxn=0;

			for(int j=1;j<i;++j)
				if(sta[j].x<sta[i].x && sta[j].y<sta[i].y && maxn<ans[j])
					maxn=ans[j];

			ans[i]=sta[i].h+maxn;

			if(ans[i]>lastans)
				lastans=ans[i];
		}

		printf("Case %d: maximum height = %d\n",cas,lastans);
	}
	
	return 0;
}
