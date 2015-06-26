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

const int MaxN=110;
const int MaxM=110;

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

char s1[300];
char s[210][110];
int n;
int next1[MaxN],extend[MaxN];

void rever(int x)
{
	int len=strlen(s[x*2-1]);

	for(int i=0;i<len;++i)
		s[x*2][i]=s[x*2-1][len-1-i];
	s[x*2][len]=0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	char temp;
	int ans,tans;
	int zans;

	scanf("%d",&T);

	while(T--)
	{
		zans=0;
		scanf("%d",&n);
		--n;

		scanf("%s",s1);

		int len=strlen(s1);

		for(int i=0;i<len;++i)
			s1[len+i]=s1[i];
		s1[len+len]=0;

		for(int i=1;i<=n;++i)
		{
			scanf("%s",s[i*2-1]);
			rever(i);
		}

		for(int i=0;i<len;++i)
		{
			temp=s1[i+len];
			s1[i+len]=0;

			ans=200;

			for(int j=1;j<=n;++j)
			{
				tans=EKMP(strlen(s[j*2-1]),s[j*2-1],len,s1+i,extend,next1);
				tans=max(tans,EKMP(strlen(s[j*2]),s[j*2],len,s1+i,extend,next1));

				ans=min(tans,ans);
			}

			s1[i+len]=temp;

			zans=max(zans,ans);
		}

		printf("%d\n",zans);
	}
	
	return 0;
}
