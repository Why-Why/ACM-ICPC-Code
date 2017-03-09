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

int next1[MaxM];

void KMP_pre(int m,int s[])
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

int KMP(int n,int s1[],int m,int s2[])
{
	int i=0,j=0;
	
	KMP_pre(m,s2);

	while(i<n)
	{
		while(j!=-1 && s1[i]!=s2[j])
			j=next1[j];

		++i;
		++j;

		if(j>=m)
			return i-m+1;
	}

	return -1;
}

int s1[MaxN],s2[MaxM];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int n,m;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&n,&m);

		for(int i=0;i<n;++i)
			scanf("%d",&s1[i]);

		for(int j=0;j<m;++j)
			scanf("%d",&s2[j]);

		printf("%d\n",KMP(n,s1,m,s2));
	}

	return 0;
}
