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

const int MaxN=30;
const int MaxM=100000;

struct Edge
{
	int next,to;
};

Edge E[MaxM];
int head[MaxN],Ecou;

void init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int N,M;
char s[20];
int pai[100];
int ru[100];
bool vis[30];

inline int find(int tru[])
{
	int ret=0;

	for(int i=1;i<=N;++i)
		if(tru[i]==0 && vis[i]==0)
			if(ret==0)
				ret=i;
			else
				return -1;

	return ret;
}

inline bool judge()
{
	int temp;
	int tru[30];

	for(int i=1;i<=N;++i)
		tru[i]=ru[i];

	for(int i=1;i<=N;++i)
	{
		temp=0;

		for(int j=1;j<=N;++j)
			if(tru[j]==0)
			{
				temp=j;
				tru[j]=-1;
				break;
			}

		if(temp==0)
			return 0;

		for(int j=head[temp];j!=-1;j=E[j].next)
			--tru[E[j].to];
	}

	return 1;
}

int paixu()
{
	int temp=0;
	int tru[100];
	int cou=1;
	
	memset(vis,0,sizeof(vis));

	if(judge()==0)
		return -1;

	for(int i=1;i<=N;++i)
		tru[i]=ru[i];

	while(cou<=N)
	{
		temp=find(tru);

		if(temp==0)
			return -1;
		else if(temp==-1)
			return 0;

		pai[cou++]=temp;
		vis[temp]=1;

		for(int i=head[temp];i!=-1;i=E[i].next)
			--tru[E[i].to];
	}

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ret;
	bool ok;
	int rem;

	while(~scanf("%d %d",&N,&M) && N+M)
	{
		init();
		ok=1;
		rem=0;
		memset(ru,0,sizeof(ru));

		for(int i=1;i<=M;++i)
		{
			scanf("%s",s);
			addEdge(s[0]-'A'+1,s[2]-'A'+1);

			++ru[s[2]-'A'+1];

			if(!ok)
				continue;

			ret=paixu();
			
			if(ret==1 && !rem)
			{
				printf("Sorted sequence determined after %d relations: ",i);

				for(int j=1;j<=N;++j)
					printf("%c",pai[j]-1+'A');

				printf(".\n");

				ok=0;
			}
			else if(ret==-1)
			{
				ok=0;
				printf("Inconsistency found after %d relations.\n",i);
			}
		}

		if(!ok)
			continue;

		if(rem==0)
			printf("Sorted sequence cannot be determined.\n");
		else
		{
			printf("Sorted sequence determined after %d relations: ",rem);

			for(int i=1;i<=N;++i)
				printf("%c",pai[i]-1+'A');

			printf(".\n");
		}
	}
	
	return 0;
}
