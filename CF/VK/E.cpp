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

int N,K;
int num[5010];

int dfs(int n,int x,int rem,int mian)
{
	if(rem>K)
		return -1;

	if(mian>2)
		return -1;

	if(x==0)
	{
		if(rem>K)
			return -1;
		return rem;
	}

	while(num[n]>x && n>0)
		--n;

	if(n<=0)
		return -1;

	if(x%num[n]==0)
		return dfs(n-1,0,rem+x/num[n],mian+1);

	int temp;

	for(int i=x/num[n];i>=0;--i)
	{
		temp=dfs(n-1,x-i*num[n],rem+i,(i?mian+1:mian));

		if(temp>=0)
			return temp;
	}

	return -1;
}

void getans(int x)
{
	int temp=dfs(N,x,0,0);

	if(temp>K)
		temp=-1;

	printf("%d\n",temp);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int q,a;

	scanf("%d %d",&N,&K);

	for(int i=1;i<=N;++i)
		scanf("%d",&num[i]);

	sort(num+1,num+N+1);

	scanf("%d",&q);

	while(q--)
	{
		scanf("%d",&a);

		getans(a);
	}
	
	return 0;
}
