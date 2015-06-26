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
unsigned int L1,R1,a,b,c,d;

unsigned int L[10000007],R[10000007];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	unsigned int maxL=-1,minR=4294967295;
	int T;
	bool ok;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %u %u %u %u %u %u",&N,&L1,&R1,&a,&b,&c,&d);
		
		maxL=min(L1,R1);
		minR=max(L1,R1);
		ok=0;

		if(N<3)
		{
			printf("NO\n");
			continue;
		}

		L[1]=L1;
		R[1]=R1;

		for(int i=2;i<=N;++i)
		{
			L[i]=L[i-1]*a+b;
			R[i]=R[i-1]*c+d;
		}

		for(int i=1;i<=N;++i)
		{
			if(L[i]>R[i])
				swap(L[i],R[i]);

			maxL=max(maxL,L[i]);
			minR=min(minR,R[i]);
		}

		if(maxL>minR)
		{
			for(int i=1;i<=N;++i)
			{
				if(L[i]>R[i])
					swap(L[i],R[i]);

				if(L[i]>minR && R[i]<maxL)
				{
					ok=1;
					break;
				}
			}
		}

		if(ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
