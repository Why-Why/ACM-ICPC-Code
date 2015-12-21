// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年08月13日 星期四 14时22分56秒
// File Name     : 1005.cpp

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

const int MaxL=100010*10;
const int MaxC=26;

int que[500010];
int first,last;
long long ans[100005];

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

	void Query(char s[])
	{
		int p=root,temp;
		int ttt=1;

		for(int i=0;s[i];++i)
		{
			if(s[i]=='#')
			{
				++ttt;
				p=root;
				continue;
			}

			while(p!=root && next[p][s[i]-'a']==-1)
				p=fail[p];
				
			if(next[p][s[i]-'a']!=-1)	p=next[p][s[i]-'a'];
			else	p=root;

			temp=p;
			while(temp!=root)
			{
				ans[ttt]+=word[temp];
				temp=fail[temp];
			}
		}
	}
}tree;

char B[100005];
char zA[MaxL];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int N,M;
	int p,t;

	scanf("%d",&T);

	while(T--)
	{
		tree.Init();
		scanf("%d %d",&N,&M);
		p=0;
		for(int i=1;i<=N;++i)
		{
			ans[i]=0;
			scanf("%s",zA+p);
			t=strlen(zA+p);
			zA[p+t]='#';
			p+=t+1;
		}

		for(int i=1;i<=M;++i)
		{
			scanf("%s",B);
			tree.Insert(B);
		}

		tree.Build();
		tree.Query(zA);

		for(int i=1;i<=N;++i)
			printf("%I64d\n",ans[i]);
	}
	
	return 0;
}
