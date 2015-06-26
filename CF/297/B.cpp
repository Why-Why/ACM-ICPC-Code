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

char s[300000];
int num[200000];
int rem[200000];
int remlen[200000];
int remcou=0;
int m,len;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%s",s+1);
	len=strlen(s+1);

	scanf("%d",&m);

	for(int i=1;i<=m;++i)
		scanf("%d",&num[i]);

	sort(num+1,num+m+1);

	num[0]=0;
	num[m+1]=len/2+1;
	int cou=0;

	for(int i=1;i<=m+1;++i)
	{
		if(num[i]!=num[i-1])
		{
			if(cou&1)
			{
				rem[remcou]=num[i-1];
				remlen[remcou++]=num[i];
			}
		}

		++cou;
	}

	int p=0;

	rem[remcou]=len+1;

	for(int i=1;i<=len;++i)
	{
		if(i>=rem[p])
		{
			while(i<remlen[p])
			{
				swap(s[i],s[len-i+1]);
				++i;
			}

			--i;
			++p;
		}
	}

	printf("%s\n",s+1);

	return 0;
}
