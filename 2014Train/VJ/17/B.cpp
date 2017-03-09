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

const int MaxL=200*500;
const int MaxC=96;

int que[MaxL];
int first,last;

int next1[MaxL][MaxC],fail[MaxL];
int word[MaxL];
int root,Tp;

inline int Newnode()
{
	memset(next1[Tp],-1,sizeof(next1[Tp]));
	word[Tp++]=0;

	return Tp-1;
}

inline void Init()
{
	Tp=0;
	root=Newnode();
	first=last=0;
}

inline void Insert(char s[],int id)
{
	int p=root;

	for(int i=0;s[i];++i)
	{
		if(next1[p][s[i]-32]==-1)
			next1[p][s[i]-32]=Newnode();

		p=next1[p][s[i]-32];
	}

	word[p]=id;
}

inline void Build()
{
	int p,temp;

	fail[root]=-1;
	que[last++]=root;

	while(last-first)
	{
		p=que[first++];

		for(int i=0;i<MaxC;++i)
			if(next1[p][i]!=-1)
			{
				if(p==root)
					fail[next1[p][i]]=root;
				else
				{
					temp=fail[p];

					while(temp!=-1)
					{
						if(next1[temp][i]!=-1)
						{
							fail[next1[p][i]]=next1[temp][i];
							break;
						}

						temp=fail[temp];
					}

					if(temp==-1)
						fail[next1[p][i]]=root;
				}

				que[last++]=next1[p][i];
			}
	}
}

int ans[510];
int cou;

inline void Query(char s[])
{
	cou=0;

	int p=root,temp;
	int ret=0;

	for(int i=0;s[i];++i)
	{
		while(p!=root && next1[p][s[i]-32]==-1)
			p=fail[p];

		if(next1[p][s[i]-32]!=-1)
			p=next1[p][s[i]-32];
		else
			p=root;

		temp=p;

		while(temp!=root)
		{
			if(word[temp])
				ans[cou++]=word[temp];

			temp=fail[temp];
		}
	}
}

char s[10004];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	int tot=0;

	scanf("%d",&N);

	Init();

	for(int i=1;i<=N;++i)
	{
		scanf("%s",s);
		Insert(s,i);
	}

	Build();

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
	{
		scanf("%s",s);
		Query(s);

		if(cou)
		{
			printf("web %d:",i);

			sort(ans,ans+cou);

			for(int i=0;i<cou;++i)
				printf(" %d",ans[i]);
			printf("\n");

			++tot;
		}
	}

	printf("total: %d\n",tot);
	
	return 0;
}
