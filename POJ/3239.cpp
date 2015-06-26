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

int N;
int rem[400];

inline bool judge(int d,int x)
{
	for(int i=1;i<=d;++i)
		if(rem[i]==x || d+1-i==abs(x-rem[i]))
			return 0;

	return 1;
}

bool dfs(int d)
{
	if(d==N+1)
		return 1;

	if(d+d/2<N)
	for(int k=1;k<=N;++k)
	{
		int i=rand()%N+1;

		if(judge(d-1,i))
		{
			rem[d]=i;

			if(dfs(d+1))
				return 1;
		}
	}
	else
	{
		for(int i=1;i<=N;++i)
			if(judge(d-1,i))
			{
				rem[d]=i;

				if(dfs(d+1))
					return 1;
			}
	}

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	srand(time(0));

	while(~scanf("%d",&N) && N)
	{
		dfs(1);

		printf("%d",rem[1]);

		for(int i=2;i<=N;++i)
			printf(" %d",rem[i]);
		printf("\n");
	}
	
	return 0;
}
