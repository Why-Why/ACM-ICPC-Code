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

int cou[1010];
int N,M;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b,c;
	int rem,maxn;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&M);

		memset(cou,0,sizeof(cou));

		while(M--)
		{
			scanf("%d %d %d",&a,&b,&c);
			for(int i=a;i<=b;++i)
				cou[i]+=c;
		}

		maxn=0;
		for(int i=1;i<=N;++i)
			if(cou[i]>maxn)
			{
				maxn=cou[i];
				rem=i;
			}

		printf("%d\n",rem);
	}
	
	return 0;
}
