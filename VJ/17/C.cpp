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

const int MaxL=1010*50;
const int MaxC=26;

int que[500010];
int first,last;

int ans[1100];

struct AC_auto
{
	int next[MaxL][MaxC],fail[MaxL],word[MaxL];		// 这个节点结尾的单词的个数。
	int root,Tp;

	int Newnode()
	{
		for(int i=0;i<MaxC;++i)
			next[Tp][i]=-1;
		word[Tp++]=0;

		return Tp-1;
	}

	bool notFu(char c)
	{
		if(c<='Z' && c>='A')
			return 0;

		return 1;
	}

	void Init()
	{
		Tp=0;
		root=Newnode();
		first=last=0;
	}

	void Insert(char s[],int id)
	{
		int p=root;
		for(int i=0;s[i];++i)
		{
			if(next[p][s[i]-'A']==-1)	next[p][s[i]-'A']=Newnode();
			p=next[p][s[i]-'A'];
		}
		
		word[p]=id;
	}

	void Build()
	{
		int p,temp;

		fail[root]=-1;
		que[last++]=root;

		while(last-first)
		{
			p=que[first++];
			for(int i=0;i<MaxC;++i)
				if(next[p][i]!=-1)
				{
					if(p==root)	fail[next[p][i]]=root;
					else
					{
						temp=fail[p];
						while(temp!=-1)
						{
							if(next[temp][i]!=-1)
							{
								fail[next[p][i]]=next[temp][i];
								break;
							}
							temp=fail[temp];
						}
						
						if(temp==-1)	fail[next[p][i]]=root;
					}
					que[last++]=next[p][i];
				}
		}
	}

	void Query(char s[])
	{
		int p=root,temp;
		int ret=0;

		for(int i=0;s[i];++i)
		{
			while(p!=root && (notFu(s[i]) || next[p][s[i]-'A']==-1))
				p=fail[p];
				
			if(!notFu(s[i]) && next[p][s[i]-'A']!=-1)	p=next[p][s[i]-'A'];
			else	p=root;

			temp=p;
			while(temp!=root)
			{
				if(word[temp])
					++ans[word[temp]];
	
				//	word[temp]=0;				//!!!
				temp=fail[temp];
			}
		}
	}
};

AC_auto myAC;
char s[2000006];
char st[1010][60];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;

	while(~scanf("%d",&N))
	{
	myAC.Init();

	memset(ans,0,sizeof(ans));

	for(int i=1;i<=N;++i)
	{
		scanf("%s",st[i]);

		myAC.Insert(st[i],i);
	}

	myAC.Build();

//	scanf("%s",s);

	getchar();
	gets(s);

	myAC.Query(s);

	for(int i=1;i<=N;++i)
		if(ans[i])
			printf("%s: %d\n",st[i],ans[i]);
	}
	
	return 0;
}
