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
	int id,first,second;

	bool operator < (const state &a) const
	{
		if(first!=a.first)
			return first>a.first;
		if(second!=a.second)
			return second<a.second;
		return id<a.id;
	}
};

state sta[200];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;
	int n;
	int a,b;

	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d %d",&a,&b);
			sta[i].id=i;
			sta[i].first=a-b;
			sta[i].second=b;
		}

		sort(sta,sta+n);

		printf("%d",sta[0].id);
		for(int i=1;i<n;++i)
			printf(" %d",sta[i].id);
		printf("\n");
	}

	return 0;
}
