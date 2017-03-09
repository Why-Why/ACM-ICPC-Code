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

int num[1000006];
int N;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cou;

	while(~scanf("%d",&N))
	{
		cou=0;
		for(int i=0;i<N;++i)
			scanf("%d",&num[i]);

		sort(num,num+N);

		for(int i=1;i<N;++i)
			if(num[i]==num[i-1])
			{
				++cou;
				if(cou>=(N+1)/2)
				{
					printf("%d\n",num[i]);
					break;
				}
			}
			else
				cou=1;
	}
	
	return 0;
}
