#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int MaxU=110;
const int MaxV=310;

int vis[MaxV];
int flag;
int linker[MaxV];
int uN,vN;
int line[MaxU][MaxV];

bool find(int u)
{
	for(int v=1;v<=vN;++v)
		if(line[u][v] && vis[v]!=flag)
		{
			vis[v]=flag;

			if(linker[v]==-1 || find(linker[v]))
			{
				linker[v]=u;
				
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
		++flag;

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
	flag=0;

	for(int i=1;i<=vN;++i)
	{
		linker[i]=-1;
		vis[i]=0;

		for(int j=1;j<=uN;++j)
			line[j][i]=0;
	}
}

void slove()
{
	if(uN>vN)
	{
		printf("NO\n");
		return;
	}

	if(Hungary()>=uN)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int T;
	int P,N;
	int temp,t;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&P,&N);

		init(P,N);

		for(int i=1;i<=P;++i)
		{
			scanf("%d",&t);
			while(t--)
			{
				scanf("%d",&temp);
				addEdge(i,temp);
			}
		}

		slove();
	}

	return 0;
}
