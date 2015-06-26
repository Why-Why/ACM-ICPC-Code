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

char s[MaxM];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	int a,b,t;
	int len;

	scanf("%d",&N);

	while(N--)
	{
		scanf("%s",s);

		len=strlen(s);

		KMP_pre(len,s);

		a=next1[len];

		b=0;

		for(int i=2;i<len;++i)
		{
			t=min(next1[i],i/2);
			t=min(t,len-i);
			b=max(b,t);
		}

		printf("%d\n",min(a,b));
	}
	
	return 0;
}
