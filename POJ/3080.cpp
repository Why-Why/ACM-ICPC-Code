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
		p=next[a]+a-(next[a]!=0);

		if(k+L-1>p)
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

	ret=p;
	extend[0]=p;

	for(int k=1;k<n;++k)
	{
		L=next[k-a];
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

char s0[200];
char s[20][100];
int m;
int next[200];
int extend[200];

bool judge(int x,int y)
{
	for(int i=0;i<60;++i)
		if(s0[x+i]!=s0[y+i])
			return s0[x+i]>s0[y+i];

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int ans,minn;
	int rem;

	scanf("%d",&T);

	while(T--)
	{
		ans=-1;

		scanf("%d",&m);

		scanf("%s",s0);
		for(int i=0;i<60;++i)
			s0[60+i]=s0[i];
		s0[120]=0;

		--m;

		for(int i=0;i<m;++i)
			scanf("%s",s[i]);

		for(int i=0;i<60;++i)
		{
			minn=10000;

			for(int j=0;j<m;++j)
				minn=min(minn,EKMP(60,s[j],60,s0+i,extend,next));

			if(!minn)
				continue;

			if(ans<minn)
			{
				ans=minn;
				rem=i;
			}
			else if(ans==minn)
				if(judge(rem,i))
					rem=i;
		}

		if(ans<3)
			printf("no significant commonalities\n");
		else
		{
			s0[rem+ans]=0;
			printf("%s\n",s0+rem);
		}
	}
	
	return 0;
}
