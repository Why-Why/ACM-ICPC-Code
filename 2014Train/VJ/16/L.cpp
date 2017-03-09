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

const int MaxN=100005;
const int MaxM=MaxN;

void EKMP_pre(int m,char s[],int next1[])
{
	int p=0,L,a=1;

	next1[0]=m;

	while(p+1<m && s[p]==s[p+1])
		++p;

	next1[1]=p;

	for(int k=2;k<m;++k)
	{
		L=next1[k-a];
		p=next1[a]+a-(next1[a]!=0);

		if(k+L-1<p)
			next1[k]=L;
		else
		{
			++p;

			while(p<m && s[p]==s[p-k])
				++p;

			next1[k]=p-k;
			a=k;
		}
	}
}

void EKMP(int n,char s1[],int m,char s2[],int extend[],int next1[])
{
	int p=0,a=0,L;

	EKMP_pre(m,s2,next1);

	while(p<n && p<m && s1[p]==s2[p])
		++p;

	extend[0]=p;

	for(int k=1;k<n;++k)
	{
		L=next1[k-a];
		p=a+extend[a]-(extend[a]!=0);

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
	}

	extend[n]=0;
}

int next1[MaxM];
int extend[MaxN];
char s[MaxN];
char s1[MaxN];
char table[30];
char table1[30];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int len;
	int ans;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%s",table1);
		scanf("%s",s);

		len=strlen(s);

		for(int i=0;i<26;++i)
			table[table1[i]-'a']=i+'a';

		for(int i=0;i<len;++i)
			s1[i]=table[s[i]-'a'];

		EKMP(len,s,len,s1,extend,next1);

		for(ans=len/2;ans<=len;++ans)
			if(ans+ans>=len && extend[ans]+ans==len)
				break;

		for(int i=0;i<ans;++i)
			printf("%c",s[i]);
		for(int i=0;i<ans;++i)
			printf("%c",table[s[i]-'a']);

		printf("\n");
	}
	
	return 0;
}
