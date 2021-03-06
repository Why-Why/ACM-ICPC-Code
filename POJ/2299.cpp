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

long long num[500005];
long long tnum[500005];

long long getans(int L,int R)
{
	if(L==R)
		return 0;

	int M=(L+R)>>1;
	long long ret=getans(L,M)+getans(M+1,R);
	int p1=L,p2=M+1;
	int cou=0;

	while(p1<=M || p2<=R)
	{
		if(p2<=R && (p1>M || num[p2]<num[p1]))
		{
			ret+=M-p1+1;
			tnum[cou++]=num[p2++];
		}
		else
			tnum[cou++]=num[p1++];
	}

	for(int i=0;i<cou;++i)
		num[L+i]=tnum[i];

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;

	while(scanf("%d",&N) && N)
	{
		for(int i=1;i<=N;++i)
			scanf("%lld",&num[i]);

		printf("%lld\n",getans(1,N));
	}
	
	return 0;
}
