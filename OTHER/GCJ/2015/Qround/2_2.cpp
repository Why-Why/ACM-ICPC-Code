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

bool judge(int x)
{
	int base=0;

	for(int i=1;i<=D;++i)
		if(P[i]>x)
}

int getans()
{
	int L=0,R=1001,M;

	while(R>L)
	{
		M=(L+R)/2;

		if(judge(M))
			R=M;
		else
			L=M+1;
	}

	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&D);

		for(int i=1;i<=D;++i)
			scanf("%d",&P[i]);

		printf("Case #%d: %d\n",cas++,getans());
	}
	
	return 0;
}
