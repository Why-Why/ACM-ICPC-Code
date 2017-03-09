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

char map1[2010][2010];
int N,M;

int gethang(int x)
{
	for(int i=1;i<=M/2;++i)
		if(map1[x][i]!=map1[x][M+1-i])
			return M/2-i+1;

	return 1;
}

int getlie(int x)
{
	for(int i=1;i<=N/2;++i)
		if(map1[i][x]!=map1[N+1-i][x])
			return N/2-i+1;

	return 1;
}

bool judge()
{
	for(int i=1;i<=M/2;++i)
		if(map1[1][i]!=map1[1][M+1-i])
			return 0;
		else if(map1[N][i]!=map1[N][M+1-i])
			return 0;

	for(int i=1;i<=N/2;++i)
		if(map1[i][1]!=map1[N+1-i][1])
			return 0;
		else if(map1[i][M]!=map1[N+1-i][M])
			return 0;

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int hangmax,liemax;
	int ans;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);

		for(int i=1;i<=N;++i)
			scanf("%s",map1[i]+1);

		if(judge()==0)
		{
			printf("0\n");
			continue;
		}

		if(N==2 || M==2)
		{
			printf("0\n");
			continue;
		}

		hangmax=liemax=0;

		for(int i=2;i<N;++i)
			hangmax=max(hangmax,gethang(i));

		for(int i=2;i<M;++i)
			liemax=max(liemax,getlie(i));

		printf("%d\n",((N/2-liemax)*(M/2-hangmax)));
	}
	
	return 0;
}
