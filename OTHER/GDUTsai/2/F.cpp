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

bool vis[110];
int ans[110];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int N,M;
	int a;

	scanf("%d",&T);

	while(T--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d %d",&N,&M);

		while(M--)
		{
			scanf("%d",&a);

			for(int i=a;i<=N;++i)
				if(!vis[i])
				{
					vis[i]=1;
					ans[i]=a;
				}
		}

		printf("%d",ans[1]);
		for(int i=2;i<=N;++i)
			printf(" %d",ans[i]);
		printf("\n");
	}
	
	return 0;
}
