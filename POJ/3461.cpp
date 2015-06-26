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

const int MaxN=1000006;
const int MaxM=10004;

int next[MaxM];

void KMP_pre(int m,char s[])
{
	int i=0,j=-1;

	next[0]=-1;

	while(i<m)
	{
		while(j!=-1 && s[i]!=s[j])
			j=next[j];

		++i;
		++j;

		next[i]=j;
	}
}

int KMP(int n,char s1[],int m,char s2[])
{
	int i=0,j=0;
	int ret=0;

	while(i<n)
	{
		while(j!=-1 && s1[i]!=s2[j])
			j=next[j];

		++i;
		++j;

		if(j>=m)
		{
			++ret;
			j=next[j];
		}
	}

	return ret;
}

char s1[MaxN],s2[MaxM];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n,m;
	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%s %s",s2,s1);

		n=strlen(s1);
		m=strlen(s2);

		KMP_pre(m,s2);

		printf("%d\n",KMP(n,s1,m,s2));
	}
	
	return 0;
}
