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

int N,M;
int x[100005],y[100005];

bool judge(int a,int b)
{
	if(abs(y[b]-y[a])>abs(x[b]-x[a]))
		return 1;

	return 0;
}

int getans(int a,int b)
{
	return (x[b]-x[a]+y[b]+y[a])/2;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);

	for(int i=1;i<=M;++i)
		scanf("%d %d",&x[i],&y[i]);

	int maxn=0;
	bool ok=1;

	for(int i=1;i<M;++i)
	{
		if(judge(i,i+1))
		{
			ok=0;
			break;
		}

		maxn=max(maxn,getans(i,i+1));
	}

	maxn=max(maxn,N-x[M]+y[M]);
	maxn=max(maxn,x[1]+y[1]-1);

	if(ok)
		printf("%d\n",maxn);
	else
		printf("IMPOSSIBLE\n");
	
	return 0;
}
