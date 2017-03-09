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

struct state
{
	int n,id;

	bool operator < (const state &a) const
	{
		return n<a.n;
	}
};

state ans[100];

int chang(int x)
{
	int cou=0;
	int num[50];

	while(x)
	{
		num[cou++]=x%10;
		x/=10;
	}

	int ret=0;

	for(int i=0;i<cou;++i)
		ret+=ret*10+num[i];

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&a,&b);

		for(int i=a;i<=b;++i)
		{
			ans[i-a].n=chang(i);
			ans[i-a].id=i;
		}

		sort(ans,ans+b-a+1);

		printf("%d",ans[0].id);
		for(int i=1;i<b-a+1;++i)
			printf(" %d",ans[i].id);
		printf("\n");
	}

	return 0;
}
