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

int D,P[1010];
int maxn[1010],cost[1010];
priority_queue <int> que,que1;

void pre()
{
	int temp;

	maxn[0]=0;
	cost[0]=0;

	maxn[1]=1;
	cost[1]=0;

	for(int i=2;i<=1001;++i)
	{
		temp=sqrt(double(i));

		if(temp*temp<i)
			++temp;

		cost[i]=temp-1;
		maxn[i]=temp;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	int T,cas=1;
	int ans;
	int base,base1;
	int t,temp;

	scanf("%d",&T);

	pre();

	while(T--)
	{
		scanf("%d",&D);

		while(!que.empty())
			que.pop();
		while(!que1.empty())
			que1.pop();

		for(int i=1;i<=D;++i)
		{
			scanf("%d",&P[i]);
			que.push(P[i]);
			que1.push(P[i]);
		}

		ans=1010;
		base=0;
		base1=0;

		while(!que.empty())
		{
			temp=que.top();
			que.pop();

			ans=min(ans,temp+base);

			if(temp<2 && que1.top()<2)
				break;

			if(temp<2)
				goto loop;

			base+=cost[temp];
			t=temp;

			while(temp)
			{
				if(temp>=maxn[t])
				{
					que.push(maxn[t]);
					temp-=maxn[t];
				}
				else
				{
					que.push(temp);
					temp=0;
				}
			}
loop:
			temp=que1.top();
			que1.pop();

			if(temp<2 && que.top()<2)
				break;

			if(temp<2)
				continue;

			ans=min(ans,temp+base1);

			++base1;

			que1.push(temp/2);
			que1.push(temp-temp/2);
		}

		printf("Case #%d: %d\n",cas++,ans);
	}
	
	return 0;
}
