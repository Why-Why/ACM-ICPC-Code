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

const int MaxU=1010;
const int MaxV=510;

bool vis[MaxV];
int linker[MaxV][MaxU];
int uN,vN;
int line[MaxU][MaxV];
int vDec;

bool find(int u)
{
	for(int v=1;v<=vN;++v)
		if(line[u][v] && !vis[v])
		{
			vis[v]=1;

			if(linker[v][0]<vDec)
			{
				linker[v][++linker[v][0]]=u;

				return 1;
			}

			for(int i=1;i<=linker[v][0];++i)
				if(find(linker[v][i]))
				{
					linker[v][i]=u;

					return 1;
				}
		}

	return 0;
}

int Hungary()
{
	int ret=0;

	for(int u=1;u<=uN;++u)
	{
		memset(vis,0,sizeof(vis));

		if(find(u))
			++ret;
	}

	return ret;
}

void addEdge(int u,int v)
{
	line[u][v]=1;
}

void init(int _uN,int _vN)
{
	uN=_uN;
	vN=_vN;

	for(int i=1;i<=vN;++i)
	{
		linker[i][0]=0;

		for(int j=1;j<=uN;++j)
			line[j][i]=0;
	}
}

int N,M;

void slove()
{
	int L=1,R=uN,Mid;

	while(R>L)
	{
		Mid=(L+R)/2;

		vDec=Mid;
		for(int i=1;i<=vN;++i)
			linker[i][0]=0;

		if(Hungary()>=uN)
			R=Mid;
		else
			L=Mid+1;
	}

	printf("%d\n",L);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int temp;
	char name[20];

	while(scanf("%d %d",&N,&M)&&(N||M))
	{
		init(N,M);

		for(int i=1;i<=uN;++i)
		{
			scanf("%s",name);

			while(getchar()!='\n')
			{
				scanf("%d",&temp);

				addEdge(i,temp+1);
			}
		}

		slove();
	}

	return 0;
}
