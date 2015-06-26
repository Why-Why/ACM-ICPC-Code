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

char s[1010];
int zans;
int N;

void getans1()
{
	int i;
	int ans=-1;
	bool ok;
	bool flag=0;

	for(i=N/2-1;i<N-1;++i)
	{
		ok=1;
		for(int j=i+1;j<N;++j)
			if(s[j]==s[2*i+1-j])
			{
				ok=0;
				break;
			}

		if(ok)
		{
			flag=1;
			ans=2*i-N+2;
			break;
		}
	}

	if(flag==0)
		ans=N;

	zans=min(zans,ans);
}

void getans2()
{
	int i,ans=-1;
	bool ok,flag=0;

	for(int i=N/2;i<N-1;++i)
	{
		ok=1;

		for(int j=i+1;j<N;++j)
			if(s[j]==s[2*i+1-j])
			{
				ok=0;
				break;
			}

		if(ok)
		{
			flag=1;
			ans=2*i-N+2;
			break;
		}
	}

	if(flag==0)
		ans=N;

	zans=min(zans,ans);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	char temp;
	
	scanf("%d",&T);

	while(T--)
	{
		zans=10e8;

		scanf("%d",&N);

		scanf("%s",s);

		if(N%2==0)
			getans1();
		else
			getans2();

		for(int i=0;i+i<N;++i)
		{
			temp=s[i];
			s[i]=s[N-i-1];
			s[N-i-1]=temp;
		}

		if(N%2==0)
			getans1();
		else
			getans2();

		printf("%d\n",zans);
	}
	
	return 0;
}
