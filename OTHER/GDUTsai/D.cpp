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

const int mod=1000000007;

long long fang[1000006];
long long ans[1000006];

void pre()
{
	fang[0]=1;
	fang[1]=2;
	fang[2]=4;
	ans[1]=0;
	ans[2]=1;

	for(int i=3;i<=1000000;++i)
	{
		ans[i]=((ans[i-1]+ans[i-2])%mod+fang[i-2]%mod)%mod;
		fang[i]=fang[i-1]*2;
		fang[i]%=mod;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int n;

	pre();

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",(int)ans[n]);
	}
	
	return 0;
}
