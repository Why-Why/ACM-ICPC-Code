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

int num[30004];
int N;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int base;
	int ans;

	while(~scanf("%d",&N))
	{
		ans=0;

		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		for(int i=1;i<=N;++i)
			if(num[i])
			{
				++ans;
				base=num[i];

				for(int j=i+1;j<=N;++j)
					if(num[j] &&num[j]<=base)
					{
						base=num[j];
						num[j]=0;
					}
			}

		printf("%d\n",ans);
	}
	
	return 0;
}
