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

const int MaxN=500005;

char Mt[MaxN*2];
int Mp[MaxN*2];
int zlen;

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
	zlen=l;
	
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
int num[30];
int sum[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int len;
	int ans,temp;

	scanf("%d",&T);

	while(T--)
	{
		for(int i=0;i<26;++i)
			scanf("%d",&num[i]);
		scanf("%s",s);

		len=strlen(s);

		sum[0]=num[s[0]-'a'];

		for(int i=1;i<len;++i)
			sum[i]=sum[i-1]+num[s[i]-'a'];

		Manacher(len,s);

		ans=0;

		for(int i=0;i<len-1;++i)
		{
			temp=0;

			if(Mp[i+2]-1==i+1)
				temp+=sum[i];

			if(Mp[i+len+2]-1==len-i-1)
				temp+=sum[len-1]-sum[i];

			ans=max(ans,temp);
		}

		printf("%d\n",ans);
	}
	
	return 0;
}
