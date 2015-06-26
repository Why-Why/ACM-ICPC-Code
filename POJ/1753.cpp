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

char map1[10][10];

int getans(int fang,int t)
{
	int ret=0;
	int num[10][10]={0};

	for(int i=1;i<=4;++i)
		if(fang & (1<<(i-1)))
		{
			num[1][i]=1;
			++ret;
		}

	for(int i=2;i<=4;++i)
		for(int j=1;j<=4;++j)
			if((num[i-1][j]+num[i-1][j-1]+num[i-1][j+1]+num[i-2][j]+(map1[i-1][j]=='b'))%2!=t)
			{
				num[i][j]=1;
				++ret;
			}

	bool ok=1;

	for(int i=1;i<=4;++i)
		if((num[4][i]+num[4][i-1]+num[4][i+1]+num[3][i]+(map1[4][i]=='b'))%2!=t)
			ok=0;

	if(ok==0)
		return 100000000;

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ans=100000000;

	while(~scanf("%s",map1[1]+1))
	{
		ans=100000000;
		for(int i=2;i<=4;++i)
			scanf("%s",map1[i]+1);

		for(int i=0;i<16;++i)
		{
			ans=min(ans,getans(i,0));
			ans=min(ans,getans(i,1));
		}

		if(ans<100000000)
			printf("%d\n",ans);
		else
			printf("Impossible\n");
	}
	
	return 0;
}
