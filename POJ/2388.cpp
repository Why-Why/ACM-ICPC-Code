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

int N;
int num[10004];

int getans(int L,int R,int k)
{
	int mid=num[L];
	int tl=L,tr=R;

	if(L==R)
		return num[L];

	while(L<R)
	{
		while(L<R && num[R]>=mid)
			--R;

		num[L]=num[R];

		while(L<R && num[L]<=mid)
			++L;

		num[R]=num[L];
	}

	num[L]=mid;

	if(L-tl+1>=k)
		return getans(tl,L,k);
	else
		return getans(L+1,tr,k-(L-tl+1));
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		printf("%d\n",getans(1,N,(N+1)/2));
	}
	
	return 0;
}
