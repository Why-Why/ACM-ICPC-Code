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

const int MaxL=100010*5;
const int MaxC=26;

int que[500010];
int first,last;

struct AC_auto
{
	int next[MaxL][MaxC],fail[MaxL],word[MaxL];
	int root,Tp;

	int Newnode()
	{
		for(int i=0;i<MaxC;++i)
			next[Tp][i]=-1;
		word[Tp++]=0;

		return Tp-1;
	}

	void Init()
	{
		Tp=0;
		root=Newnode();
		first=last=0;
	}

	void Insert(char s[])
	{
		int p=root;
		for(int i=0;s[i];++i)
		{
			if(next[p][s[i]-'a']==-1)	next[p][s[i]-'a']=Newnode();
			p=next[p][s[i]-'a'];
		}
		++word[p];
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

	int Query(char s[])
	{
		int p=root,temp;
		int ret=0;

		for(int i=0;s[i];++i)
		{
			while(p!=root && next[p][s[i]-'a']==-1)
				p=fail[p];
				
			if(next[p][s[i]-'a']!=-1)	p=next[p][s[i]-'a'];
			else	p=root;

			temp=p;
			while(temp!=root)
			{
				ret+=word[temp];
				word[temp]=0;
				temp=fail[temp];
			}
		}
		return ret;
	}
};

AC_auto AC;

char s1[75],s2[1000016];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int n;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&n);
		getchar();

		AC.Init();

		while(n--)
		{
			gets(s1);
			AC.Insert(s1);
		}
		scanf("%s",s2);

		AC.Build();

		printf("%d\n",AC.Query(s2));
	}
	
	return 0;
}
