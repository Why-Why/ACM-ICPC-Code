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

int N,K;
char s[1010];

int getans(int x)
{
	int cou=0;
	char num[1010];
	int maxn;
	int cou1[1010];

	int i=0;
	while((N-K)*i+x<N)
	{
		num[cou++]=s[x+(N-K)*i];
		++i;
	}

	maxn=-100000000;
	for(int i=0;i<cou;++i)
	{
		cou1[i]=0;
		for(int j=0;j<cou;++j)
			if(num[i]==num[j])
				++cou1[i];

		if(cou1[i]>maxn)
			maxn=cou1[i];
	}

	return cou-maxn;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int ans=0;

	scanf("%d",&T);

	while(T--)
	{
		ans=0;
		scanf("%s",s);
		N=strlen(s);
		scanf("%d",&K);

		for(int i=0;i<min(K,N-K);++i)
			ans+=getans(i);

		printf("%d\n",ans);
	}
	
	return 0;
}
