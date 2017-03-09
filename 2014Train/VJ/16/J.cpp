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

const int MaxN=50004;
const int MaxM=50004;

void EKMP_pre(int m,char s[],int next1[])
{
	int p=0,a=1,L;

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

int EKMP(int n,char s1[],int m,char s2[],int extend[],int next1[])
{
	int p=0,a=0,L;
	int ret=0;

	EKMP_pre(m,s2,next1);

	while(p<n && p<m && s1[p]==s2[p])
		++p;

	extend[0]=p;

	if(p==n)
		ret=p;

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

		if(k+extend[k]==n)
			ret=max(ret,extend[k]);
	}

	return ret;
}

int next1[MaxN],extend[MaxN];
char s1[MaxN],s2[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%s %s",s2,s1))
	{
		int ans=EKMP(strlen(s1),s1,strlen(s2),s2,extend,next1);

		if(ans)
		{
			s2[ans]=0;
			printf("%s %d\n",s2,ans);
		}
		else
			printf("0\n");
	}
	
	return 0;
}
