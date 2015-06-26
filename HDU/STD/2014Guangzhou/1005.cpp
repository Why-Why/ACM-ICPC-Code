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
	char name[60];
	int val;

	bool operator < (const state & a) const
	{
		if(val==a.val)
			return strcmp(name,a.name)<0;

		return val>a.val;
	}
};

int cou[310];
int couji[310][210];
state sta[210];
int N;
int M;
char s[310];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int rank;

	while(~scanf("%d",&N) && N)
	{
		sta[0].val=0;

		for(int i=1;i<=N;++i)
			scanf("%s %d",sta[i].name,&sta[i].val);

		sort(sta+1,sta+1+N);

		for(int i=1;i<=N;++i)
			printf("%s %d\n",sta[i].name,sta[i].val);

		scanf("%d",&M);

		while(M--)
		{
			scanf("%s",s);

			for(int i=1;i<=N;++i)
			{
				if(sta[i].val==sta[i-1].val)
					++rank;
				else
					rank=1;

				if(strcmp(sta[i].name,s)==0)
				{
					printf("%d",i-rank+1);

					if(rank!=1)
						printf(" %d",rank);
					
					printf("\n");

					break;
				}
			}
		}
	}
	
	return 0;
}
