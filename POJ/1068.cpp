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

int n;
int num[30];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int t;
	int a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&n);

		for(int i=1;i<=n;++i)
			scanf("%d",&num[i]);

		printf("1");

		for(int i=2;i<=n;++i)
		{
			a=0;
			t=0;

			for(int p=i-1;p>=1;--p)
			{
				t+=num[p+1]-num[p];

				if(t>0)
					break;

				++a;
				--t;
			}

			printf(" %d",a+1);
		}

		printf("\n");
	}
	
	return 0;
}
