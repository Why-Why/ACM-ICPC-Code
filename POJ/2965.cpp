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
int num[65540][5][5];
int wei[70000];
int numx[65540][5],numy[65540][5];
int ans[65540];

inline int getwei(int x)
{
	int ret=0;

	while(x)
	{
		if(x&1)
			++ret;

		x>>=1;
	}

	return ret;
}

inline bool judge(int m,int x)
{
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j)
			if((((m&(1<<((i-1)*4+j-1)))!=0)+numx[x][i]+numy[x][j]-num[x][i][j])&1)
				return 0;

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int remm;
	int minn;

	for(int i=0;i<(1<<16);++i)
	{
		wei[i]=getwei(i);

		for(int j=0;j<4;++j)
			for(int k=0;k<4;++k)
				if(i & (1<<(j*4+k)))
				{
					++numx[i][j+1];
					++numy[i][k+1];
					num[i][j+1][k+1]=1;
				}
	}

	for(int m=0;m<(1<<16);++m)
	{
		minn=100000;

		for(int i=0;i<(1<<16);++i)
			if(wei[i]<minn && judge(m,i))
			{
				minn=wei[i];
				remm=i;
			}

		ans[m]=remm;

		printf("%d,",ans[m]);
	}

	return 0;
}
