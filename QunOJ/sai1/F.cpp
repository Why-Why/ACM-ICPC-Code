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
int map1[50][50];

int getans()
{
	int temp;

	temp=100;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
		{
			if(i==j && map1[i][j]!=0)
				return 1;

			if(i!=j && map1[i][j]<=0)
				temp=min(temp,2);

			if(map1[i][j]!=map1[j][i])
				temp=min(temp,3);

			if(temp<4)
				continue;

			for(int k=1;k<=N;++k)
				if(i!=j && i!=k && j!=k && map1[i][j]+map1[j][k]<map1[i][k])
					temp=min(temp,4);
		}

	return temp<100 ? temp : 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				scanf("%d",&map1[i][j]);

		printf("%d\n",getans());
	}
	
	return 0;
}
