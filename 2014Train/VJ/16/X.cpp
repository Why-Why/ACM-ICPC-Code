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

const int MaxN=110104;

char Mt[MaxN*2];
int Mp[MaxN*2];

int Manacher(int len,char s[])
{
	int Mx=0,id=0,l=0;
	int ret=0;

	Mt[l++]='$';
	Mt[l++]='#';

	for(int i=0;i<len;++i)
	{
		Mt[l++]=s[i];
		Mt[l++]='#';
	}

	Mt[l]=0;

	for(int i=1;i<l;++i)
	{
		if(Mx>i)
			Mp[i]=min(Mp[2*id-i],Mx-i);
		else
			Mp[i]=1;

		while(Mt[i+Mp[i]]==Mt[i-Mp[i]])
			++Mp[i];

		if(Mp[i]+i>Mx)
		{
			Mx=Mp[i]+i;
			id=i;
		}

		if(Mp[i]-1>ret)
			ret=Mp[i]-1;
	}

	return ret;
}

char s[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%s",s))
	{
		printf("%d\n",Manacher(strlen(s),s));
	}
	
	return 0;
}
