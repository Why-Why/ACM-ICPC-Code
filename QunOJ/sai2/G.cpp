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

char s[100005];
int N;

const int MaxN=100005;

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
		
		if(Mp[i]-l>ret)
			ret=Mp[i]-l;
	}

	return ret;
}

bool judge(int x,int y)
{
	if(x>y)
		return 0;

	if(Mp[x+y+2]>=y-x+1)
		return 1;

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%s",s);
		N=strlen(s);

		int i,ans=-10;

		Manacher(N,s);

		for(i=0;N-1-i>i;++i)
			if(s[i]!=s[N-1-i])
				break;
			else if(judge(i+1,N-1-i))
			{
				if(ans<0 || ans>i)
					ans=i;
			}
			else if(judge(i,N-i-1-1))
			{
				if(ans<0 || ans>N-i-1)
					ans=N-i-1;
			}

		if(i<=N-1-i)
		{
			if(judge(i+1,N-1-i))
				if(ans<0 || ans>i)
					ans=i;
			
			if(judge(i,N-i-1-1))
				if(ans<0 || ans>N-i-1)	
					ans=N-i-1;
		}

		for(i=0;N-1-i>=i;++i)
			if(s[i]!=s[N-1-i])
				break;

		if(i>N-1-i)
			ans=-10;

		if(ans<0)
			printf("No Solution\n");
		else
			printf("%d\n",ans+1);
	}
	
	return 0;
}
