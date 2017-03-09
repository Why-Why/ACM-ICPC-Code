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

const int MaxM=1000006;
const int MaxN=MaxM*2;

int next1[MaxM];

void KMP_pre(int m,char s[])
{
	int i=0,j=-1;

	next1[0]=-1;

	while(i<m)
	{
		while(j!=-1 && s[i]!=s[j])
			j=next1[j];

		++i;
		++j;

		next1[i]=j;
	}
}

int KMP(int n,char s1[],int m,char s2[])
{
	int i=0,j=0;
	int ret=0;

	KMP_pre(m,s2);

	while(i<n)
	{
		while(j!=-1 && s1[i]!=s2[j])
			j=next1[j];

		++i;
		++j;

		if(j>=m)
		{
			++ret;
			j=next1[j];
		}
	}

	return ret;
}

int MinRepre(int len,char s[])
{
	int i=0,j=1,k;
	
	while(i<len && j<len)
	{
		k=0;

		while(s[i+k]==s[j+k] && k<len)
			++k;

		if(k==len)
			return min(i,j);

		if(s[i+k]>s[j+k])
			i=max(j+1,i+k+1);
		else
			j=max(i+1,j+k+1);
	}

	return min(i,j);
}

int MaxRepre(int len,char s[])
{
	int i=0,j=1,k;
	
	while(i<len && j<len)
	{
		k=0;

		while(s[i+k]==s[j+k] && k<len)
			++k;

		if(k==len)
			return min(i,j);

		if(s[i+k]<s[j+k])
			i=max(j+1,i+k+1);
		else
			j=max(i+1,j+k+1);
	}

	return min(i,j);
}

char s[MaxN*2];
int len;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ans;

	while(~scanf("%s",s))
	{
		len=strlen(s);

		for(int i=0;i<len;++i)
			s[len+i]=s[i];
		s[len+len]=0;

		ans=MinRepre(len,s);

		printf("%d %d",ans+1,KMP(len*2-1,s,len,s+ans));
		
		ans=MaxRepre(len,s);

		printf(" %d %d\n",ans+1,KMP(len*2-1,s,len,s+ans));
	}
	
	return 0;
}
