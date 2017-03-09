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

// 扩展KMP，复杂度 O(n+m)。
// 输入：s1及其长度n，s2及其长度m。
// 输出：extend(extend[i]表示s1[i...n-1]与s2[0...m-1]的最长公共前缀)，next(s2[i...m-1]与s2[0...m-1]的最长公共前缀)。
// 注意：字符串从0开始。
// 原理：KMP的next数组跳转的原理，记录最远位置p。

const int MaxN=210;
const int MaxM=210;

void EKMP_pre(int m,char s[],int next[])
{
	int p=0,a=1,L;

	next[0]=m;

	while(p+1<m && s[p]==s[p+1])
		++p;
	next[1]=p;

	for(int k=2;k<m;++k)
	{
		L=next[k-a];
		p=next[a]+a-(next[a]!=0);			/////

		if(k+L-1<p)
			next[k]=L;
		else
		{
			++p;
			while(p<m && s[p]==s[p-k])
				++p;

			next[k]=p-k;
			a=k;
		}
	}
}

int EKMP(int n,char s1[],int m,char s2[],int extend[],int next[])
{
	int p=0,a=0,L;
	int ret;

	EKMP_pre(m,s2,next);

	while(p<n && p<m && s1[p]==s2[p])
		++p;

	extend[0]=p;
	ret=p;

	for(int k=1;k<n;++k)
	{
		L=next[k-a];
		p=a+extend[a]-(extend[a]!=0);			/////

		if(k+L-1<p)
			extend[k]=L;
		else
		{
			++p;
			while(p<n && p-k<m && s1[p]==s2[p-k])
				++p;

			extend[k]=p-k;
			a=k;
		}

		ret=max(ret,extend[k]);
	}

	return ret;
}

int N;
char s[4010][210];
char s1[500];
int next1[MaxN],extend[MaxN];

bool judge(int x,int y,int L)
{
	for(int i=0;i<L;++i)
		if(s1[y+i]!=s1[x+i])
			return s1[y+i]<s1[x+i];

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ans,zans;
	int rem;

	while(~scanf("%d",&N) && N)
	{
		getchar();
		--N;
		gets(s1);

		for(int i=1;i<=N;++i)
			gets(s[i]);

		int len=strlen(s1);

		for(int i=0;i<len;++i)
			s1[len+i]=s1[len];
		s1[len+len]=0;

		zans=0;

		for(int i=0;i<len;++i)
		{
			ans=300;

			for(int j=1;j<=N;++j)
				ans=min(ans,EKMP(strlen(s[j]),s[j],len,s1+i,extend,next1));

			if(ans>zans)
			{
				rem=i;
				zans=ans;
			}
			else if(ans==zans)
				if(judge(rem,i,zans))
					rem=i;
		}

		if(zans==0)
			puts("IDENTITY LOST");
		else
		{
			s1[rem+zans]=0;
			puts(s1+rem);
		}
	}
	
	return 0;
}
