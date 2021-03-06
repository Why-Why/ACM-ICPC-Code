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

int next1[MaxM];

void EKMP_pre(int m,char s[])
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

	next1[m]=0;
}

char s[MaxM];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int len;

	while(~scanf("%s",s))
	{
		if(s[0]=='.' && s[1]==0)
			break;

		len=strlen(s);

		EKMP_pre(len,s);

		for(int i=1;i<=len;++i)
			if(next1[i]+i==len && len%i==0)
			{
				printf("%d\n",len/i);
				break;
			}
	}
	
	return 0;
}
