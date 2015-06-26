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

int que[1000000];
int first,last;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;
	int N,a,b;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		first=last=0;

		while(N--)
		{
			scanf("%d",&a);

			if(a==1)
			{
				scanf("%d",&b);
				que[last++]=b;
			}
			else if(a==2)
			{
				if(last-first)
					++first;
			}
			else
			{
				scanf("%d",&b);

				if(last-first<b)
					printf("na li you zhe me duo ren\n");
				else
					printf("%d\n",que[first-1+b]);
			}
		}
	}

	return 0;
}
