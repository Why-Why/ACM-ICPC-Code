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

inline int sgn(double x)
{
	if(fabs(x)<eps)
		return 0;

	if(x<0)
		return -1;

	return 1;
}

struct state
{
	double L,R;

	bool operator < (const state & b) const
	{
		if(sgn(R-b.R))
			return sgn(R-b.R)<0;
		
		return sgn(L-b.L)>0;
	}
};

int N;
double d;
state sta[1010];
bool vis[1010];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas=1;
	double x,y;
	bool ok;
	double temp;

	while(~scanf("%d %lf",&N,&d) && N)
	{
		memset(vis,0,sizeof(vis));
		ok=1;
		
		for(int i=1;i<=N;++i)
		{
			scanf("%lf %lf",&x,&y);

			if(y>d)
				ok=0;
			else
			{
				temp=sqrt(d*d-y*y);
				sta[i].L=x-temp;
				sta[i].R=x+temp;
			}
		}

		printf("Case %d: ",cas++);

		if(!ok)
		{
			printf("-1\n");
			continue;
		}

		sort(sta+1,sta+1+N);

		int ans=0;
		int p=1;

		while(p<=N)
		{
			++ans;
			temp=sta[p].R;

			while(p<=N && sgn(temp-sta[p].L)>=0)
				++p;
		}

		printf("%d\n",ans);
	}
	
	return 0;
}
