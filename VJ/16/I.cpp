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

const int MaxN=70;
const int MaxM=70;

void EKMP_pre(int m,char s[],int next1[])
{
	int p=0,a=1,L;

	next1[0]=m;

	while(p+1<m && s[p]==s[p+1])
		++p;

	next1[1]=p;

	for(int k=2;k<m;++k)
	{
		L=next1[k-1];
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

int extend[MaxN],next1[MaxN];

int EKMP(int n,char s1[],int m,char s2[])
{
	int p=0,a=0,L;
	int ret;

	EKMP_pre(m,s2,next1);

	while(p<n && p<m && s1[p]==s2[p])
		++p;

	extend[0]=p;
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

		ret=max(ret,extend[k]);
	}

	return ret;
}

char s[15][70];
int m;
int ans;

int getans(char s2[],char s1[])
{
	return EKMP(strlen(s1),s1,strlen(s2),s2);
}

bool judge(int x,int y)
{
	for(int i=0;i<ans;++i)
		if(s[1][x+i]!=s[1][y+i])
			return s[1][x+i]>s[1][y+i];

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int rem;
	int temp;
	
	scanf("%d",&T);

	while(T--)
	{
		ans=0;
		rem=0;

		scanf("%d",&m);
		
		for(int i=1;i<=m;++i)
			scanf("%s",s[i]);

		for(int i=0;i<60;++i)
		{
			temp=70;

			for(int j=2;j<=m;++j)
				temp=min(temp,getans(&s[1][i],s[j]));

			if(temp>ans)
			{
				ans=temp;
				rem=i;
			}
			else if(temp==ans && judge(rem,i))
				rem=i;
		}

		if(ans<3)
			printf("no significant commonalities\n");
		else
		{
			for(int i=0;i<ans;++i)
				printf("%c",s[1][rem+i]);
			printf("\n");
		}
	}
	
	return 0;
}
