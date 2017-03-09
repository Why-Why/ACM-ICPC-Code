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

int cou;
int ans[MaxM];
char s[MaxM];
int next1[MaxM];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int len;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%s",s);

		len=strlen(s);

		EKMP_pre(len,s,next1);

		cou=0;

		for(int i=1;i<len;++i)
			if(next1[i]==len-i)
				ans[cou++]=i;
		ans[cou++]=len;

		printf("Case #%d: %d\n",cas++,cou);

		printf("%d",ans[0]);

		for(int i=1;i<cou;++i)
			printf(" %d",ans[i]);
		printf("\n");
	}
	
	return 0;
}
