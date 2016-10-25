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
// Created Time  : 2016年07月17日 星期日 22时30分06秒
// File Name     : F.cpp

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

const int MaxL=300;
const int MaxC=26;

int que[MaxL];
int first,last;

char s[MaxL];
int N;
long long L;
int val[MaxL];

long long dp[1000][MaxL];

struct AC_auto
{
	int next[MaxL][MaxC],fail[MaxL];
	long long word[MaxL];		// 这个节点结尾的单词的个数。
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

	void Insert(char s[],long long val)
	{
		int p=root;
		for(int i=0;s[i];++i)
		{
			if(next[p][s[i]-'a']==-1)	next[p][s[i]-'a']=Newnode();
			p=next[p][s[i]-'a'];
		}
		word[p]+=val;
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
				word[temp]=0;				// !!!
				//temp=fail[temp];			// 需要时要修改。
			}
		}
		return ret;
	}

	long long getans() {
		int temp,p;
		long long sum;

		memset(dp,-1,sizeof(dp));
		dp[0][0]=0;

		for(int i=0;i<L-1;++i) {
			for(int j=0;j<Tp;++j) {
				if(dp[i][j]==-1) continue;
				for(int c=0;c<26;++c) {
					p=j;
					while(p!=root && next[p][c]==-1) p=fail[p];

					if(next[p][c]!=-1) {
						p=next[p][c];

						temp=p;
						sum=0;
						while(temp!=root) {
							sum+=word[temp];
							temp=fail[temp];
						}

						if(dp[i+1][p]==-1) dp[i+1][p]=sum;
						else dp[i+1][p]+=sum;
					}
				}
			}
		}

		sum=0;
		for(int i=0;i<Tp;++i)
			sum=max(sum,dp[L-1][i]);
		return sum;
	}

}AC;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %I64d",&N,&L);
	for(int i=1;i<=N;++i) scanf("%d",val+i);

	AC.Init();
	for(int i=1;i<=N;++i) {
		scanf("%s",s);
		AC.Insert(s,val[i]);
	}
	AC.Build();
	printf("%I64d\n",AC.getans());

	return 0;
}
