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

const int MaxL=60010;
const int MaxC=256;

int que[100010];
int first,last;

bool vis[MaxL];

int N;

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

	void Init()
	{
		Tp=0;
		root=Newnode();
		first=last=0;
	}

	void Insert(int s[],int id)
	{
		int p=root;
		for(int i=0;s[i]!=-1;++i)
		{
			if(next[p][s[i]]==-1)	next[p][s[i]]=Newnode();
			p=next[p][s[i]];
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

	int Query(int s[])
	{
		int p=root,temp;
		int ret=0;

		for(int i=0;s[i]!=-1;++i)
		{
			while(p!=root && next[p][s[i]]==-1)
				p=fail[p];
				
			if(next[p][s[i]]!=-1)	p=next[p][s[i]];
			else	p=root;

			temp=p;
			while(temp!=root)
			{
				if(word[temp])
				{
					vis[word[temp]]=1;
				}

//				word[temp]=0;				//!!!
				temp=fail[temp];
			}
		}

		for(int i=1;i<=N;++i)
			if(vis[i])
				++ret;

		return ret;
	}
};

AC_auto myAC;
int num[3000*8];
int cou;

void change2toS(int n)
{
	for(int i=5;i>=0;--i)
		if(n & (1<<i))
			num[cou+5-i]=1;
		else
			num[cou+5-i]=0;

	cou+=6;
}

int changeStoC(int *n)
{
	int ret=0;

	for(int i=0;i<8;++i)
		ret=ret*2+n[i];

	return ret;
}

int getnum(char c)
{
	if(c>='A' && c<='Z')
		return c-'A';

	if(c>='a' && c<='z')
		return c-'a'+26;

	if(c>='0' && c<='9')
		return c-'0'+52;

	if(c=='+')
		return 62;

	if(c=='/')
		return 63;
}

void change(char s[],int sn[])
{
	int len=strlen(s);
	int hou=0;

	cou=0;

	if(s[len-2]=='=')
		hou=2,len-=2;
	else if(s[len-1]=='=')
		hou=1,len-=1;

	int L=len*6-hou*2;

	for(int i=0;i<len;++i)
	{
		int temp=getnum(s[i]);

		change2toS(temp);
	}

	for(int i=0;i<L;i+=8)
		sn[i/8]=changeStoC(&num[i]);

	sn[L/8]=-1;
}

char s[40000];
int sn[40000];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M;

	while(~scanf("%d",&N))
	{
		myAC.Init();

		for(int i=1;i<=N;++i)
		{
			scanf("%s",s);

			change(s,sn);

			myAC.Insert(sn,i);
		}

		scanf("%d",&M);

		while(M--)
		{
			scanf("%s",s);
			memset(vis,0,sizeof(vis));

			change(s,sn);
			printf("%d\n",myAC.Query(sn));
		}

		printf("\n");
	}
	
	return 0;
}
