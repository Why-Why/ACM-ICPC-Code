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

long long B;
long long num[2000];
long long N;

long long getnum(long long ttt)
{
	if(ttt==0)
		return 0;

	long long ret=0;

	for(long long i=1;i<=B;++i)
		ret+=(ttt-1)/num[i]+1;

	return ret;
}

bool judge(long long Mid)
{
	long long ret=getnum(Mid);

	return ret<N;
}

long long getans()
{
	long long L=0,R=1000000000000000LL,M;

	while(R>L)
	{
		M=(L+R+1)/2;

		if(judge(M))
			L=M;
		else
			R=M-1;
	}

	return L;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	long long ans;
	long long timef;

	cin>>T;

	while(T--)
	{
		cin>>B>>N;

		for(long long i=1;i<=B;++i)
			cin>>num[i];

		timef=getans();

		N-=getnum(timef);

		for(long long i=1;i<=B;++i)
		{
			if(timef % ((long long)num[i])==0)
				--N;

			if(N==0)
			{
				ans=i;
				break;
			}
		}

		printf("Case #%d: ",cas++);
		cout<<ans<<endl;
	}
	
	return 0;
}
