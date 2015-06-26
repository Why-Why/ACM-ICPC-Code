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

const int MaxN=200005;

char Mt[MaxN*2];
int Mp[MaxN*2];

int zans;

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
		{
			ret=Mp[i]-1;
			zans=i;
		}
	}

	return ret;
}

char s[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char c[3];
	int len;
	int ans;
	int d;
	int t;
	int lans,rans;

	while(~scanf("%s %s",c,s))
	{
		len=strlen(s);

		ans=Manacher(len,s);

		if(ans<2)
		{
			printf("No solution!\n");
			continue;
		}

		if(ans&1)
		{
			zans=zans/2-1;
			lans=zans-ans/2;
			rans=zans+ans/2;
		}
		else
		{
			zans=(zans+1)/2-1;
			lans=zans-ans/2;
			rans=zans-1+ans/2;
		}

		printf("%d %d\n",lans,rans);
		d='a'-c[0];

		for(int i=lans;i<=rans;++i)
		{
			t=(s[i]-'a'+d)%26;

			if(t<0)
				t+=26;

			printf("%c",t+'a');
		}

		printf("\n");
	}
	
	return 0;
}
