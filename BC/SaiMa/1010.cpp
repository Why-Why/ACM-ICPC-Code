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

int L[1010],R[1010],D[1010];
int ans[1010];
int N,Q;

int gcd(int a,int b)
{
	if(!a)
		return b;

	return gcd(b%a,a);
}

int gongbei(int a,int b)
{
	int temp=gcd(a,b);
	int ret=a;

	ret*=(b/temp);

	return ret;
}

inline void chuli(int L,int R,int D)
{
	for(int i=L;i<=R;++i)
		ans[i]=gongbei(ans[i],D);
}

inline bool judge(int L,int R,int D)
{
	int ret=ans[L];

	for(int i=L+1;i<=R;++i)
		ret=gcd(ret,ans[i]);

	return ret==D;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&Q);

		for(int i=1;i<=N;++i)
			ans[i]=1;

		for(int i=1;i<=Q;++i)
		{
			scanf("%d %d %d",&L[i],&R[i],&D[i]);

			chuli(L[i],R[i],D[i]);
		}

		bool ok=1;

		for(int i=1;i<=Q;++i)
			if(judge(L[i],R[i],D[i])==0)
			{
				ok=0;
				break;
			}

		if(ok)
		{
			printf("%d",ans[1]);
			for(int i=2;i<=N;++i)
				printf(" %d",ans[i]);
		}
		else
			printf("Stupid BrotherK!");

		printf("\n");
	}
	
	return 0;
}
