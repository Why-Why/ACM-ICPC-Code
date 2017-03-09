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

const int MaxN=1010;

int fa[MaxN];

int find(int x)
{
	if(fa[x]==-1)
		return x;

	fa[x]=find(fa[x]);
	
	return fa[x];
}

int X[MaxN],Y[MaxN];
bool vis[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N,D;
	char c[5];
	int a,b;

	memset(fa,-1,sizeof(fa));

	scanf("%d %d",&N,&D);

	for(int i=1;i<=N;++i)
		scanf("%d %d",&X[i],&Y[i]);

	while(~scanf("%s",c))
	{
		if(c[0]=='O')
		{
			scanf("%d",&a);

			if(!vis[a])
			{
				vis[a]=1;

				for(int i=1;i<=N;++i)
					if(vis[i] && i!=a && (X[i]-X[a])*(X[i]-X[a])+(Y[i]-Y[a])*(Y[i]-Y[a])<=D*D && find(i)!=find(a))
						fa[find(i)]=find(a);
			}
		}
		else
		{
			scanf("%d %d",&a,&b);

			if(vis[a] && vis[b] && find(a)==find(b))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
	
	return 0;
}
