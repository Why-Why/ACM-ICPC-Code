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

int wei[100005];
int shu[100005];
int N,M,K;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int temp;

	scanf("%d %d %d",&N,&M,&K);

	for(int i=1;i<=N;++i)
	{
		scanf("%d",&temp);

		wei[i]=temp;
		shu[temp]=i;
	}

	long long ans=0;

	while(M--)
	{
		scanf("%d",&temp);

		ans+=(shu[temp]-1)/K+1;

		if(shu[temp]==1)
			continue;

		--shu[temp];
		++shu[wei[shu[temp]]];
		wei[shu[temp]+1]=wei[shu[temp]];
		wei[shu[temp]]=temp;
	}

	cout<<ans<<endl;
	
	return 0;
}
